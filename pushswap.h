/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:54:34 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/20 19:28:36 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	long			value;
	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;

}					t_stack;

typedef struct s_form
{
	int				simple;
	int				medium;
	int				complex;
	int				adaptive;
	int				bench;

}					t_form;

char				**ps_split(char const *s, char c);
char				**make_grid(char **res, char const *s, char c);
void				free_all(char **res, int row_num);
char				*fill_words(char const *s, int len);
int					word_count(char const *s, char c);
int					list_apply(t_stack *head, long num);
void				stack_init(t_stack *stack);
int					ps_lstadd_back(t_stack *head, t_node *new);
void				ft_lstclear(t_stack *head);
t_node				*node_new(t_stack *head, long value);