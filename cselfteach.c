//#include <stdio.h>
#include <stdio.h>
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
int katherine();
void print_stars_like_java();

int max();

int alternative_max(int one, int two){
   int result;
   if (one > two){
      result = one;
   }
   else{
      result = two;
   }
   return result;
}

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

printf("This is the greater number of %d and %d: %d\n",10,94,max(10,94));
printf("this should give exact same # as above: %d\n",max(10,94));

  // return 0;
}

//function definition: note it is after function call
// a la forward declaration
int func(){
	return 0;
}

//next section:

// this is evidently not the express purposes of "goto"
//but it works...only due to the "if" in marcus

//"continue" can do basically the same thing: skip if condition

//goto is probably most useful if you have an end condition
// and when/if it hits that condition
//you want program to go straight somewhere else and not come back

// possible: get it to work like I'm thinking:
// put all into one function. Hmm...
int marcus(int x){

   //15 or 16: changes depending on where I put the LOOP keyword
   //16 if outside do
   //15 if inside
  if (x==16){printf("leedleedlee\n")
   ;}

}
//calling katherine anywhere inside Marcus will likely result in endless loop
//  nested, and no exit case
//as I've called it previously, "some weird echo shit"

int katherine(int qq)   {  

//the function after the keyword (LOOP) will run even
// if not sent by the goto.
  LOOP:marcus(qq);      do {
 
      if( qq == 15) {
         /* skip the iteration */

         qq = qq + 1;
         goto LOOP;
      }
      
      printf("value of qq: %d\n", qq);
      qq++;
   }while( qq < 20 );
 }

void print_stars_like_java(){
// you must create a character array
// and it must be long enough
// also just declaring char str; won't work, because you can't
// add on to it in C: no appending (at leastI'm pretty sure)
   char str[10];
   int k= 0;
   char* luna = "*";
//all three of below work (i.e. symbol must be a character not ptr):

   //strcpy(str,luna);
   //str[0]= *luna;
   str[0] = *"*";
//
   printf("%s\n",str);
   do {
   //strcat comes from include string.h
      strcat(str,luna);
      k++;
      puts(str);
   } while (k<8);
}

void hello(){
   printf("hi!\n");
}

int max(int first, int second){
   if (first > second){
      return first;
   } else{
      return second;
   }
}