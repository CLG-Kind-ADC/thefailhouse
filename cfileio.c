#include <stdio.h>

int main(int argc, char** argv){
   FILE *fp;

   fp = fopen("tmp/test.txt", "w+"); //the tutorial says "/tmp/test.txt" but that doesn't work
   //also it appears it has to be in the working directory or lower, can't open one higher up.
   fprintf(fp, "nathan...\n");
   fputs("Kenny...\n", fp); // these overwrite what was there before.
   fclose(fp);
   FILE * rashardlewis= fopen("tmp/rashardlewis.txt","a+");
//a brief interlude to explain: the file is "closed", but the pointer fp
//is still active. (and you can't redefine it.)
//And the location it points to is exactly where the next fopen function
//puts the next opened file. Effectively, rashardlewis and fp are 
//pointers to the same place. Equivalent.

//HOWEVER, if you open two files at the same time,
//naturally they will be given different addresses, and the names will
//point to different places. So writing to the second won't write to the first.

//And of course, if the file is closed and none is reopened after,
//you can't write into anything. There's nothing to write into.
   fprintf(fp,"nathan schmitty");
   fputs("tom brady",rashardlewis);
   fprintf(fp,"kennyschrubby");
   fclose(rashardlewis);
   FILE * marcia = fopen("tmp/marcia.txt","a+");

   fprintf(rashardlewis,"trumpet");
   fputs("richard got the magic stick\n",marcia);
   fputs("eric\n",fp);
   fclose(marcia);

if (marcia==rashardlewis){printf("marcia and lewis point to the same");}
if (rashardlewis==fp){printf(" location, and so does fp\n");}

return 0;
}