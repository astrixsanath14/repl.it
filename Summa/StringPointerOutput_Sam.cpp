#include<stdio.h>

void function(char **);

int main()
{
  char *arr[] = {"ant","bat","cat","dog","egg","fly"};
  function(arr);
  return 0;
}

void function(char **ptr)
{
  char *ptr1;
  printf("%d\n",sizeof(int));
  ptr1 = (ptr+sizeof(int))[-2];
  printf("%s\n",ptr1);

  ptr1 = (ptr+2)[-2];
  printf("%s\n",ptr1);
}

/*
Summa/StringPointerOutput_Sam.cpp
*/