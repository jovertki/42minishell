/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:27:58 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/20 21:18:13 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd()
{
	char str[PATH_MAX];
	char *temp;
	if (getcwd(str, PATH_MAX) == NULL)
	{
		temp = ft_strjoin("pwd: ", strerror(errno));
		ft_putendl_fd(temp, 2);
		free(temp);
		return ;
	}
	ft_putendl_fd(str, 1);
}	
