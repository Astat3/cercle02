/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_others.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:49 by agallot           #+#    #+#             */
/*   Updated: 2025/12/08 19:15:18 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_check_var(char **l_path, char *line, char *var, char **t_cmd)
{
	int	i;

	i = 0;
	while (l_path[i])
	{
		line = ft_strjoin(l_path[i], "/");
		var = ft_strjoin(line, t_cmd[0]);
		free(line);
		if (access(var, F_OK | X_OK) == 0)
		{
			return (var);
		}
		free(var);
		i++;
	}
	return (NULL);
}
