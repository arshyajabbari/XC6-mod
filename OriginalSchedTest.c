#include "types.h"
#include "stat.h"
#include "user.h"

struct timeVariables{
  int creationTime;
  int terminationTime;
  int sleepingTime;
  int runningTime;
  int readyTime;
};

int main(void){

  int CBT[10];
  int TT[10];
  int WT[10];
  int averageCBT=0;
  int averageTT=0;
  int averageWT=0;
  int pid;
  changePolicy(1);
  for(int i=0;i<10;i++)
{
  	pid=fork();
  	if(pid == 0)
{
  		for(int j=1 ; j<1001;j++)
			printf(0,"[%d]: [%d]\n",getpid(),j);
  exit();
}
}
  printf(0,"-----------------------------------------------------------------");
  struct timeVariables *time = malloc(sizeof(struct timeVariables));
  for(int i=0;i<10;i++)
{
	//printf(0,"calculating");
	waitForChild(time);
	//printf(0,"calculating");
	CBT[i]=time->runningTime;
	TT[i]=time->terminationTime - time->creationTime; 
	WT[i]=time->sleepingTime;
	averageCBT+=CBT[i];
	averageTT+=TT[i];
	averageWT+=WT[i];
}
  averageCBT = averageCBT/10;
  averageTT = averageTT/10;
  averageWT = averageWT/10;
  for(int i=0;i<10;i++)
	printf(0,"Child num[%d] --> CBT= %d,TT= %d, WT=%d \n",(i+1),CBT[i],TT[i],WT[i]);
  printf(1,"Average CBT= %d, Average TT= %d, Average WT= %d\n",averageCBT,averageTT,averageWT);
  exit();
}
