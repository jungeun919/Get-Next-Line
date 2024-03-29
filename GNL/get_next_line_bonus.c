/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:13:13 by jungchoi          #+#    #+#             */
/*   Updated: 2022/05/14 19:22:45 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ret_line(char **backup)
{
	char	*line;
	char	*temp;
	size_t	cut_idx;

	if (!(ft_strchr(*backup, '\n')))
	{
		temp = ft_strdup(*backup);
		return (temp);
	}
	cut_idx = 0;
	while ((*backup)[cut_idx] != '\n')
		cut_idx++;
	temp = ft_strdup(*backup);
	line = ft_substr(temp, 0, cut_idx + 1);
	free_ptr(&temp);
	return (line);
}

char	*cut_backup(char **backup)
{
	char	*temp;
	size_t	cut_idx;

	if (!(ft_strchr(*backup, '\n')))
	{
		free_ptr(backup);
		return (NULL);
	}
	cut_idx = 0;
	while (*((*backup) + cut_idx) != '\n')
		cut_idx++;
	temp = ft_substr(*backup, cut_idx + 1, ft_strlen(*backup) - cut_idx);
	free_ptr(backup);
	return (temp);
}

char	*read_buff(int fd, char **backup)
{
	char	*buff;
	char	*temp;
	ssize_t	read_size;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_size = 1;
	while (read_size && !(ft_strchr(*backup, '\n')))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free_ptr(&buff);
			free_ptr(backup);
			return (NULL);
		}
		buff[read_size] = '\0';
		temp = *backup;
		*backup = ft_strjoin(temp, buff);
		free_ptr(&temp);
	}
	free_ptr(&buff);
	return (*backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup[fd])
		backup[fd] = ft_strdup("");
	backup[fd] = read_buff(fd, &backup[fd]);
	if (!backup[fd])
		return (NULL);
	if (!backup[fd][0])
	{
		free_ptr(&backup[fd]);
		return (NULL);
	}
	line = ret_line(&backup[fd]);
	backup[fd] = cut_backup(&backup[fd]);
	return (line);
}
