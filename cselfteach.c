//#include <stdio.h>
#include "csupport.c"
#include <float.h>
#include <math.h>
# include <string.h>

int i=10, j=11, k=290;
int z = 19;
int *p = &z;
char c, ch;

int count = 5;

float f, salary;
double d;

// function declaration
int func();
//extern void write_extern(void);
void hello();
int marcus();
int elizabeth();
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

   long lolo = pow(5,4);
   printf("%d\n",lolo);


// function call
   int x = func();

   printf("%d",i+j); putchar('\n');
// above does not work if you do two printfs instead of the putchar
// Don't know why.
   printf("this is an integer list: %d, %d, %d\n",i,j,k);
   printf("%d\n",x);

// testing do... while   
//below: the condition starts off unmet. But in spite of that,
// the program runs once, because condition is evaluated at end.
   int ster = 51;
   do {printf("hi i'm %d\n",ster);} while(ster<20);

   int ai=10;

katherine(ai);
print_stars_like_java();

hello();

  // return 0;
}

//function definition: note it is after function call
// a la forward declaration
int func(){
	return 0;
}

//for some reason, calling these void doesn't work

int marcus(int x){
  if (x==15){printf("leedleedlee\n");}

}

int katherine(int qq)   {  

//the function after the keyword (LOOP) will run even
// if not sent by the goto.
       do {LOOP:marcus(qq); 
 
      if( qq == 15) {
         /* skip the iteration */
         qq = qq + 1;
         goto LOOP;
      }
      
      printf("value of qq: %d\n", qq);
      qq++;
   }while( qq < 20 );
 }

int print_stars_like_java(){
// you must create a character array
// and it must be long enough
// also just declaring char str; won't work, because you can't
   // add on to it (I'm pretty sure)
   char str[10];
   int k= 0;
   char* luna = "*";
   strcpy(str,luna);
   printf("%s\n",str);
   do {
      strcat(str,luna);
      k++;
      puts(str);
   } while (k<8);
}

void hello(){
   printf("hi!\n");
}