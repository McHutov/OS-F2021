#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(){
	char command[100];
	while(strcmp(command, "quit") != 0){
	    printf(">>");
		scanf("%s",command);
		system(command);
	}
	return 0;
}

