#include "types.h"
#include "stat.h"
#include "user.h"



int main(int argc, char *argv[])
{
	printf(1, "Waitpid Test\n");
	printf(1, "Creating 5 proccesses and exiting in order\n\n");

	int pid[5];

	int child_status;
	int i;
 
	for (i = 0; i < 5; i++) {
		if((pid[i] = fork()) == 0) {
			exit(i);
		}
	}
	for (i = 0; i < 5; i++) {
		
		int childpid = waitpid(pid[i], &child_status, 0);
		
		if (child_status) {
			printf(1, "Child %d terminated successfully\n", childpid);
		}
	}
	exit(0);
}
