#include <stdio.h>	 // input/output lib
#include <stdlib.h>
#include <pthread.h>    // User Space Thread
#include <unistd.h>     // used for sleep function

/*
Compile :
gcc struct_threads.c -lpthread -o struct_threads 
	"struct_threads"-> Object file
*/

struct person{
	int age;
	char gender;
}*p;

void *my_thread(void *ptr){

	p = (struct person *)ptr;
	printf("Entered in thread function, age and gender = %d and %c\n", p->age, p->gender);
	pthread_exit(NULL); // returning NULL to main function (from where it got invoked)
}

int main(){	
	pthread_t tid;
	int ret;
	struct person P1 = { 22, 'F'};  //creating structure instance
	
	/*int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);*/
	ret = pthread_create( &tid, NULL, &my_thread, &P1);  //thread creation
	
	if (ret!=0){
		printf("Thread is not created\n");
		return -1;
	}
	
	printf("Entered Main function\n");
	pthread_join(tid,NULL);
	printf("Back to Main function\n");
	
	return 0;
}