/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:37 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/18 11:29:11 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	full_free(char **tab)
{
	int i; 
	i = 0; 
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
}

char	*get_path(char **path, char *good_line) // trouve la bonne ligne;
{
	int i; 
	int j;
	char *res;

	i = 0;
	res = NULL;
	while (path[i])
	{
		j = 0;
		while (path[i][j] && path[i][j] != '=')
			j++;
		if(ft_strcmp(ft_substr(path[i], 0, j), good_line) == 0)
		{
			res = ft_strdup(ft_substr(path[i], 0, j));
			return (res); // peut être manque un free ici
		}
		i++;
	}
	return (res);
}

char	*find_var(char *cmd, char **path) // rend arg1 de excve
{
	char **l_path;
	char *line;
	char *var;
	char **t_cmd;
	int i;

	l_path = ft_split(get_path(path, "PATH"), ':'); // recupère PATH et convert into tab of tab
	line = NULL;
	var = NULL;
	t_cmd = ft_split(cmd, ' ');
	i = 0;
	while (path[i])
	{
		line = ft_strjoin(path[i], "/");
		var = ft_strjoin(line,t_cmd[0]);
		free(line);
		if (access(var, F_OK | X_OK) == 0)
		{
			full_free(l_path);
			return (var);
		}
		free(var);
		i++;
	}
	return (NULL);
}

void	ft_exe(char *cmd, char **path)
{
	char **t_cmd;
	char *var;

	t_cmd = ft_split(cmd, ' ');
	var = find_var(t_cmd[0],path); // trouve le dir de la commande
	if (execve(var, t_cmd, path) == -1)
	{
		perror("Command not found");
		full_free(t_cmd);
		//free(var)
		exit(0);
	}
	
}	
void	code_exit(int nbr)
{
	if (nbr == 0)
	{
	perror("Wrong argument number !\n");		
	}
	else if (nbr == 1)
	{
		perror("Something went wrong with pid");
	}
	else if (nbr == 2)
	{
		perror("Get files Error");
	}
	exit(0);
}