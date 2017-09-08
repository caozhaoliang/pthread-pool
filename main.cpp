#include <iostream>
#include <exception>
#include "pthread_pool.h"

using namespace std;


void* mypro(void* arg) {
	int* num = (int*)arg;
	printf("process id is %d\n and *arg is:%d\n",getpid(),*num);
	while(1){
		printf("thread is running num is: %d\n",*num);
		sleep(1);
		// if(*num==3) {
		// 	int * ptr=NULL;
		// 	*ptr = 0;
		// }
		
	}

	return NULL;
}

int main()
{
	int i;
	pool_init(5);
	int *workingnum=(int*)malloc(sizeof(int)*6);
	for(i=0;i<6;i++){
		workingnum[i] = i;
		pool_add_worker(mypro,&workingnum[i]);
	}
	printf("all of pthread is running\n");
	sleep(10);
	pool_destory();
	free(workingnum);
	return 0;

}