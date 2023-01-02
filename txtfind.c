#include "Ex3.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define MAX_INPUT_LENGTH 64000

int main(int argc, char *argv[]) {

    // First, we'll get the first line which provides us the special word and a/b.
    char first_word_temp[WORD];
    char first_word[WORD];
    char a_or_b[1];
    scanf("%s", first_word_temp);
    strcpy(first_word, first_word_temp);

    scanf("%s", a_or_b);


    if (*(a_or_b) == 'a') 
    {
        char input[MAX_INPUT_LENGTH]; //^^
        char word_copy[WORD];
        strcpy(word_copy, first_word);
        // fgets - a function that can recived txt.
        // stdin - a method that read a line, used for fgets.
        while (fgets(input, sizeof(input), stdin) != NULL)
        {
            char line[sizeof(LINE)];  // declare the line
            strcpy(line, input);  // copy the input string to the declared line

            char first_word_copy[WORD];
            strcpy(first_word_copy, word_copy);

            if (substring(line, first_word_copy) == 1)
            {
                printf("%s", line);
            }
        }
    }

    if (*(a_or_b) == 'b') 
    {


        char input[MAX_INPUT_LENGTH];
        char *p = input;  // p will be used to iterate through input array
        int c;

        // Read input one character at a time until end of input or array is full
        while ((c = getchar()) != EOF && p < input + MAX_INPUT_LENGTH - 1) {
            *p++ = c;
        }
        
        // Add null terminator to the end of the string
        *p = '\0';

        char word[WORD];
        //char empty_word[WORD];
        int indexWord = 0;
        int indexInput = 0;

        char *pointer = input;  // p will be used to iterate through input array
        while(*pointer != '\n')
        {
            pointer++;
        }

        while(*pointer != '\0') 
        {

            while(*pointer != '\0' && *pointer != '\t' && *pointer != '\r' && *pointer != ' ' && *pointer != '\n' && *pointer != EOF)
            {
                *(word + indexWord) = *(input + indexInput);
                indexWord++;
                indexInput++;
                pointer++;
            }

            *(word + indexWord) = '\0';
            

            if (similar(word,first_word) == 1) {
                printf("%s\n", word);
            }

            // initializes all elements of the array word to 0
            // strcpy(word, empty_word);
            int i;
            for (i = 0; i < strlen(word); i++) {
                *(word + i) = ' ';
            }

            
            indexWord = 0;
            pointer++;
            indexInput++;
        }
    }
    
}

int getLine(char s[]) {

    int i = 0;
    return i;
}

// Check if the word s is similar to word t
int similar (char* s, char* t)
{   

    int s_len = strlen(s);
    int t_len = strlen(t);

    //printf("size s: %d and t: %d\n", s_len, t_len);

    if (s_len < t_len) {
        return 0;
    }

    if (s_len > t_len+1) {
        return 0;
    }


    // First, check if a s is bigger than t in 2 or more chars.
    char* i = s;
    char* j = t;
    int len = 0;

    while (*j != '\0') { //t is the shortest.       
        i++;
        j++;
        len++;
    }

    // Now, *j == '\0'. We need (*i == '\0' OR *(i+1) == '\0'). otherwise, s is bigger than s in 2 chars or more.
    // For ex: t = abc\0 | s = abcdefg. *i = d, *(i+1) = e | abcde is enough to say it is more than 2 chars.
    if (*i != '\0' && *(i+1) != '\0') {
        return 0;
    }

    //An edge case when |s|=1, |t|=1 and s!=t. If true, return 1. else 0.
    if ( (len == 1) && (*i == '\0') && (*(i-1) != *(j-1)) ) {
        return 0;
    }

    //check if similar
    char* index = s;
    char* jndex = t;
    int errors = 0;

    while(*jndex != '\0')
    {
        if(*index != *jndex)
        {
            errors++;
            jndex--;
        }

        index++;
        jndex++;

        // To break the infinite-loop of jndex-- and jndex++:
        if (*index == '\0')
            break;
    }

    // If the amount of errors ("wrong" char) is 0 or 1, it's good.
    // 0 = equalties.
    // 1 = a single error.
    if(errors <= 1)
    {
        return 1;
    }

    return 0;
}

int substring(char* str1, char* str2) {
    // Return 1 if str2 is a substring of str1
    char* i = str1;
    
    while (*i != '\0') {
        char* j = str2;
        int flag = 1;
        int p = 0;
        
        while (*j != '\0') {
            if (*(i + p) != *j) {
                flag = 0;
                break;
            }
            p++;
            j++;
        }
        if (flag == 1) {
            return 1;
        }
        i++;
    }
    return 0;
}

void print_lines(char* str)
{
    //char* pointer = str;

    int index = 0;
    char* word; // The word we will check if it is contained in any line.
    //char word[30];

    printf("blal");

    while (*str != ' ' || *str != '\t' || *str != '\r') 
    {
        *(word+index) = *(str+index);
        str++;
        index++;
    }
    
    printf("Just checking: the word is %s", word);


    // As long as str* is not null
    while ((*str)) 
    {
        int i = 0;
        char* line;
        // As long as str* is not 
        while ((*str) && *str != '\n') 
        {
            *(line + i) = *(str + i);

            i++;
            str++;
        }
        if (substring(line, word) == 1)
        {
            printf("%s\n", line);
        }
    }
}
