/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_histo2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:47:13 by macbookpro        #+#    #+#             */
/*   Updated: 2021/04/15 14:38:12 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cmd_add_back(t_elem_env *new)
{
	t_elem_env *tmp;

	if (!new)
		return ;
	new->next = NULL;
	if (g_all.cmd_lst)
	{
		tmp = g_all.cmd_lst;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	else
		g_all.cmd_lst = new;
}

void	cmd_rm_last(void)
{
	t_elem_env *tmp;
	t_elem_env *prev;

	tmp = g_all.cmd_lst;
	prev = tmp;
	if (!tmp)
		return ;
	else
	{
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp != prev)
		{
			prev->next = NULL;
			free(tmp->env);
			free(tmp);
			return ;
		}
		free(g_all.cmd_lst->env);
		free(g_all.cmd_lst);
		g_all.cmd_lst = NULL;
	}
}

void	insertion_end_lst(char *str)
{
	t_elem_env *nouveau;

	nouveau = malloc(sizeof(t_elem_env));
	nouveau->env = ft_strdup(str);
	cmd_add_back(nouveau);
}

int		lst_len(void)
{
	t_elem_env	*tmp;
	int			i;

	tmp = g_all.cmd_lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	check_arrow2(int i, char *a)
{
	g_all.cursor = (i == 2 && (a[0] == 'C' || a[0] == 'D')) ? g_all.cursor
	: g_all.cursor + 1;
	g_all.cursor_x = (i == 2 && (a[0] == 'C' || a[0] == 'D')) ?
	g_all.cursor_x : g_all.cursor_x + 1;
	if (i == 2 && (a[0] == 'C' || a[0] == 'D'))
	{
		rm_del2();
		rm_del2();
		a[0] = '\n';
		g_all.arrow = 4;
	}
}
