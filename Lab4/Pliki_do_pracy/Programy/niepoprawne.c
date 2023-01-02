#include <stdio.h>

int main()
{
  int x=3;

  x=((x++) * (x++));

  printf("%d\n",x);

  return(0);
}
