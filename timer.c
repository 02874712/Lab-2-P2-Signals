/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

/***

COPY YOUR SIGNAL.C INTO THIS FILE

UPDATE YOUR MAKEFILE


***/

int sigCallFalseBool = 1; 
int totalAlarm = 0; 
int totalSeconds = 0;
clock_t start, end; 

void handler(int signum) //signal handler
{
  if(signum == SIGALRM){
    printf("Hello World!\n");
    alarm(3);
    totalAlarm++;
    sigCallFalseBool = 0;    
    }

  else if(signum == SIGINT){
    end = clock() - start; 
  
    printf("\nProgram Finishing...\n");
    printf("Total Alarms: %d\n", totalAlarm);

    double time_taken = ((double)end)/CLOCKS_PER_SEC;
    printf("Seconds: %f\n", time_taken);

    exit(0);
  }

}
//use of times jumps to a handler function that keeps track of how many times the tracker has been calle

int main(int argc, char * argv[]){

  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, handler);

  alarm(3);
  start = clock(); 
  totalAlarm++; 

  while(sigCallFalseBool){

    if(sigCallFalseBool == 0){
      printf("Turing was right!\n");
    }
    
    sigCallFalseBool = 1; 

  }; //busy wait for signal to be delivered


  return 0; //never reached
}