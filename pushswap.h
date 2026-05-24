/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 21:54:34 by riwatana          #+#    #+#             */
/*   Updated: 2026/05/24 23:40:16 by riwatana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	long			value;
	int				index;
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

typedef struct s_command
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;

}					t_command;

char				**ps_split(char const *s, char c);
char				**make_grid(char **res, char const *s, char c);
void				free_all(char **res);
char				*fill_words(char const *s, int len);
int					word_count(char const *s, char c);
int					list_apply(t_stack *head, long num);
void				stack_init(t_stack *stack);
int					ps_lstadd_back(t_stack *head, t_node *new);
void				ft_lstclear(t_stack *head);
t_node				*node_new(long value);
int					ps_strncmp(char *s1, char *s2, int n);
void				flag_init(t_form *flag);
int					flag_check(t_form *flag, char **argv, int argc);
int					write_error(void);
long				ps_atol(const char *nptr);
int					parse_num(t_stack *head, char **argv, int argc, int pos);
int					check_duplicates(t_stack *head);
int					parse(t_stack *head, t_form *flag, int argc, char **argv);
long				calc_mistakes(t_stack *head, int size);
double				disorder(t_stack *head);
void				push(t_stack *to, t_stack *from);
void				reconnect_from(t_stack *from, t_node *node);
void				reconnect_to(t_stack *to, t_node *node);
void				push_a(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
void				push_b(t_stack *b, t_stack *a, t_command *command,
						t_form *flag);
void				reverse_rotate(t_stack *head);
void				reverse_rotate_a(t_stack *a, t_command *command,
						t_form *flag, int output);
void				reverse_rotate_b(t_stack *b, t_command *command,
						t_form *flag, int output);
void				rverse_rotate_both(t_stack *a, t_stack *b,
						t_command *command, t_form *flag);
void				rotate(t_stack *head);
void				rotate_a(t_stack *a, t_command *command, t_form *flag,
						int output);
void				rotate_b(t_stack *b, t_command *command, t_form *flag,
						int output);
void				rotate_both(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
void				swap(t_stack *head);
void				swap_a(t_stack *head, t_command *command, t_form *flag,
						int output);
void				swap_b(t_stack *head, t_command *command, t_form *flag,
						int output);
void				swap_both(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
void				assign_index(t_stack *a);
int					calc_index(t_stack *a, t_node *current);

double				disorder(t_stack *head);
long				calc_mistakes(t_stack *head, int size);
int					ps_strlen(char *str);
void				command_init(t_command *command);
void				count_command(t_command *command, char *type);
int					output_command(t_form *flag, t_command *command,
						char *type);
int					select_strategy(t_stack *a, t_stack *b, t_form *flag);
void				simple_sort(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
void				radix_sort(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
int					get_max_bits(int size);
int					calc_chunk_size(int n);
bool				find_pos(t_stack *b, int target);
void				push_chunks_to_b(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
void				sort_chunks_to_a(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
void				chunk_sort(t_stack *a, t_stack *b, t_command *command,
						t_form *flag);
