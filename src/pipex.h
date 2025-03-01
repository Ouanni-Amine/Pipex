/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:02:25 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 15:59:40 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	cleanup_exit(char *v1, char **v2, char **v3, int exit_code);
void	ft_free_split(char **str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	dup_fd(char	*file, int pipe_fd1);
void	dup_fd2(char *file, int pipe_fd0);
int		check_path(char **env, char **cmd_args);
char	*command_with_path(char **cmd_args, int exit);
char	*command_without_path2(char **args, char **solo, char *cmd_s, int exit);
char	*command_without_path(char **env, char **cmd_args, int exit);
void	handle_first_command(int *pipe_fd, char **v, char **env);
void	handle_second_command(int *pipe_fd, char **v, char **env);
char	*ft_strchr(const char *s, int c);

#endif
