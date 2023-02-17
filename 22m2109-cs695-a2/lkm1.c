#include<linux/module.h> //Needed by all modules
#include<linux/init.h>
#include<linux/kernel.h> //KERN_INFO
#include<linux/sched/signal.h> //for_aech_process

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anubhav Jana");
MODULE_DESCRIPTION("Module to list all processes");


void process_info(void)
{

    
    struct task_struct *task;
    for_each_process(task)
    {
        if(task->__state>=0)
        
        printk(KERN_INFO "PID: %d | PROCESS: %s | STATE: %ld\n", task->pid,task->comm, task->__state);
    }
    
}

int ps_init(void)
{
    printk(KERN_INFO "Hello, Welcome to LKM\n");
    process_info();
    printk(KERN_INFO "Listing process kernel module loaded\n");
    return 0;
}


void ps_exit(void)
{
    printk("PS module removed,Bye !!\n");
    
}

module_init(ps_init);
module_exit(ps_exit);

