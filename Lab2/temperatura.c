#include <stdio.h>
#include <math.h>

int main(){
  int prog=20,x;
  printf("Podaj temperature we Wroclawiu: ");
  scanf("%d",&x);
  if (x>=prog)
    printf("Jest bardzo ladna pogoda!\n");
    else
      printf("Nie jest zbyt cieplo!\n");
  return 0;
}
