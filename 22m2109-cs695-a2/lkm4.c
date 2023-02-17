#include<linux/module.h> //Needed by all modules
#include<linux/init.h>
#include<linux/kernel.h> //KERN_INFO
#include<linux/sched/signal.h> //for_each_process, task_struct
#include<linux/mm.h> //for mm_struct
#include<linux/moduleparam.h>
#include<linux/pgtable.h>
#include<linux/pid.h>
#include<linux/mm_types.h>
#include<linux/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anubhav Jana");
MODULE_DESCRIPTION("Module information regarding V.A to P.A. mapping LKM");
static long pid=1;
module_param(pid,long,S_IRUSR);
static long address = 0x000000000000;
module_param(address,long,S_IRUSR);
void process_info(void)
{

    struct task_struct *task;
    task = pid_task(find_get_pid(pid),PIDTYPE_PID);
    struct mm_struct *mm;
    struct vm_area_struct *vma;
    printk(KERN_INFO "PID: %d | PROCESS: %s \n", task->pid,task->comm);
    mm = task->mm;
    if(mm==NULL)
    {
        printk(KERN_INFO "PID: %d is not assigned a memory\n", task->pid);
    }
    if(mm!=NULL)
    vma = task->mm->mmap;
    if(mm!=NULL && vma!=NULL)
    {
        while(vma)
        {
                
            printk(KERN_INFO "VM START = %lx VM END = %lx\n",vma->vm_start,vma->vm_end);
            vma = vma->vm_next;
            
        }

        printk(KERN_INFO "Number of VMAs = %d\n", mm->map_count);
        pgd_t *pgd = pgd_offset(mm, (unsigned long)address);
        if(!pgd_none(*pgd) && !pgd_bad(*pgd))
        {
            printk(KERN_INFO "VALID PGD ADDRESS = %lx\n",pgd);
            
            p4d_t *p4d = p4d_offset(pgd, address);
            if(!p4d_none(*p4d) && !p4d_bad(*p4d))
            {
                printk(KERN_INFO "VALID P4D ADDRESS = %lx\n",p4d);
                pud_t *pud = pud_offset(p4d, address);
                if (!pud_none(*pud) && !pud_bad(*pud))
                {
                    printk(KERN_INFO "VALID PUD ADDRESS = %lx\n",pud);
                    pmd_t *pmd = pmd_offset(pud, address);
                    if(!pmd_none(*pmd) && !pmd_bad(*pmd))
                    {
                        printk(KERN_INFO "VALID PMD ADDRESS = %lx\n",pmd);
                        pte_t *pte = pte_offset_map(pmd, address);
                        if(!pte_none(*pte))
                        {
                            // now we get a pointer pointing to a pte entry!
                            printk(KERN_INFO "VALID PTE ADDRESS = %lx\n",pte);
                            struct page *pg = pte_page(*pte);
                            unsigned long phys = page_to_phys(pg);
                            printk(KERN_INFO "The virtual address %lx maps to physical address %lx\n",address,phys);


                            
                        }
                        pte_unmap(pte);
                    }
                }
            }
        }
        
    }
}
    
        
int ps_init(void)
{
    printk(KERN_INFO "Hello, Welcome to LKM\n");
    process_info();
    printk(KERN_INFO "Virtual memory to physical memory info kernel module loaded\n");
    return 0;
}


void ps_exit(void)
{
    printk("Virtual memory module to physical memory info removed,Bye !!\n");
    
}

module_init(ps_init);
module_exit(ps_exit);

