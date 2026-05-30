/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:54:34 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/30 20:56:19 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H
# include "pushswap.h"

typedef struct s_fdnode
{
	int		fd;
	char	*stash;
}			t_fdnode;

char		*get_next_line(int fd);
char		*slice(char *s, int start, int size);
char		*gnl_join(char *s1, char *s2);
int			ft_strlen(char *str);
int			strline(char *s);
char		*extract_parse(t_fdnode *file);
char		*gnl_free(char **stash, char **buf, char **tmp);
int			parse_bonus(t_stack *head, int argc, char **argv);
int			sort_check_bonus(t_stack *a);
void		command_dispatch(char *command, t_stack *a, t_stack *b);
void		swap_both_bonus(t_stack *a, t_stack *b);
void		rotate_both_bonus(t_stack *a, t_stack *b);
void		reverse_rotate_both_bonus(t_stack *a, t_stack *b);

#endif
