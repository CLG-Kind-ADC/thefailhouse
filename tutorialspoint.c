#include <stdio.h>
#include <float.h>

int i, j, k;
char c, ch;
float f, salary;
double d;

// function declaration
int func();

int main(){
	   printf("Storage size for float : %d \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );
   printf("Maximum float positive value: %E\n", FLT_MAX );
   printf("Precision value: %d\n", FLT_DIG );
   i=10;
   j=11;
   k=290;

// function call
   int x = func();

   printf("%d",i+j);
   printf("this is an integer list: %d\n%d\n%d\n",i,j,k);

  // return 0;
}

//function definition: note it is after function call
// a la forward declaration
int func(){
	return 0;
}