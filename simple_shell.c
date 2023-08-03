#include "main.h"

int main(int ac, char **argv)
{
	long unsigned int a;
	size_t buffsize = BUFF_SIZE;
	char *buffer, **token_array;
	size_t characters;
	int num_tokens, i;
	char *real_command;
	(void)ac;

	a = -1;

	buffer = (char *)malloc(buffsize * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(1);
	}

	while (1)
	{
		buffer = get_input(&buffsize);
		characters = strlen(buffer);
		if (characters == a)
		{
			printf("Exiting shell....\n");
			return (-1);
		}

		if (characters > 0 && buffer[characters - 1] == '\n')
		{
			buffer[characters - 1] = '\0';
			--characters;
		}	
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(0);
		}
/**		
 *		printf("%ld characters read \n", characters);
 *		printf("your command is %s \n", buffer);
 */
		token_array = split_string(buffer, WHITESPACE, &num_tokens);
/**		
 *		print_tokens(token_array, num_tokens);
 */		
		argv = (char **)malloc(sizeof(char *) * (num_tokens + 1));
		if (!argv)
		{
			fprintf(stderr, "Memory allocation error.\n");
			exit(1);
		}

		for (i = 0; i < num_tokens; i++)
			argv[i] = strdup(token_array[i]);
		argv[num_tokens] = NULL;
		real_command = find_command(argv[0]);
		if (real_command != NULL)
		{
			execute_input(argv);
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
		}

		free_tokens(token_array, num_tokens);
		free(argv);
	}
	free(buffer);
	return (0);
}
