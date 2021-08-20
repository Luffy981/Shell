#include <unistd.h>
#include <stdio.h>
int var = 22;
int main(void)
{
	pid_t ron;
	printf("proceso comienza PID = %d\n",getpid());
	ron = fork();
	printf("proceso que se ejecuta PID = %d\n",getpid());
	if(ron>0)
	{
		var = 44;
	}
	else if(ron == 0)
	{
		var = 33;
	}
	while(1)
	{
		sleep(3);
		printf("proceso PID = %d , VAR = %d ejecutandose \n", getpid(),var);
	}
	return(0);
}
