#include "main.h"

char *get_input(size_t *buffsize)
{
	char *buffer = NULL;
	printf("enter command: "); 
	ssize_t characters = getline(&buffer, buffsize, stdin);

	if (characters == -1)
	{
		fprintf(stderr, "Error reading input. \n");
		exit(1);
	}
	if (characters > 0 && buffer[characters - 1] == '\n')
	{
		buffer[characters - 1] = '\0';
		--characters;
	}
	return (buffer);
}
