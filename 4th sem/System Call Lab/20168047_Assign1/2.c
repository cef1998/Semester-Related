#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int n=5;

int fn(char *x) {
    printf("I am a %s.  My pid is:%d  my parent pid is: %d \n", x, getpid(), getppid() );
    return 1;
}

int func(int n) 
{
    if (n == 0)
    { 
        return 0;
    }
    int pid = fork(); 
    if (pid == -1) {
        exit(0);
    }
    if (pid==0) { 
        fn("child");
        n = n-1;
        func(n);
        exit(0);
    }
    else {
       wait(NULL);
    } 
    return 0;   
}


int main()
{
    func(n); 
    return 0;
}
