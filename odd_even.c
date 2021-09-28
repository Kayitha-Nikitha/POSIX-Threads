#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Leading to Race Condition-> Should use synchronization techniques.
Compilation :
gcc odd_even.c -lpthread -o oddeven 
	"oddeven"->Object file  
*/

int value,data=0;

void *even_num(void *ptr){
	
	do{
		if(data%2==0){
			printf("Even : %d\n",data);
			data++;
		}
	}
	while(data<value);
}

void *odd_num(void *ptr1){
	
	do{
		if(data%2!=0){
			printf("Odd : %d\n",data);
			data++;
		}
	}
	while(data<value);
}
int main(){

	printf("Enter the Max value : ");
	scanf("%d",&value);
	
	pthread_t tid[2]; // creating array of Thread Id
	
	//creating two threads
	pthread_create(&tid[0],NULL,&even_num,NULL);
	pthread_create(&tid[1],NULL,&odd_num,NULL);
	
	//joining the threads
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	return 0;
}