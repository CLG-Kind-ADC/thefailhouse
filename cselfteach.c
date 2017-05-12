//#include <stdio.h>
#include "csupport.c"
#include <float.h>

int i=10, j=11, k=290;
int z = 19;
int *p = &z;
char c, ch;

int count = 5;

float f, salary;
double d;

// function declaration
int func();
extern void write_extern(void);

int main(){
	   printf("Storage size for float : %d \n", sizeof(float));
   printf("Minimum float positive value: %E\n", FLT_MIN );//same thing as with %d
   printf("Maximum float positive value: %E\n", FLT_MAX );//same thing as with %d
   printf("Precision value: %d\n", FLT_DIG );
//   i=10;
//   j=11;
//   k=290;

   printf("%d\n",*p); 

   //count = 5;
   write_extern();


// function call
   int x = func();

   printf("%d",i+j); putchar('\n');
// above does not work if you do two printfs instead of the putchar
// Don't know why.
   printf("this is an integer list: %d\n%d\n%d\n",i,j,k);
   printf("%d\n",x);

  // return 0;
}

//function definition: note it is after function call
// a la forward declaration
int func(){
	return 0;
}