#include <stdio.h>
int find_max(int array[], int length){
	int current_max = array[0];
	int i = 0;
	for (i = 1; i < length; i++){
		if (array[i] > current_max){
			current_max = array[i];
		}
}
return current_max;
}

int main(){
	int monkey[10]={19, 10, 8, 17, 24, 14, 1, 2, 27, 11};
int q = find_max(monkey, 10);	
printf("%i\n",q);
}