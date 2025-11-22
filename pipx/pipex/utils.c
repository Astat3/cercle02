/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:37 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/22 19:14:01 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
void	full_free(char **tab)
{
	int i; 
	i = 0; 
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_sstrlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return i;
}

char	*get_path(char **path, char *good_line) // trouve la bonne ligne;
{
	int i; 
	int j;
	char *res;
	char *temp;

	i = 0;
	res = NULL;
	while (path[i])
	{
		j = 0;
		while (path[i][j] && path[i][j] != '=')
			j++;
		temp = ft_substr(path[i], 0, j);
		if (ft_strcmp(temp, good_line) == 0)
		{
			free(temp);
			res = ft_strdup(path[i] + j + 1);
			return (res);
		}
		free(temp);
		i++;
	}
	return (NULL);
}

char	*find_var(char *cmd, char **path) // rend arg1 de excve
{
	char **l_path;
	char *line;
	char *var;
	char **t_cmd;
	int i;

	l_path = ft_split(get_path(path, "PATH"), ':'); // recupère PATH et convert into tab of tab
	if (!l_path || !l_path[0])
		return (NULL);
	line = NULL;
	var = NULL;
	t_cmd = ft_split(cmd, ' ');
	if (access(cmd, F_OK | X_OK) == 0)
	{
		return cmd;
	}
	i = 0;
	while (l_path[i])
	{
		line = ft_strjoin(l_path[i], "/");
		var = ft_strjoin(line, t_cmd[0]);
		free(line);
		if (access(var, F_OK | X_OK) == 0)
		{
			full_free(l_path);
			full_free(t_cmd);
			return (var);
		}
		free(var);
		i++;
	}
	full_free(l_path);
	full_free(t_cmd);
	return (NULL);
}