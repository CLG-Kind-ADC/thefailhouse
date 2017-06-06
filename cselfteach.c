//#include <stdio.h>
#include "csupport.c"
#include <float.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//#include <assert.h>

#define TRUE 1
#define _4 "DEVIL"
//tutorialspoint appears to have lied, you can't
//define a digit. or perhaps they got mixed up.

//experimenting with
# define tokenpasteR_string(n,y) printf("richard " #n " = %s\n", parasail_##y)
# define tokenpaster_digit(n) printf("token " #n " = %d\n",digit##n)

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

double getAverage(int arr[], int size){
   int i;
   double avg;
   double sum = 0;

   for (i = 0; i < size; ++i){
      sum += arr[i];
   }
   avg = sum/size;
   return avg;
}

union Data{
   int d;
   float f;
   char str[50];
} data;

//"pointer arithmetic": for example, pointer + 1 = address immediately following
//integers

//arr[i] = *(arr+i)
//^ "move to the ith memory location from arr and dereference that"
double average2(int * arr, int size){
   int i;
   double avg; 
   double sum = 0;

   for(i=0; i<size; i++){
      sum += arr[i]; 
   }
   avg = sum / size;
   return avg;
}
//above two fns: equivalent because params int arr[] and int * arr
//are essentially treated as the same thing: pointer to 1st elem of
//array, and then we iterate on the memory addresses going forward
//which are of course the following elements of the array.

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

int *add(int *x, int *y){
   static int z;
   z = *x + *y;
   return &z;
}

# define message_for(a,b) \
 puts(#a " and " #b ": Kick some NV A$$")
 // ^no semicolon?
 //works with puts...hm. I guess puts can do this
 // but it can't do "%d",10?

///////////////
// To return an array from a function in C
//1.can only return a POINTER to the array (by specifying the array's name w/o an index)
//2.since c doesn't return address of local var outside the fn, declare it a static var.

// and because this has a "for loop initial declaration"
// the program must now run in "C99 mode." i.e., -std=c99
int * getRandom(){
   //STATIC
   static int r[10];
srand( (unsigned)time( NULL ) ); //this line sets the seed
   for (int i =0; i<10; i++){
      r[i]=rand();
      printf("r[%d] = %d\n", i, r[i]);
   }
   return r;
}

typedef struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;

void book_print(book * book){
      printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}

struct {
   unsigned int x;
   unsigned int y;
} status1;

struct {
   unsigned int x:1;
   unsigned int y:1;
} status2;


void temp_converter(float start_celsius, float end_celsius, float step){
   
   printf("Celsius\t\tFahrenheit\n");
   printf("------\t\t---------\n");
   for (float i = start_celsius; i < end_celsius; i+=step){
      printf("%f\t%f\n",i, i*9.0/5.0 + 32 );
   }
}

// parametrized macro square
#define PREPROCESS_SQUARE(x) ((x) * (x))
//C-function square
int function_square(int x){
   return x*x;
}

void something();

static char buffer[13];

#define EXIE 20
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

//the only way I could actually test the string thing
char hello[11];
strcpy(hello,"hello, ");strcat(hello,"d");strcat(hello,"ear");
puts(hello);

int balance[5] = {1000, 2, 3, 17, 50};
//array "balance" declared locally to function "main"
double avg ;
avg = getAverage(balance, 5);

printf("after running the average function, average of balance is %f\n",avg);
//above: %d doesn't show the "right" answer--has to be f. (float?)
// Not sure why exactly.

double avg2;
int * a = balance;
avg2 = average2(balance, 5);
printf("after running average2 fn on balance, average of balance is %f\n",avg2);
double zz  = average2(a,5);
printf("after running average2 on int pointer assigned to balance, get %f\n",zz);

// Names assigned to arrays are treated as pointers--that's why dereferencing
// doesn't work as hoped

int * peter ;

peter = getRandom();

for (int i = 0; i<10; i++){
   printf("returned var thingy. %d element of array:\
 %d and is the same as %d\n", i, peter[i], *(peter+i));
}

//below: will print a nonsense value
//(that is, 0)
printf("%d\n",peter[11]);

   int  var1;
   char var2[10];

   printf("Address of var1 variable: %x\n", &var1  );
   printf("Address of var2 variable: %x\n", &var2  );

int heaven = 10; int hell = 30;
int *  earth;

earth = add(&heaven, &hell);
printf("the answer to %d + %d = %d\n", heaven, hell, *earth);

book book1;
book book2;
strcpy(book1.title,"Fuck your mom");
strcpy(book1.subject,"how to slap a ho");
strcpy(book1.author, "melanija knavs");
book1.book_id=19867;

printf("%s, %d\n", book1.title, book1.book_id);
book_print(&book1);

//union experimentation
data.d = 5;
printf("%d\n",data.d);
data.f = 25.0;
printf("This works, %f + %f = %f\n",data.f, 6.0, data.f + 6.0);
printf("But you can't do call this anymore: %d\n",data.d);
strcpy(data.str, "hello there");
printf("now you can't do %d and %f anymore\nbut you \
can do this: %s\n", data.d, data.f, data.str);

// struct and typedef experimentation
struct may{
   int i;
   float x;
} apr, jun;

jun.i = 10; jun.x = 91.1;
apr.i=14; apr.x = 10.4;
printf("%d %f\n", jun.i, jun.x);
printf("%f\n",jun.x + apr.x);

struct may july; july.i = 89;
printf("%d\n",july.i);

typedef struct may May;

May august;
august.i = 87;
printf("%d\n",august.i);

//and the following code doesn't work: 'unknown type'
//may december;

//bit field experimentation
printf("size of status1: %d\n",sizeof(status1)); //should be 8
printf("size of status2: %d\n",sizeof(status2)); //should be 4

//another note: different values take up different bit sizes?
// for example values from 0-7 take up 3 bits but a value of 8
// takes up more.

//32 1 bit width fields, up to 4 bytes. hit 33, go up to 8.

temp_converter(10.0,20.0,4.0);

printf("value of TRUE: %d\n",TRUE);
printf("value of _4: %s\n",_4);

putchar('x');putchar('\n');
//don't want to leave in a getchar (below) because I don't want
//program to have to wait for me. I'll just forget.
//int c = getchar();
//putchar(c);putchar('\n');


// setting up/testing for Cprogramming.com 2nd Basic Programming Challenge

strcpy(buffer,"hi im dyrus\n");
if (strrchr(buffer,'\n')){
   printf("Hello\n");
} else { printf("Byebye\n");}
puts(buffer);

printf("%d\n",EXIE);

printf("File :%s\n", __FILE__ ); //this file's name
printf("Date :%s\n", __DATE__ ); //today's date
printf("Time :%s\n", __TIME__ ); //time right now (run time)
printf("Line :%d\n", __LINE__ ); //line this command is on
printf("ANSI :%d\n", __STDC__ ); //"Def'd as 1 when compiler complies w/ANSI standard."

//demonstrates both stringize (#) and macro continuation op (\)
//the continuation op seems to work for regular C strings too
message_for(Nathan, Kenny);
// don't need quotes. preprocessor beauty

//testing puts vs printf
printf("%d\nwhere is shoxie\t\ttaco I don't know%f\n",10,10.0);
//puts("%d\nwhere is json\tderulo I don't know%f\n",10,10.0);

char parasail_test[10]; strcpy(parasail_test,"Hello");
tokenpasteR_string(papillon,test);
int digit1950 = 1492;
tokenpaster_digit(1950);

///// WHAT USED TO BE HERE ////
// File I/O things: now in cfileio.c


int h = PREPROCESS_SQUARE(9); printf("%d\n",h);
int lauren = function_square(7); printf("%d\n",lauren);

int sumx=17, countx = 5;
double meanx;
meanx=(double)sumx/countx;
printf("value of meanx: %f\n",meanx);

   int  zed = 17;
   char clarity = 'c'; // ascii value is 99 
   float summ;

   summ = zed + clarity;
   printf("Value of sum : %f\n", summ );
   //above as opposed to if we declare summ to be an int
   // demonstrates coercion to float type

   FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "r");
   
   if (pf == NULL) {
   
      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
   }
   else {
   
      fclose (pf);
   }

return 0;
}

//function definition: note it is after function call
// a la forward declaration
int func(){
	return 0;
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
//i had previously misunderstood this, leading to the "weird echo shit"
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

// function not to call because it has scanf and I don't want to
// bother with user inputs
// but I thought it illustrated scanf
 void something(){

char str1[100];
char str2[100];
int i;
scanf("%s %s %d", str1, str2, &i);

 }
//scanf: needs buffers or an integer declared but not init
//(and will use the pointer)
//and needs to match or else it will crash the program


// Extra Notes

 /*
 #include ANYTHING ELSE'
     This variant is called a "computed #include".  Any `#include'
     directive whose argument does not fit the above two forms is a
     computed include.  The text ANYTHING ELSE is checked for macro
     calls, which are expanded (see Macros.).  When this is done,
     the result must fit one of the above two variants--in particular,
     the expanded text must in the end be surrounded by either quotes
     or angle braces.

     This feature allows you to define a macro which controls the file
     name to be used at a later point in the program.  One application
     of this is to allow a site-specific configuration file for your
     program to specify the names of the system include files to be
     used.  This can help in porting the program to various operating
     systems in which the necessary system header files are found in
     different places.
*/