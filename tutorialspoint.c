#include <stdio.h>
#include <float.h>

static int i=10, j=11, k=290;
char c, ch;
float f, salary;
double d;

// function declaration
int func();

int main(){
	   printf("Storage size for float : %d \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );//same thing as with %d
   printf("Maximum float positive value: %E\n", FLT_MAX );//same thing as with %d
   printf("Precision value: %d\n", FLT_DIG );
   /*i=10;
   j=11;
   k=290;*/

// function call
   int x = func();

   printf("%d",i+j); putchar('\n');
// above does not work if you do two printfs instead of the putchar
// Don't know why.
   printf("this is an integer list: %d\n%d\n%d\n",i,j,k);

  // return 0;
}

//function definition: note it is after function call
// a la forward declaration
int func(){
	return 0;
}