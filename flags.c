/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:53:58 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/25 18:27:50 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	flag_init(t_form *flag)
{
	flag->simple = 0;
	flag->medium = 0;
	flag->complex = 0;
	flag->adaptive = 0;
	flag->bench = 0;
	flag->strategy = NULL;
	flag->disorder = 0;
	return ;
}

int	flag_check(t_form *flag, char **argv, int argc)
{
	int	i;

	i = 1;
	flag_init(flag);
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ps_strncmp(argv[i], "--simple", 8) == 0)
			flag->simple = 1;
		else if (ps_strncmp(argv[i], "--medium", 8) == 0)
			flag->medium = 1;
		else if (ps_strncmp(argv[i], "--complex", 9) == 0)
			flag->complex = 1;
		else if (ps_strncmp(argv[i], "--adaptive", 10) == 0)
			flag->adaptive = 1;
		else if (ps_strncmp(argv[i], "--bench", 7) == 0)
			flag->bench = 1;
		else
			return (-1);
		i++;
	}
	if (flag->simple + flag->medium + flag->complex + flag->adaptive > 1)
		return (-1);
	return (i);
}

int	write_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}
