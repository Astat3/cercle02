/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:47:44 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/18 11:29:09 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

# define READ 0
# define WRITE 1

/*recuperer la bonne ligne -> puis trouver le dir qui contient la commande*/

/*./pipex infilea "ls -l" "wc -l" outfile*/



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
	if (instruction == -1)
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
	dup2(fd_child, READ); 
	close(fd_child);
	// renvoi l'output dans le Pip au lieu du STDOUT
	dup2(fd[WRITE], WRITE);
	ft_exe(av[2], path);
}

/*./pipex infilea "ls -l" "wc -l" outfile*/
/*< infile.txt ls -l | wc -l outfile*/
void	parent_process(char **av, int *fd, char **path)
{
	int fd_parent;

	fd_parent = get_file(av[4], WRITE);
	dup2(fd_parent, WRITE);
	dup2(fd[READ], READ);
	close(fd_parent);
	ft_exe(av[3], path);
}

int main(int ac, char **av, char **path)
{
	int fd[2];
	pid_t pid;

//verif des arguments;
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