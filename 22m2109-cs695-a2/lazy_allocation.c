
//This program is to verify and validate lazy allocation in our module so implemented
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int pid = getpid();
    char command[100];
    int *p;
    int i;
    
    // Load and unload 
    
    sprintf(command,"sudo insmod lkm5.ko pid=%d",pid);
    system(command);
    sprintf(command,"sudo rmmod lkm5");
    system(command);

    //Malloc - reserving virtual address space range in virtual space - Not allocated physical page yet

    
    p = (int *)malloc(sizeof(int)*10000);

    // Load and unload 

    sprintf(command,"sudo insmod lkm5.ko pid=%d",pid);
    system(command);
    sprintf(command,"sudo rmmod lkm5");
    system(command);

    //Access - Now should get physical pages when accessed

    
    for(i=0;i<10000;i++)
    {
        p[i]=i+1;
        printf("Value at  index %d = %d\n",i,p[i]);
    }

    

    // Load and unload and now check RSS

    sprintf(command,"sudo insmod lkm5.ko pid=%d",pid);
    system(command);
    sprintf(command,"sudo rmmod lkm5");
    system(command);

    return 0;
    
}