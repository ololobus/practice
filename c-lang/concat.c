#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 150

/*
    Concatenate str2 to the end of str1 using pointers
*/

void concat(char *str1p, char *str2p)
{
    while (*str1p++)
        ;
    while ((*(str1p++ - 1) = *str2p++))
        ;
}

int main()
{
    char str1[MAXSTRLEN], str2[MAXSTRLEN];
    
    fgets(str1, MAXSTRLEN, stdin);
    fgets(str2, MAXSTRLEN, stdin);
    
    str1[strlen(str1) - 1] = 0;
    str2[strlen(str2) - 1] = 0;

    concat(str1, str2);
    
    printf("%s\n", str1);
}
