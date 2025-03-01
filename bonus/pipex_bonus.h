/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:35:07 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 16:25:43 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../GNL/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		prev_fd;
	int		output_fd;
	int		input_fd;
	int		pipe_fd[2];
	int		pid;
	int		nb_cmd;
	int		cmd_start;
	int		heredoc;
	char	**env;
	char	**v;
	int		c;
	int		last_pid;
}	t_pipex;

void	valid_input(int c, int num);
int		heredoc_check(char *str);
int		heredoc_inputfd(char **v);
int		heredoc_outputfd(char **v, int c);
int		normal_outputfd(char **v, int c );
int		normal_inputfd(char **v, int *pipe_fd);
void	cleanup_exit_process(int *pipe_fd, int prev_fd, int pipe_created);
void	first_process_input(t_pipex *data);
void	other_process_input(t_pipex *data, int i);
void	last_process_output(t_pipex *data);
void	other_process_output(t_pipex *data);
void	execute_cmd(char *cmd, char **env, int is_last_cmd);
void	cleanup_exit(char *v1, char **v2, char **v3, int exit_code);
int		check_path(char **env, char **cmd_args);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_free_split(char **str);
char	*ft_strchr(const char *s, int c);

#endif
