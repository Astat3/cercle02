/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:47:44 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/22 22:06:07 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

# define READ 0
# define WRITE 1

/*recuperer la bonne ligne -> puis trouver le dir qui contient la commande*/

/*./pipex infilea "ls -l" "wc -l" outfile*/

void	ft_exe(char *cmd, char **path)
{
	char **t_cmd;
	char *var;

	t_cmd = ft_split(cmd, ' ');
	var = find_var(cmd, path);// trouve le dir de la commande
	if (var == NULL)
	{
		perror("Command not found");
		full_free(t_cmd);
		exit(127);
	}
	if (execve(var, t_cmd, path) == -1)
	{
		perror("Execve failed");
		full_free(t_cmd);
		free(var);
		exit(1);
	}
}	

int	get_file(char *file_name, int instruction)
{
	int fd;

	fd = 0;
	if (instruction == WRITE)
	{
		fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	}
	if (instruction == READ)
	{
		fd = open(file_name, O_RDONLY, 0777);
	}
	if (fd == -1)
	{
		code_exit(2);
	}
	return (fd);
}

void	child_process(char **av, int *fd, char **path)
{
	int fd_child;
	
	fd_child = get_file(av[1], READ);
	// change 3 avec STDIN -> recupère input
	dup2(fd_child, STDIN_FILENO); 
	close(fd_child);
	// renvoi l'output dans le Pip au lieu du STDOUT
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[READ]);
	close(fd[WRITE]);
	ft_exe(av[2], path);
}

/*./pipex infilea "ls -l" "wc -l" outfile*/
/*< infile.txt ls -l | wc -l outfile*/
void	parent_process(char **av, int *fd, char **path)
{
	int fd_parent;

	fd_parent = get_file(av[4], WRITE);
	dup2(fd_parent, STDOUT_FILENO);
	dup2(fd[READ], STDIN_FILENO);
	close(fd_parent);
	close(fd[READ]);
	close(fd[WRITE]);
	ft_exe(av[3], path);
}

int main(int ac, char **av, char **path)
{
	int fd[2];
	pid_t pid;

//verif des arguments;
    printf("ceci est un test du clavier qui semble parfaitment fonctionner");
    if (ac != 5)
		code_exit(0);
	if (pipe(fd) == -1)
		code_exit(1);
// creating child process;
	pid = fork();
	if (pid == 0)
		child_process(av,fd, path);
	else
	{
		parent_process(av,fd, path);
	}
    return 0;
}