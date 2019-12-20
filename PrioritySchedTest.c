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

  int CBT[5][5];
  int TT[5][5];
  int WT[5][5];
  int averageCBT[5];
  int averageTT[5];
  int averageWT[5];  
  int allaverageCBT=0;
  int allaverageTT=0;
  int allaverageWT=0;

  for(int i=0;i<5;i++){
  averageCBT[i]=0;
  averageTT[i]=0;
  averageWT[i]=0;
}

  int pid;
  changePolicy(2);
  for(int i=0;i<25;i++)
{
  	pid=fork();
  	if(pid == 0)
{
		changePriority( 5 - (getpid()/5) );
  		for(int j=1 ; j<501;j++)
			printf(0,"[%d]: [%d]\n",getpid(),j);
  exit();
}
}
  printf(0,"-----------------------------------------------------------------");
  struct timeVariables *time = malloc(sizeof(struct timeVariables));
  for(int i=0;i<25;i++)
{
	//printf(0,"calculating");
	waitForChild(time);
	//printf(0,"calculating");
	CBT[i/5][i%5]=time->runningTime;
	TT[i/5][i%5]=time->terminationTime - time->creationTime; 
	WT[i/5][i%5]=time->sleepingTime;
	allaverageCBT+=CBT[i/5][i%5];
	allaverageTT+=TT[i/5][i%5];
	allaverageWT+=WT[i/5][i%5];
	averageCBT[i/5]+= CBT[i/5][i%5];
 	averageTT[i/5]+=TT[i/5][i%5];
	averageWT[i/5]+=WT[i/5][i%5];
}
  allaverageCBT = allaverageCBT/25;
  allaverageTT = allaverageTT/25;
  allaverageWT = allaverageWT/25;

  for(int i=0;i<5;i++){
	averageCBT[i]=averageCBT[i]/5;
 	averageTT[i]=averageTT[i]/5;
	averageWT[i]=averageWT[i]/5;
}	
  for(int i=0;i<25;i++){
	printf(0,"-----------------------------------------------------------------\n/");
	printf(0,"Child num[%d] --> CBT= %d,TT= %d, WT=%d \n",(i+1),CBT[i/5][i%5],TT[i/5][i%5],WT[i/5][i%5]);
printf(0,"-----------------------------------------------------------------\n/");
}
  for(int i=0;i<5;i++){
	printf(0,"-----------------------------------------------------------------\n/");
	printf(0,"Group With [%d] Priority --> AverageCBT= %d, AverageTT= %d, AverageWT= %d\n",(i+1),averageCBT[i],averageTT[i],averageWT[i]);
	printf(0,"-----------------------------------------------------------------\n/");
}

  printf(1,"Average CBT= %d, Average TT= %d, Average WT= %d\n",allaverageCBT,allaverageTT,allaverageWT);
  exit();
}
