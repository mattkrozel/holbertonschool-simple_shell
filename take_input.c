#include "main.h"


char *get_input(size_t *buffsize)
{
	ssize_t characters;
	char *buffer = NULL;
	printf("Enter command: ");
	characters = getline(&buffer, buffsize, stdin);

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

	if (isatty(STDIN_FILENO

	return (buffer);
}
