/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:39:33 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/24 12:04:34 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	code_exit(int nbr);
void	ft_exe(char *cmd, char **path);
void	parent_process(char **av, int *fd, char **path);
void	child_process(char **av, int *fd, char **path);
int		get_file(char *file_name, int instruction);
char	*find_var(char *cmd, char **path);
char	*get_path(char **path, char *good_line);
void	full_free(char **tab);

/*LIBFT*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

char	*find_check_var(char **l_path, char *line, char *var, char **t_cmd);

#endif