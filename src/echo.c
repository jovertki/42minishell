/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:09:55 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/08 16:24:31 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **str)//add pipes via whatever means
{
	int i;

	if (ft_strncmp(str[1], "-n\0", 3))
		i = 1;
	else
		i = 2;
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!(ft_strncmp(str[1], "-n\0", 3)))
		ft_putchar_fd('\n', 1);
}
