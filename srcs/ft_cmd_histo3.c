/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_histo3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:21:17 by macbookpro        #+#    #+#             */
/*   Updated: 2021/04/21 20:37:17 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ctrl_d(char *a)
{
	a[0] = '\n';
	rm_del2();
	g_all.ctrl_d = 1;
	g_all.arrow = 5;
}
