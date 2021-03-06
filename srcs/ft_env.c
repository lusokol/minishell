/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:04:36 by pacorrei          #+#    #+#             */
/*   Updated: 2021/04/07 15:41:16 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_env_builtins(t_elem_env *tmp)
{
	int			verif;
	int			i;

	verif = 0;
	i = 0;
	while (tmp != NULL)
	{
		while (tmp->env[i] != '\0')
		{
			if (tmp->env[i] == '=')
				verif = 1;
			i++;
		}
		if (verif == 1)
		{
			ft_putstr(tmp->env);
			ft_putchar('\n');
		}
		i = 0;
		verif = 0;
		tmp = tmp->next;
	}
}

int		ft_env(t_elem_cmd *actual)
{
	t_elem_env	*tmp;

	tmp = g_all.first_env;
	if (actual->next != NULL && actual->next->token == ARG)
	{
		ft_putstr_fd("Wrong argument\n", 2);
		return (1);
	}
	print_env_builtins(tmp);
	return (0);
}
