#include<linux/module.h> //Needed by all modules
#include<linux/init.h>
#include<linux/kernel.h> //KERN_INFO
#include<linux/sched/signal.h> //for_each_process, task_struct
#include<linux/mm.h> //for mm_struct

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anubhav Jana");
MODULE_DESCRIPTION("Module to fetch current kernel stack pointer of process pid 1 LKM");


void process_info(void)
{

    
    struct task_struct *task;
    struct thread_struct th;

    
    for_each_process(task)
    {
       
        if(task->pid == 1)
        {
            th=task->thread;
            printk(KERN_INFO "PID: %d | PROCESS: %s | STATE: %ld | STACK TOP FROM TASK->STACK: %lx | CURRENT STACK POINTER THREAD.SP %lx\n", task->pid,task->comm,task->__state,task->stack,th.sp);
        }   
    }
    
    
}

int ps_init(void)
{
    printk(KERN_INFO "Hello, Welcome to  LKM\n");
    process_info();
    printk(KERN_INFO "SP module loaded\n");
    return 0;
}


void ps_exit(void)
{
    printk("Kernel stack pointer module removed,Bye !!\n");
    
}

module_init(ps_init);
module_exit(ps_exit);

