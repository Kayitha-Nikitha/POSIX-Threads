#include <stdio.h>	    // input/output lib
#include <pthread.h>    // User Space Thread
#include <unistd.h>      // used for sleep function

/*
Compile :
gcc threads2_detach.c -lpthread -o detach 
	"detach"->Object file
*/

void *my_thread(void *ptr){

	pthread_detach(pthread_self());      // detaching the thread with itself
	printf("Enter in thread function\n");
	pthread_exit(NULL);      // returning NULL to main func where it got invoked.
}

int main(){
	
	pthread_t tid;
	int ret,var;
	void *rval;
	
	/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/        
	ret = pthread_create( &tid, NULL, &my_thread, NULL);
	if (ret!=0){
		printf("Thread is not created\n");
		return -1;
	}
	
	printf("Entered Main function\n");
	printf("Back to main function\n");
	pthread_exit(NULL);
	
	return 0;
}