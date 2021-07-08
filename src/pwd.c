/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:27:58 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/08 20:58:15 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **envp)
{
	int i;
	i = 0;

	while (envp[i])
	{
		if ((ft_strncmp(envp[i], "PWD=", 4)) == 0)
			break ;
		i++;
	}
	char *temp;
	temp = ft_substr(envp[i], 4, ft_strlen(envp[i]) - 4);
	printf("%s\n", temp);
	free(temp);
}
