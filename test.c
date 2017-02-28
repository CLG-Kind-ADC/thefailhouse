#include <stdio.h>

int add_together(int x, int y) {
  int result = x + y;
  return result;
}

typedef struct {
	float x;
	float y;
} new_type;

int main(int argc, char** argv) {
  puts("Hello, world!");
  int added = add_together(10,18);
  printf("%d\n",added);
  new_type p;
  p.x = 0.1;
  p.y = 10.0;
  float number = p.x*p.x+p.y*p.y;
  printf("%f\n",number);
return 0;
}