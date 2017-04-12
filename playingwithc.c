#include <stdio.h>

int main(){
	int i = 0;
	while(i<10){
//remember, you can't print an int in C as is...
		printf("%d\n",i);
		i++;
	}

	/* Remember that a variable
	can have only 1 name in C. SIGH */
	int x = 10;
	while (x>0){
		printf("%d\n",x);
		x--;
	}
}