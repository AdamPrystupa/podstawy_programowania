#include <stdio.h>
#include <math.h>

int main(){
  int i=1,x;
  
  do
  {
    printf("Podaj %d. wartosc parametru: ",i);
    scanf("%d",&x);
    i++;
    if (x==99)
      break;
    if (x>=-5&&x<=5)
      printf("Aktualna wartosc parametru: %d\n",x);
    else
      printf("Bledna wartosc parametru!\n");
  }while(1);
  return 0;
}
