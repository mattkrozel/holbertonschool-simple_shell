#include "main.h"

/**
 * function to execute given command 
 * @param argv: a pointer to a list of args where argv[0] is command to be executed 
 **/

void execute_input(char **argv)
{
	char *command = NULL, *real_command = NULL;
	pid_t pid;
	int status, error_wait = 0;

	/* check if args are provided */
	if (argv)
	{
		/* extract command from arg list */
		command = argv[0];
		/* find full path of the command if exists */
		real_command = find_command(command);
		
		/* create new process */
		pid = fork();
		if (pid < 0) /* check for fork error */
		{
			perror("Error: ");
			free(real_command);
		}
		if (pid == 0) /* child process execute command */
		{
			execve(real_command, argv, NULL);
			free(real_command);
		}
		else /* parent process wait for child */
		{
			error_wait = waitpid(pid, &status, 0);
			if (error_wait < 0)
			{
				free(real_command);
			}
			free(real_command);
		}
	}
}

void print_enviro(char **env)
{
	size_t i = 0, length = 0;

	while (env[i]) /* iterate over list of enviro variables and print each */
	{
		length = strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
