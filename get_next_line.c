/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:39:33 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/27 23:00:33 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

char	*get_next_line(int fd)
{
	static t_fdnode	file;
	char			*buf;
	char			*tmp;
	int				ret;

	buf = NULL;
	tmp = NULL;
	ret = 1;
	while (strline(file.stash) == -1 && ret != 0)
	{
		buf = malloc(sizeof(char) * (5));
		if (buf == NULL)
			return (gnl_free(&file.stash, &buf, &tmp));
		ret = read(fd, buf, 5);
		if (ret == -1)
			return (gnl_free(&file.stash, &buf, &tmp));
		buf[ret] = '\0';
		tmp = file.stash;
		file.stash = gnl_join(file.stash, buf);
		if (file.stash == NULL)
			return (gnl_free(&file.stash, &buf, &tmp));
		free(tmp);
		free(buf);
	}
	return (extract_parse(&file));
}

char	*extract_parse(t_fdnode *file)
{
	int		lb;
	char	*tmp;
	char	*res;

	lb = strline(file->stash);
	if (lb >= 0)
	{
		res = slice(file->stash, 0, lb + 1);
		tmp = file->stash;
		file->stash = slice(file->stash, lb + 1, (ft_strlen(file->stash) - (lb
						+ 1)));
		free(tmp);
		return (res);
	}
	else
	{
		res = NULL;
		if (file->stash[0] != '\0' || !file->stash)
			res = slice(file->stash, 0, (ft_strlen(file->stash)));
		free(file->stash);
		file->stash = NULL;
		return (res);
	}
}

char	*gnl_free(char **stash, char **buf, char **tmp)
{
	free(*stash);
	free(*buf);
	free(*tmp);
	*stash = NULL;
	*buf = NULL;
	*tmp = NULL;
	return (NULL);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (0);
// }