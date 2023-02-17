#include<stdio.h>
#include<string.h>

char *map[] ={"/","/square","/cube","/helloworld","/pingpong","/arithmetic/prime","/arithmetic/fibonacci"};

int get_index(const char* url)
{
    int i;
    
    for(i=0;map[i]!=0;i++)
    {
        if(strcmp(url,map[i])==0)
        return i;
    }
    return -1;
}