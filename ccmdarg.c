#include <stdio.h>

int main(int argc, char *argv[]){
	if (argc==3){
	printf("The argument supplied is %s and %s\n", argv[1], argv[2]);		
	}
	else{puts("Not appropriate number of arguments.");
}
return 0;
}