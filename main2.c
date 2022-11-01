#include  <stdio.h>
#include  <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define   MAX_COUNT  3

void  ChildProcess(void);               
void  ParentProcess(void);              
void  ChildProcess2(void);     

void main(void){

    pid_t  pid;
    pid_t  pid2;


    pid = fork(); // first child process

    if(pid != 0){
       pid2 = fork(); // second child processes
    }
  
    int status;

    int lower = 1;
    int upper = 30;
    int loop_iterations;
    loop_iterations = rand() % 30;
    int sleep_timer;
    sleep_timer = rand() % 10;

    pid_t current_pid;
    pid_t parent_pid;
    current_pid = getpid();
    parent_pid = getppid();

    int i;
    
    if (pid != 0 && pid2 != 0){
      waitpid(pid, &status, 0);     
      printf("Child Pid: %d has completed\n", pid);
      waitpid(pid2, &status, 0);     
      printf("Child Pid: %d has completed\n", pid2);
    }
    else{
    for (i = 0; i < loop_iterations; i++) {
        printf("Child process: %d is going to sleep\n", current_pid);
        sleep(sleep_timer);
        printf("Child process: %d is awake. Where is my parent: %d \n",current_pid, parent_pid);
      }
      exit(0) ;
    }
}

