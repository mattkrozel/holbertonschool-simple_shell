#include "main.h"

int main(void)
{
	size_t buffsize = BUFF_SIZE;
	int x = 0;
	char *buffer, **token_array;
	size_t characters;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL || token_array == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}

	while (buffer)
	{
		buffer = get_input(&characters, &buffsize);
		characters = getline(&buffer, &buffsize, stdin);
		if (characters > 0 && buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
			--characters;
		}	
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
		printf("%zu characters read \n", characters);
		printf("your command is %s \n", buffer);

		int num_tokens;

		token_array = split_string(buffer, WHITESPACE, &num_tokens);
		print_tokens(token_array, num_tokens);
		free_tokens(token_array, num_tokens);

		free(buffer);
	}


	free(buffer);
	return (0);
}
