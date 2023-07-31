#include "main.h"

char *get_input(size_t *buffsize)
{
	char *buffer;
	printf("enter command: ");
       	getline(&buffer, buffsize, stdin);

	return (buffer);
}
