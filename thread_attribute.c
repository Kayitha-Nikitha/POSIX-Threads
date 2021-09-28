#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Compile :
gcc thread_attribute.c -lpthread -o  thread_attribute
	"thread_attribute"->Object file
*/

void *my_thread(void *p){
	printf("Empty\n");
}

int main(){

int ret, s, detach_state;
pthread_t tid;  	// thread id
size_t stacksize;	// stacksize

pthread_attr_t attr;	// pthread attribute instance (attr)
pthread_attr_init(&attr); // initialising attribute (attrs)

pthread_attr_getstacksize(&attr,&stacksize);   // getting stack size 
printf("Current stack size %d\n",stacksize);    // printing stack size

pthread_attr_setstacksize(&attr,10000000);    // setting new stack size (should be greater than the original one)	

pthread_attr_getstacksize(&attr, &stacksize);  // getting the modified/updated stacksize
printf("New stack size %d\n",stacksize);	    // printing the updated stack size

s = pthread_attr_setdetachstate(&attr, 1); // 1=detach, 0=join, default=0
s = pthread_attr_getdetachstate(&attr, &detach_state);  // getting detachstate

ret = pthread_create(&tid, &attr, &my_thread, NULL);    // thread creation
printf("im in main func\n");
pthread_exit(NULL);    // exitting thread

return 0;
}