/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int sigCallFalseBool = 1; 

void handler(int signum) //signal handler
{
  printf("Hello World!\n");
  alarm(3);
  sigCallFalseBool = 0;
}
//use of times jumps to a handler function that keeps track of how many times the tracker has been calle


int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM

  alarm(3); 
  while(sigCallFalseBool){

    if(sigCallFalseBool == 0){
      printf("Turing was right!\n");
    }
    sigCallFalseBool = 1; 
  }; //busy wait for signal to be delivered


  return 0; //never reached
}