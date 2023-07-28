#include "main.h"

char *get_input(size_t *characters, size_t *buffsize)
{
	char *buffer = NULL;

	printf("enter command: ");
	getline(&buffer, buffsize, stdin);
	if (*characters > 0 && buffer[*characters - 1] == '\n')
	{
		buffer[*characters - 1] = '\0';
		--(*characters);
	}
	return (buffer);
}
