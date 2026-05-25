/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:41:03 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/25 19:41:05 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ps_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ps_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (-1);
}

int	ps_putnbr_fd(int n, int fd)

{
	char a;

	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return (-1);
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		if (write(fd, "-", 1) == -1)
			return (-1);
	}
	if (n >= 10)
		ps_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	if (write(fd, &a, 1) == -1)
		return (-1);
	return (1);
}

int	ps_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (write(fd, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (1);
}
