#include<stdio.h>
#include<string.h>

const char* home(const char* query_string)
{
    return "Hello World !";
}

const char* square(const char* query_string)
{
  
    if(query_string==NULL)
    {
        return "1";
    }
    
    char *number;
    char* token = strtok(query_string,"=");
    while(token!=NULL)
    {
        
        number = token;
        token = strtok(NULL,"=");
    }
    int numb = atoi(number);
    int sqr = numb * numb;
    sprintf(number,"%d",sqr);
    return number;
}

const char* cube(const char* query_string)
{
  
    if(query_string==NULL)
    {
        return "1";
    }
    
    char *number;
    char* token = strtok(query_string,"=");
    while(token!=NULL)
    {
        
        number = token;
        token = strtok(NULL,"=");
    }
    int numb = atoi(number);
    int cub = numb * numb * numb;
    sprintf(number,"%d",cub);
    return number;
}

const char* helloworld(const char* query_string)
{
  
    if(query_string==NULL)
    {
        return "Hello";
    }
    
    char *name;
    char* token = strtok(query_string,"=");
    while(token!=NULL)
    {
        
        name = token;
        token = strtok(NULL,"=");
    }

    char* prefix="Hello,";
    char* result;
    asprintf(&result,"%s%s",prefix,name);
    return result;
}

const char* pingpong(const char* query_string)
{
  
    if(query_string==NULL)
    {
        return "PingPong";
    }
    
    char *name;
    char* token = strtok(query_string,"=");
    while(token!=NULL)
    {
        
        name = token;
        token = strtok(NULL,"=");
    }

    
    return name;
}

const char* prime(const char* query_string)
{
  
    if(query_string==NULL)
    {
        return "False";
    }
    
    char *number;
    char* token = strtok(query_string,"=");
    while(token!=NULL)
    {
        
        number = token;
        token = strtok(NULL,"=");
    }
    int n = atoi(number);
    int flag = 0;
    if(n==0 || n==1)
    flag=1;

    int i;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    return "True";
    else
    return "False";
}

const char* fibonacci(const char* query_string)
{
  
    if(query_string==NULL)
    {
        return "1";
    }
    
    char *number;
    char* token = strtok(query_string,"=");
    while(token!=NULL)
    {
        
        number = token;
        token = strtok(NULL,"=");
    }
    int n = atoi(number);
    int fib[n+2];

    int i;
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<=n;i++)
    {
        fib[i]=fib[i-1] + fib[i-2];
    }
    sprintf(number,"%d",fib[n-1]);
    return number;
}