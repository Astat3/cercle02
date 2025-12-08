/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:28:37 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/08 19:18:52 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	code_exit(int nbr)
{
	if (nbr == 0)
	{
		ft_putstr_fd("Wrong argument number !\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (nbr == 1)
	{
		ft_putstr_fd("Something went wrong with pid", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (nbr == 2)
	{
		ft_putstr_fd("Get files Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_FAILURE);
}

void	full_free(char **tab)
{
	int	i;

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
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*get_path(char **path, char *good_line)
{
	int		i;
	int		j;
	char	*res;
	char	*temp;

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

char	*find_var(char *cmd, char **path)
{
	char	**l_path;
	char	*line;
	char	*var;
	char	**t_cmd;
	char	*path_str;

	path_str = get_path(path, "PATH");
	l_path = ft_split(path_str, ':');
	free(path_str);
	line = NULL;
	var = NULL;
	t_cmd = ft_split(cmd, ' ');
	if (access(cmd, F_OK | X_OK) == 0)
	{
		full_free(l_path);
		full_free(t_cmd);
		return (ft_strdup(cmd));
	}
	var = find_check_var(l_path, line, var, t_cmd);
	full_free(l_path);
	full_free(t_cmd);
	return (var);
}
