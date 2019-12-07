#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	int i;
	for(i=0 ; i<5 ; i++){
		//acquire(&ptable.lock);
		if(fork() == 0 ){
			//int pid=getpid();
			int ppid=getppid();
			int children = getChildren(ppid);
			printf(i,"%d",children);
	//release(&ptable.lock);
	exit();
}
}
	for(i=0;i<5;i++)
	wait();
	wait();	
	exit();
}


