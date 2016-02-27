#include<stdio.h>

/* test big-endian or little-endian */
int main()
{
  unsigned int i = 1;
  char *p = (char*)&i;
  // if big-endian: from small to large address, 01 00 00 00
  // else little-endian: 00 00 00 01
  if(p)
    printf("little endian \n");
  else
    printf("big endian \n");

  return 0;  
}