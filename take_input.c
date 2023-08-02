#include "main.h"

char *get_input(size_t *buffsize);

int main()
{
	char *command;
	int status;
	size_t buffsize;

	while (1)
	{
		printf("Enter command:");
		command = get_input(&buffsize);

			if (command == NULL)
			{
				break;
			}
		status = system(command);

		if (status != 0)
		{
			printf("Error executing command: %s\n" , command);
		}
	}
		return 0;
}

char *get_input(size_t *buffsize)
{
	size_t buffsize = 1024;
	char *buffer = malloc(buffsize);
	
	if (buffer == NULL)
	{
		fprintf(stderr, "Error allowcating memory. \n");
		exit(1);
	}
	
	ssize_t characters = getline(&buffer, &buffsize, stdin);
	if (characters == -1)
	{
		fprintf(stderr, "Error reading input.\n");
		exit(1);
	}
	
	if (characters > 0 && buffer[characters - 1] == '\n')
	{
		buffer[characters - 1] = '\0';
	}
	
	return buffer;
}
