#include <stdio.h>
 
// Alignment requirements
// (typical 32 bit machine)
 
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes
 
// structure A - 3
/*
2 byte aligned: 
sizeof(char) + 1(padding) + sizeof(short int)
*/
typedef struct structa_tag
{
   char        c;
   short int   s;
} structa_t;


 
// structure B - 7
/*
2 + 1 + 1 (padding) + 4 = 8 bytes
*/
typedef struct structb_tag
{
   short int   s;
   char        c;
   int         i;
} structb_t;
 
// structure C - 13
typedef struct structc_tag
{
   char        c;
   double      d;
   int         s;
} structc_t;
 
// structure D - 13
typedef struct structd_tag
{
   double      d;
   int         s;
   char        c;
} structd_t;
 
int main()
{
   printf("sizeof(structa_t) = %d\n", sizeof(structa_t));   // 4
   printf("sizeof(structb_t) = %d\n", sizeof(structb_t));   // 8
   printf("sizeof(structc_t) = %d\n", sizeof(structc_t));   // 16
   printf("sizeof(structd_t) = %d\n", sizeof(structd_t));   // 16
   
   printf("sizeof char on my Ubuntu 14.04 LTS 32-bits system: %d\n", sizeof(char));
   printf("sizeof short int on my Ubuntu 14.04 LTS 32-bits system: %d\n", sizeof(short int));
   printf("sizeof int on my Ubuntu 14.04 LTS 32-bits system: %d\n", sizeof(int));
   printf("sizeof double on my Ubuntu 14.04 LTS 32-bits system: %d\n", sizeof(double));
   return 0;
}

/*
Very nice concept explanation and I want to add some more with output of the program on both architecture. 
32 bit out put :
sizeof(structa_t) = 4
sizeof(structb_t) = 8
sizeof(structc_t) = 16
sizeof(structd_t) = 16

64 Bit output :
sizeof(structa_t) = 4
sizeof(structb_t) = 8
sizeof(structc_t) = 24
sizeof(structd_t) = 16

The alignment is done on the basis of the highest size of the variable in a structure. And also on the basic of architecture(32 or 64 Bit)
For 32 Bit - Max alignment is 4 Bytes 
For 64 Bit - Max alignment is 8 Bytes

*/