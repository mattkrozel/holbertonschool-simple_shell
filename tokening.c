#include "main.h"

/**
 * splits string into tokens based on given delimiters
 * @param str: The string to be split.
 * @param delimiters: The delimiters for splitting the string.
 * @param num_tokens: A pointer to an integer that will store the number of tokens produced.
 * @return A pointer to an array of tokens.
 */

char **split_string(char *str, const char *delimiters, int *num_tokens)
{	
	char *token;
	char **tokens = NULL;
	int buffer_size = BUFF_SIZE;
	int count = 0;
	
	/* allocate initial meory for storing tokens */
	tokens = malloc(buffer_size * sizeof(char *));
	if (!tokens)
	{
	
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}
	
	/* tokenize string */
	token = strtok(str, delimiters);
	while (token != NULL)
	{
		/* if num of tokens exceeds buffer size reallocate mem */
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
		/* store the token and move to the next */
		tokens[count++] = strdup(token);
		token = strtok(NULL, delimiters);
	}
	
	/* returns total num of tokens */
	*num_tokens = count;
	return tokens;


/**
 * prints tokens
 * @param tokens: A pointer to an array of tokens
 * @param num_tokens: The number of tokens
 **/

}

void print_tokens(char **tokens, int num_tokens)
{
	int i;
	for (i = 0; i < num_tokens; ++i)
	{
		printf("%s\n", tokens[i]);
	}
}


/**
 * frees memory used by tokens
 * @param tokens: A pointer to an array of tokens.
 * @param num_tokens: The number of tokens.
 **/
void free_tokens(char **tokens, int num_tokens)
{
	int i;
	for (i = 0; i < num_tokens; ++i)
	{
		free(tokens[i]);
	}
	free(tokens);
}
