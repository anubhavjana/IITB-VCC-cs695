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
MODULE_DESCRIPTION("Module information regarding VMA spaces and physical address size of a process. LKM");
static long pid=1;
module_param(pid,long,S_IRUSR);
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

        
        unsigned long total_rss = get_mm_rss(mm);
        unsigned long page_size = 1 << (PAGE_SHIFT-10); //Get page size

        printk(KERN_INFO "PAGE SIZE  IN KB = %lu\n", page_size);
        printk(KERN_INFO "Total number of VMAs = %d\n",mm->total_vm*page_size); //No of pages * each page size
        printk(KERN_INFO "Total RSS = %lu\n", total_rss*page_size);
        
    }
}
    
        
int ps_init(void)
{
    printk(KERN_INFO "Hello, Welcome to LKM\n");
    process_info();
    printk(KERN_INFO "Virtual memory info kernel module loaded\n");
    return 0;
}


void ps_exit(void)
{
    printk("Virtual memory module removed,Bye !!\n");
    
}

module_init(ps_init);
module_exit(ps_exit);

