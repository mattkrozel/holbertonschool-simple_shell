#include "main.h"

char **split_string(char *str, const char *delimiters, int *num_tokens)
{	
	char *token;
	char **tokens = NULL;
	int buffer_size = BUFF_SIZE;
	int count = 0;
	
	tokens = malloc(buffer_size * sizeof(char *));
	if (!tokens)
	{
	
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}
	
	token = strtok(str, delimiters);
	while (token != NULL)
	{
		if (count >= buffer_size)
		{
			buffer_size *= 2;
			tokens = realloc(tokens, buffer_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Memory allocation error.\n");
				exit(1);
			}
		}
		tokens[count++] = strdup(token);
		token = strtok(NULL, delimiters);
	}
	
	*num_tokens = count;
	return tokens;

}

void print_tokens(char **tokens, int num_tokens)
{
	int i;
	for (i = 0; i < num_tokens; ++i)
	{
		printf("%s\n", tokens[i]);
	}
}

void free_tokens(char **tokens, int num_tokens)
{
	int i;
	for (i = 0; i < num_tokens; ++i)
	{
		free(tokens[i]);
	}
	free(tokens);
}

void execute_command(char *command) 
{
	int num_tokens;
	char **tokens = split_string(command, WHITESPACE, &num_tokens);
	char *argv[num_tokens + 1];
	for (int i = 0; i < num_tokens; i++) 
	{
		argv[i] = tokens[i];
	}
			argv[num_tokens] = NULL;
			execve(argv[0], argv, NULL);
}
