/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:39:49 by jungchoi          #+#    #+#             */
/*   Updated: 2022/05/17 16:01:55 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	char	*join;
	size_t	count;

	if (!s1 || !s2)
		return (0);
	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(sizeof(char) * count);
	if (!ret)
		return (0);
	join = ret;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (ret);
}

size_t	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		size;
	char	*s2;

	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;
	size_t	i;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (slen == 0 || len == 0 || slen <= start)
		return (0);
	if (slen < start + len)
		len = slen - start;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	s = s + start;
	i = 0;
	while (*s)
	{
		if (i < len)
			ret[i++] = *s;
		s++;
	}
	ret[i] = '\0';
	return (ret);
}
