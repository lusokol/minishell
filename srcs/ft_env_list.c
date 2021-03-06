/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:04:36 by pacorrei          #+#    #+#             */
/*   Updated: 2021/04/07 15:41:03 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	insertion_end_env(char *str)
{
	t_elem_env *nouveau;
	t_elem_env *tmp;

	nouveau = malloc(sizeof(t_elem_env));
	tmp = g_all.first_env;
	nouveau->env = str;
	if (tmp->next == NULL)
	{
		tmp->next = nouveau;
		nouveau->next = NULL;
		nouveau->prev = g_all.first_env;
		return ;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = nouveau;
	nouveau->next = NULL;
	nouveau->prev = tmp;
}

void	initialisation_env(char *str)
{
	t_elem_env *nouveau;

	nouveau = malloc(sizeof(t_elem_env));
	nouveau->env = str;
	nouveau->next = NULL;
	nouveau->prev = NULL;
	g_all.first_env = nouveau;
}

int		check_env_exist(char *str)
{
	t_elem_env *tmp;

	tmp = g_all.first_env;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->env, str, ft_strlen(str)) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	check_min_env(void)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd && errno == 2)
		ft_putstr_fd("Error when trying to enable a default pwd.\n", 2);
	if (!check_env_exist("PATH"))
		insertion_end_env(ft_strdup("PATH=/bin:/usr/bin"));
	if (!check_env_exist("HOME"))
		insertion_end_env(ft_strdup("HOME="));
	if (!check_env_exist("OLDPWD"))
		insertion_end_env(ft_strdup("OLDPWD="));
	if (!check_env_exist("PWD") && pwd)
		insertion_end_env(ft_strjoin(ft_strdup("PWD="), ft_strdup(pwd)));
	if (!check_env_exist("SHLVL"))
		insertion_end_env(ft_strdup("SHLVL=1"));
	if (pwd)
		free(pwd);
}

void	init_liste_env(char **envp)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup(envp[0]);
	initialisation_env(tmp);
	while (envp[i] != NULL)
	{
		tmp = ft_strdup(envp[i]);
		insertion_end_env(tmp);
		i++;
	}
	check_min_env();
}
