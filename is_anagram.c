/*
C89 doesn't define boolean type, _Bool is assigned as 1 or 0
C99 provide <stdbool.h>, use 'bool' to replace '_Bool', true/false to replace 1/0

when using definition in loop, you should compile with '-std=c99'

$gcc -w -g -o is_anagram is_anagram.c -std=c99


const char * p : mutable pointer to a constant character
char * const p : constant pointer to mutable character
const char * const p : constant pointer to constant character

char const * p : same as const char * p

*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool is_anagram(const char* str1, const char* str2) {
	if(strlen(str1) != strlen(str2))	return false;

	int len = (int)strlen(str1);
	int record[256];

	memset(record, 0, sizeof(record));
	
	for(int i = 0; i < len; ++i) {
		record[str1[i]]++;
		record[str2[i]]--;
	}

	for(int i = 0; i < 256; ++i) {
		if(record[i] != 0) {
			return false;
		}
	}
	return true;
}

int main() {

	char* str1 = "p";
	char* str2 = "q";
	if(is_anagram(str1, str2)) {
		printf("Yes!\n");
	} else {
		printf("No!\n");
	}
	return 0;
}