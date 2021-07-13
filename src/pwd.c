/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:27:58 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/13 19:45:50 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd()
{
	char str[PATH_MAX];
	if (getcwd(str, PATH_MAX) == NULL)
	{
		perror("pwd");
		return ;
	}
	ft_putendl_fd(str, 1);
}	
