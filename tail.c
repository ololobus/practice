#include <stdio.h>
#include <stdlib.h>

#define INITIALSTRLEN 70
#define STRLENINCREMENT 50
#define MINLINES 5

static int stop = 0;

/*
    Get N last lines of the input stream
    Usage: cat test.txt | ./tail N
*/

char *readline(int *stop)
{
    int c, i = INITIALSTRLEN, size;
    char *line, *linep;
    
    line = (char *) malloc(INITIALSTRLEN);
    linep = line;

    while((c = getchar()) != EOF)
    {
        if (i < 2)
        {
            size = linep - line;
            line = (char *) realloc(line, size + STRLENINCREMENT + i);
            linep = line + size;
            i += STRLENINCREMENT;
        }
        
        *linep++ = c;
        i--;
        
        if (c == '\n')
        {
            *linep++ = '\0';
            break;
        }
    }
    
    if (c == EOF)
    {
        *linep++ = '\0';
        *stop = 1;
    }
    
    return line;
}

void put(char **buffer_store, int *buffer_size, int nlines, char *l)
{
    int i;
    
    if (*buffer_size == nlines)
    {
        free(buffer_store[(*buffer_size) - 1]);
    }
    else
    {
        (*buffer_size)++;
    }

    for (i = *buffer_size - 2; i >= 0; i--)
    {
        buffer_store[i + 1] = buffer_store[i];
    }

    buffer_store[0] = l;
}

int main(int argc, char *argv[])
{
    int nlines, i, buffer_size;
    char *l, **buffer_store;
    
    nlines = argc > 1 ? atoi(argv[1]) : MINLINES;
    
    buffer_store = malloc(sizeof (char *) * nlines);
    buffer_size = 0;
    
    while (stop != 1)
    {
        l = readline(&stop);
        put(buffer_store, &buffer_size, nlines, l);
    }
    
    while (buffer_size--)
    {
        printf("%s", buffer_store[buffer_size]);
    }
}
