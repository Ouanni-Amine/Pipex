/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouanni <aouanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:31:47 by aouanni           #+#    #+#             */
/*   Updated: 2025/02/26 16:26:06 by aouanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *accumilator)
{
	char		*buffer;
	ssize_t		bytes_read;
	char		*old_accumilator;

	bytes_read = 1;
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (buffer == NULL)
		return (free(accumilator), NULL);
	while (bytes_read > 0)
	{
		if (ft_strchr_gnl(accumilator, '\n') == 1)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(accumilator), NULL);
		buffer[bytes_read] = '\0';
		old_accumilator = accumilator;
		accumilator = ft_strjoin(accumilator, buffer);
		free(old_accumilator);
	}
	free(buffer);
	if (bytes_read == 0 && accumilator == NULL)
		return (NULL);
	return (accumilator);
}

char	*ft_extractline(char *accumulator)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (accumulator[i] == '\0')
		return (NULL);
	while (accumulator[i] != '\n' && accumulator[i] != '\0')
		i++;
	if (accumulator[i] == '\n')
		i++;
	line = ft_substr(accumulator, 0, i);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*ft_updateline(char *accumulator, char *line)
{
	char	*new_accumulator;
	int		i;

	new_accumulator = NULL;
	i = ft_strlen(line);
	new_accumulator = ft_substr(accumulator, i, ft_strlen(accumulator));
	free(accumulator);
	return (new_accumulator);
}

char	*get_next_line(int fd)
{
	static char	*accumulator;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulator = ft_readline(fd, accumulator);
	if (accumulator == NULL)
		return (NULL);
	line = ft_extractline(accumulator);
	if (line == NULL)
		return (free(accumulator), accumulator = NULL);
	accumulator = ft_updateline(accumulator, line);
	return (line);
}
