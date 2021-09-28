#include <stdio.h>	     // input/output lib
#include <pthread.h>    // User Space Thread
#include <unistd.h>      // used for sleep function

/*
Leading to Race Condition->  should use any synchronization techniques.
Compilation:
gcc thread1.c -lpthread
*/

void *my_thread(void *ptr){
	int *n = (int *)ptr;
	printf("Enter in thread function and val = %d\n",*n);
	//pthread_exit(NULL); // returning NULL to main func where it got invoked.
	return (void *)10;
}

int main(){
	pthread_t tid;
	int ret,var;
	void *rval;
	/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
        
	printf("Enter the limit : ");
        	scanf("%d",&var);
        
	//ret = pthread_create(&tid,NULL,&my_thread,NULL);
	ret = pthread_create(&tid,NULL,&my_thread,&var);
	if (ret!=0){
		printf("Thread in not created\n");
		return -1;
	}
	//sleep(1);
	
	printf("Im in main func\n");
	//pthread_join(tid,NULL);
	pthread_join(tid,rval);
	printf("Back to main function %d \n",*(int *)rval);	
	
	return 0;
}