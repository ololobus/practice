#include <stdio.h>
#include <string.h>

// static char *str = "test";

int main()
{
	int i = 0;
	char str[] = "test";

	while(1)
	{
		char *next = (char *) (str + strlen(str) - i);

		if (*next != '\0')
			printf("%d %p %p: %s \n", i, &i, next, next);

		i++;
	}
}
