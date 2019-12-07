#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	int i;
	int l=1;
	for(i=0 ; i<5 ; i++){
		if(fork() == 0 ){
			if(l==1){
				l=0;
				int pid=getpid();
				int ppid=getppid();
				int children = getChildren(ppid);
				printf(0,"[%d] pid:[%d]  ppid:[%d]  %d\n",i,pid,ppid,children);
				l=1;
wait();
				exit();
}
} else wait();
}
	for(i=0;i<5;i++){
	wait();
	wait();	
	exit();
}
}


