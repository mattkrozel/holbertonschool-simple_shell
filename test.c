#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer;
	size_t buffsize = 32;
	size_t characters;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
		exit(1);
	printf("enter command: ");
	characters = getline(&buffer, &buffsize, stdin);
	printf("%zu characters read \n", characters);
	printf("your command is %s \n", buffer);

	return (0);
}
