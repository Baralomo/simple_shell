#include "shell.h"


int main(int argc, char *argv[], char **envp)
{
	char line[MAX_LINE];
	char *path = "/bin/";
	char progpath[20];
	int child;

	while (1)
	{
		printf("simple_shell> ");

		if (!fgets(line, MAX_LINE, stdin))
		{
			printf("\n");
			exit(0);
		}

		size_t length = strlen(line);

		if (line[length - 1] == '\n')
			line[length - 1] = '\0';

		strcpy(progpath, path);
		strcat(progpath, line);
		for (int i = 0; i < strlen(progpath); i++)
			if (progpath[i] == '\n')
				progpath[i] = '\0';

		child = fork();
		if (child == 0)
		{
			if (execve(progpath, NULL, envp) == -1)
			{
				perror("Error:");
			}
		} else
			wait(NULL);
	}

	return (0);
}
