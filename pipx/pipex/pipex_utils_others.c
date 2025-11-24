/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_others.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:49 by agallot           #+#    #+#             */
/*   Updated: 2025/11/24 12:04:21 by agallot          ###   ########.fr       */
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
			full_free(l_path);
			full_free(t_cmd);
			return (var);
		}
		free(var);
		i++;
	}
	return (NULL);
}
