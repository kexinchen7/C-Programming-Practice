/*
wc - print non-empty line, word, and byte counts from a file

SYNOPSIS

    wc [OPTIONS] FILE

DESCRIPTION

    Print non-empty line, word, and byte counts for FILE.

OPTIONS:
-L 
    print the longest line
    
-M k
    print the lines exceeding k characters
*/  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

int is_delimiter(char c);
void print_longest(char *file, int byte_count);
void print_exceed_k(char *file, int byte_count, int k);

int main(int argc, char **argv)
{
// processing the arguments
    /*
    for simplification, only three format supported:

    ./wc -L filename
    ./wc -M k filename
    ./wc -L -M k filename

    */
    char *file;
    int op1 = 0; // 0: unset, 1: set
    int op2 = 0;
    int k = 0;

    if(argc < 2) {
        exit(0);
    }
    
    if(argc == 2) {
        file = argv[1];
    }
    
    if(argc == 3) {
        if(strcmp("-L", argv[1]) == 0) {
            file = argv[2];
            op1 = 1;
        } else {
            exit(0);
        }
    }

    if(argc == 4) {
        if(strcmp("-M", argv[1]) == 0) {
            file = argv[3];
            op2 = 1;
            k = atoi(argv[2]);
            
        } else {
            exit(0);
        }
    }

    if(argc == 5) {
        if(!strcmp("-L", argv[1]) && !strcmp("-M", argv[2])) {
            op1 = 1;
            op2 = 1;
            k = atoi(argv[3]);
            file = argv[4];
        } else {
            exit(0);
        }
    }

    FILE *read;
    unsigned int line_count = 0, word_count = 0, byte_count = 0;    
    read = fopen(file, "r");
    
    if(read == NULL) {
        printf("Error!\n");
        exit(0);
    }
    
    int inword = FALSE; // if the current char is in a word
    char ch;

    while((ch = fgetc(read)) != EOF) {
        byte_count++;

        if(ch == '\n') {
            line_count++;
        }

        // if the current char is not delimiter, and the previous char is not in word
        if((inword == FALSE) && (is_delimiter(ch) == FALSE)) {
            inword = TRUE;
            word_count = word_count + 1;
        // the current is a delimiter, and the previous char is in word 
        } else if ((inword == TRUE) && (is_delimiter(ch) == TRUE)) {
            inword = FALSE;
        }

    }
    // for the last line, since there's no '\n' at the end. we still count it as a line.
    if(byte_count != 0) {
        line_count++;
    }

    fclose(read);
    
    printf(">>> LINES: %d, WORDS: %d, BYTES: %d\n", line_count, word_count, byte_count);
 
    // print longest string
    if(op1 == 1) {
        print_longest(file, byte_count);
    }

    if(op2 == 1) {
        print_exceed_k(file, byte_count, k);
    }

}


// Check if it is a delimiter, like punctions or white space
int is_delimiter(char c) {
    if(    (c == '\n') || (c == '\t') || (c == ' ') 
        || (c == '.') || (c == ',') || (c == ';') 
        || (c == ':') || (c == '?') || (c == '!')) 
    {
        return TRUE;
    }
    return FALSE;
}



void print_longest(char *file, int byte_count) {
    FILE *read;
    read = fopen(file, "r");
    
    char ch;
    char *first = (char *)malloc(sizeof(char)*(byte_count+1));
    char *p;

    p = first;

    // store all characters
    while( (ch = fgetc(read)) != EOF) {
        *p = ch;
        p++;
    }
    *p = '\n'; // for the EOF, we append '\n' at the end

    int cur_len = 0;
    int max_len = 0;
    int max_start_index = 0;

    int i = 0;
    for( ; i < byte_count + 1; ++i) {
        if(*(first+i) == '\n') {
            if(max_len < cur_len) {
                max_len = cur_len;
                max_start_index = i - cur_len;
            }
            cur_len = 0;

        } else {
            cur_len ++;
        }

    }
    printf(">>>THE LONGEST IS: \n");
    int j = 0;
    for( ; j < max_len; ++j) {
        printf("%c", *(first+max_start_index+j));
    }
    printf("\n");

    free(first); 
    fclose(read);
}


void print_exceed_k(char *file, int byte_count, int k) {
    FILE *read;
    read = fopen(file, "r");

    char ch;
    char *first = (char *)malloc(sizeof(char)*(byte_count+1));
    char *p;

    p = first;

    // store all characters
    while( (ch = fgetc(read)) != EOF) {
        *p = ch;
        p++;
    }
    *p = '\n'; // for the EOF, we append '\n' at the end


    int i = 0;
    int cur_len = 0;
    printf(">>> LINES THAT EXCEED K: \n");
    for( ; i < byte_count + 1; ++i) {
        if(*(first+i) == '\n') {
            if(cur_len > k) {
                int j = 0;
                for( ; j < cur_len; ++j){
                    printf("%c", *(first+i-cur_len+j));   
                }
                printf("\n");
            }
            cur_len = 0;

        } else {
            cur_len ++;
        }       
    }

    free(first); 
    fclose(read);
}