#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
	wait();
	wait();
	wait();
	int sys_num=3;
	int count=getCount(sys_num);

	printf(0,"system call count is:%d\n",count);
	exit();
}
