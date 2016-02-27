#include <stdio.h>

char* strStr(char *haystack, char *needle) {
	char* src = haystack;
	char* dst = needle;

	while(*haystack != '\0') {
		if(*dst == '\0') {			// whole string matched
			return haystack;
		} else if(*src == '\0') {	// the source string is not long enough
			return NULL;
		} else if(*src == *dst) {	// character matched
			src++;
			dst++;
		} else {					// character not matched, backtracking
			src = ++haystack;
			dst = needle;
		}
	}
	if(*dst == '\0')	return haystack;
	else return NULL;
}

int main() {
	char *haystack = "MMYY131499999";
	char *needle = "14";
	printf("begins at '%s' \n", strStr(haystack, needle));
}