/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:01:34 by jungchoi          #+#    #+#             */
/*   Updated: 2022/05/17 16:10:22 by jungchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int fd;
	char *file_path;
	char *line;

	file_path = "text.txt";
	fd = open(file_path, O_RDONLY);

	while ((line = get_next_line(fd)) !=  NULL)
	{
		printf("%s\n", line);
		printf("%s\n", line);
		printf("%s\n", line);
		free(line);
	}
	system("leaks a.out");
}
