#include<linux/module.h> //Needed by all modules
#include<linux/init.h>
#include<linux/kernel.h> //KERN_INFO
#include<linux/sched/signal.h> //for_each_process, task_struct
#include<linux/mm.h> //for mm_struct

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anubhav Jana");
MODULE_DESCRIPTION("Module to get in use heap memory LKM");


void process_info(void)
{

    
    struct task_struct *task;
    struct mm_struct *mm;
    int max = 0x0000;
    int pid_max_heap;
    for_each_process(task)
    {
        mm = task->mm;
        if(task->__state>=0 && mm!=NULL)
        {
            if(mm->brk-mm->start_brk > max)
            {
                max = mm->brk-mm->start_brk;
                pid_max_heap = task->pid;
            }
        
        printk(KERN_INFO "PID: %d | PROCESS: %s | STATE: %ld | HEAP: %X\n", task->pid,task->comm,task->__state,(mm->brk-mm->start_brk));
        }   
    }
    printk(KERN_INFO "MAX HEAP USAGE BY PID = %d --> AMOUNT USED = %X\n",pid_max_heap,max);
    
}

int ps_init(void)
{
    printk(KERN_INFO "Hello, Welcome to LKM\n");
    process_info();
    printk(KERN_INFO "List Heap memory-in-use by processes kernel module loaded\n");
    return 0;
}


void ps_exit(void)
{
    printk("Heap-in-use module removed,Bye !!\n");
    
}

module_init(ps_init);
module_exit(ps_exit);

