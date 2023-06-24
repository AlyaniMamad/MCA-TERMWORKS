#include <stdio.h>

int main() {
    char string[100], *p;
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    gets(string);

    p = string; // set the pointer to the first character of the string

    while (*p != '\0') {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            vowels++;
        } else if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            consonants++;
        }
        p++; // move the pointer to the next character
    }

    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);

    return 0;
}
