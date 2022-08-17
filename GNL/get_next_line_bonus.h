/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:13:50 by jungchoi          #+#    #+#             */
/*   Updated: 2022/05/17 15:59:06 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define OPEN_MAX 256

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	free_ptr(char **ptr);
char	*ret_line(char **backup);
char	*cut_backup(char **backup);
char	*read_buff(int fd, char **backup);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strchr(char *s, char c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
