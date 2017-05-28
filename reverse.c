#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 150

/*
    Reverse keyboard input via recursion
*/

char string[MAXSTRLEN];

void reverse(char str[])
{
    int c, l;
    char *substr;
    
    l = strlen(str);
    
    putchar(str[l - 1]);

    if (l > 1)
    {
        str[l - 1] = 0;
        reverse(str);
    }
}

int main()
{
    fgets(string, MAXSTRLEN, stdin);
    
    reverse(string);
    printf("\n");
}
