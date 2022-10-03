#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#define   MAX_COUNT  200

void  ChildProcess1(void);  
void  ChildProcess2(void);               /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;

     pid = fork();
     if (pid == 0) {
          ChildProcess1();
          ChildProcess2();
     }
     else 
          ParentProcess();
}

void  ChildProcess1(void)
{
      int   i;
      time_t t;
      srand((unsigned) time(&t));
      int child_count = rand() % 30;
      pid_t pid = getpid();
      for (i = 1; i <= child_count; i++) {
          printf("Child Pid:  %d is going to sleep!\n", pid);
          sleep(2);//rand() % 10
          pid_t ppid = getppid();
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?", pid, ppid);
      }
      exit(0);
      
}
void  ChildProcess2(void)
{
      time_t t;
      int i;
      srand((unsigned) time(&t));
      int child_count = rand() % 30;
      pid_t pid = getpid();
      for (i = 1; i <= child_count; i++) {
          printf("Child Pid:  %d is going to sleep!\n", pid);
          sleep(rand() % 10);
          pid_t ppid = getppid();
      printf("Child Pid: %d is awake!\nWhere is my Parent: %d?", pid, ppid);
      }
      exit(0);
      
}


void  ParentProcess(void)
{
    int i;
    pid_t wait(int *status);
    pid_t pid = getpid();
    pid_t ppid = getppid();
    // wait(&status);
    for (i = 1; i <= MAX_COUNT; i++)
          printf("Child Pid: %d has completed\n",pid );
    printf("*** Parent is done ***\n");
}