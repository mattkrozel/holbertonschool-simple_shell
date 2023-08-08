#include "main.h"

/**
 * reads a line of input from used
 * @param buffsize: A pointer to a size_t variable that indicates the size of the buffer.
 * @return A pointer to a string containing the read input. 
 **/
char *get_input(size_t *buffsize)
{
	ssize_t characters; /* num of chars read bby getline */
	char *buffer = NULL; /* buffer to store read input */
	if (isatty(STDIN_FILENO)) /* check if input is from term if so display promt */
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	characters = getline(&buffer, buffsize, stdin); /* read a line of input */
	
	if (characters == EOF) /* check if EOF has been reached */
	{
		if (buffer) /* if buffer is not null free memory and set pointer to null*/
		{
			free(buffer);
			buffer = NULL;
		}
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	
	/* replace newline char w null term */
	
	if (characters > 0 && buffer[characters - 1] == '\n')
	{
		buffer[characters - 1] = '\0';
		--characters;
	}
	
	return buffer;
}
