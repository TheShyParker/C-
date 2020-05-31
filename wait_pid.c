#include<sys/types.h>
#include<unistd.h>
#include <stdio.h>
#include<sys/wait.h>

int var=10;
int main(int argc,char *argv[])
{
    pid_t pid;
    pid_t pid_bk;
    int i;
    int s;
    int pid_num;
    int num;
    pid=fork();
    if (pid<0)
    {
        perror("fork");
        return 0;
    }else if(pid==0)
    {
        //获得子进程的进程号
        pid_num=getpid();
        printf("pid=%d\n",pid_num);
        for(i=0;i<5;i++)
        {
            printf("这里是子进程\n");
            sleep(1);
        }
        //测试wait，让子进程返回一个5
        return 5;
        
    }else
    {
        pid_bk=waitpid(pid,&s,0);
        //测试WIFEXITED和WEXITSTATUS两个宏
        if (WIFEXITED(s) != 0)
        {
            num=WEXITSTATUS(s);
            printf("子线程的返回值为%d\n",num);
        }
        
        printf("pid_bk=%d\n",pid_bk);
        while(1)
        {
            printf("现在执行的为主进程\n");
            sleep(1);
        }
    }
    return 0;

}

