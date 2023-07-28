#include "main.h"

char *get_input(size_t *characters, size_t *buffsize)
{
	char *buffer = NULL;

	printf("enter command: ");
	getline(&buffer, buffsize, stdin);

	return (buffer);
}
