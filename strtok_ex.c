/*
 * The following description is from Linux Programmer's Manual (strtok(3)):
 *
 * #include <string.h>
 * char *strtok(char *str, const char *delim);
 *
 * The  strtok() function breaks a string into a sequence of zero or more
 * nonempty tokens.  On the first call to strtok() the string to be parsed
 * should be specified in str. In each subsequent call that should parse
 * the same string, str must be NULL.
 *
 * The delim argument specifies a set of bytes that delimit the tokens in
 * the parsed string.  The caller may specify different strings in  delim
 * in  successive  calls  that parse the same string.
 *
 * Each  call  to strtok() returns a pointer to a null-terminated string
 * containing the next token.  This string does not include the delimiting
 * byte.  If no more tokens are found, strtok() returns NULL.
 */

#include <stdio.h>
#include <string.h>

int main()
{
   char message[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
   char* token;

   /* get the first token from the message, seperated by
    * space character */
   token = strtok(message, " ");
   printf("1st token using delimiter ' ': %s\n", token);

   /* get the second token from the message, NULL must be
    * used to get tokens from the previous string now */
   token = strtok(NULL, " ");
   printf("2nd token using delimiter ' ': %s\n", token);

   token = strtok(NULL, ",");
   printf("1st token using delimiter ',': %s\n", token);   
   
   /* the following loop gets the rest of the tokens until the
    * end of the message */
   while ((token = strtok(NULL, " ")) != NULL)
      printf("Next token with delimiter ' ': %s\n", token);

   return 0;
}