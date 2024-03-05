#include <stdio.h>

// Function to find length of a string
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to reverse a string
void stringReverse(char *str) {
    int length = stringLength(str);
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to compare two strings
int stringCompare(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

// Function to concatenate two strings
void stringConcatenate(char *dest, const char *src) {
    int dest_len = stringLength(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
}

// Function to copy one string to another
void stringCopy(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter string 1: ");
    scanf("%s", str1);
    
    printf("Enter string 2: ");
    scanf("%s", str2);
    
    printf("Length of string 1: %d\n", stringLength(str1));
    printf("Length of string 2: %d\n", stringLength(str2));
    
    stringReverse(str1);
    printf("Reversed string 1: %s\n", str1);
    
    printf("Comparison result: %d\n", stringCompare(str1, str2));
    
    stringConcatenate(str1, str2);
    printf("Concatenated string: %s\n", str1);
    
    stringCopy(str2, str1);
    printf("Copied string: %s\n", str2);
    
    return 0;
}
