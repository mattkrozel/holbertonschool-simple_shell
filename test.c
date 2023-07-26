#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *buffer;
	size_t buffsize = 32;
	size_t characters;
	int tkncntr;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
		exit(1);
	while (buffer)
	{
		printf("enter command: ");
		characters = getline(&buffer, &buffsize, stdin);
		if (characters > 0 && buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
			--characters;
		}
		if (strcmp(buffer, "exit") == 0)
			break;

		printf("%zu characters read \n", characters);
		printf("your command is %s \n", buffer);
		
		char *token;
		token = strtok(buffer, " ");

		while (token != NULL)
		{
			printf("Token: %s\n", token);
			token = strtok(NULL, " ");;
		}
	}

	free(buffer);
	return (0);
}
