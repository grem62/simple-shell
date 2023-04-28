#include "main.h"

/**
 *main - entry point
 *Return: return void
*/

int main(void)
{
	char *line;
	char **tokens = NULL;
	
	while (true) /*Boucle while infinie*/
	{
		if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "$ ", 1);

		line = sshell_read_line();/*Lire la ligne d'entrée de l'utilisateur*/

		if (line == NULL)
		{
			continue;
		}
		tokens = sshell_split_line(line);/*spliter ligne d'entrée*/

		if (tokens == NULL)
		{
			continue;
		}

		if (tokens[0] != NULL)
		{
			shell_exec(tokens);/*Exécuter la commande avec shell_exec*/
		}

		free(tokens);/*Libérer la mémoire allouée pour "tokens"*/
	}
}
