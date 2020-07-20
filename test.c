#include<stdio.h>
#include<stdlib.h>
int main()
{
  int *p=NULL;
  p=malloc(sizeof(int));
  printf("%d\n",p );
  return 0;
}
