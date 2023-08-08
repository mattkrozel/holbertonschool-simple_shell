#include "main.h"
/**
 * main - shell that executes user input as commannds
 * @ac: argument count
 * @argv: argument
 * @env: path
 */
int main(int ac, char **argv, char **env)
{
	size_t buffsize = BUFF_SIZE;
	char *buffer = NULL, **token_array;
	ssize_t characters;
	int num_tokens, i;
	char *real_command;
	(void)ac;

	while (1)
	{
		/* displays prompt */
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		/* reads users input */
		characters = getline(&buffer, &buffsize, stdin);
		/* ctrl+D */
		if (characters == EOF)
		{
			if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		/* ctrl+c */
		signal(SIGINT, handle);
		/* checks empty input */
		if (characters == 1 && buffer[0] == '\n')
		{
			continue;
		}
		/* removes newline if present */
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
		if (strcmp(buffer, "env") == 0)
			print_enviro(env);
		/* tokenizes buffer */
		token_array = split_string(buffer, WHITESPACE, &num_tokens);
		free(buffer);
		/* allocating memory for argv and then passing tokens into */
		argv = (char **)malloc(sizeof(char *) * (num_tokens + 1));
		if (!argv)
		{
			fprintf(stderr, "Memory allocation error.\n");
			exit(1);
		}
		for (i = 0; i < num_tokens; i++)
			argv[i] = strdup(token_array[i]);
		argv[num_tokens] = NULL;
		/* finding command path */
		real_command = find_command(argv[0]);
		if (real_command != NULL)
		{
			execute_input(argv);
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", argv[0]);
		}
		free(argv);
		free_tokens(token_array, num_tokens);
		fflush(stdin);
		buffer = NULL, buffsize = 0;
	}
	/* free buffer before exit */
	free(buffer);
	return (EXIT_SUCCESS);
}
/**
 * handle - signal handler for ctrl+c
 * @signals: signal
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n$ ", 2);
}
