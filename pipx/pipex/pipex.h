/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:39:33 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/18 11:51:24 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "Libft/libft.h"

void	code_exit(int nbr);
void	ft_exe(char *cmd, char **path);
void	parent_process(char **av, int *fd, char **path);
void	child_process(char **av, int *fd, char **path);
int		get_file(char *file_name, int instruction);
char	*find_var(char *cmd, char **path);
char	*get_path(char **path, char *good_line);
void	full_free(char **tab);



#endif