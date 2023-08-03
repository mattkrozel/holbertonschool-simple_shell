#include "main.h"

void execute_input(char **argv)
{
	char *command = NULL, *real_command = NULL;
	
	if (argv)
	{
		command = argv[0];
		real_command = find_command(command);
		
		if (execve(real_command, argv, NULL) == -1)
		{
			perror("Error");
			return;
		}
	}
}
