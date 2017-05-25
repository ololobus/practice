#include <stdio.h>

#define MAXLEN 70
#define IN 1
#define OUT 0

/*
    Wrap lines to MAXLEN
    cat test.txt | ./wrap
*/

main()
{
    int c, l = 0, state = OUT;
    
    c = getchar();
    
    while (c != EOF)
    {
        l++;
        
        if (c == ' ' || c == '\t')
        {
            state = OUT;
            putchar(c);
            
            if (l >= MAXLEN)
            {
                l = 0;
                putchar('\n');
            }
        }
        else if (c == '\n')
        {
            l = 0;
            putchar('\n');
        }
        else
        {
            state = IN;
            putchar(c);
        }
        
        c = getchar();
    }
}
