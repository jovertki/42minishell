/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:02:53 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/19 22:06:22 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(char **envp)
{
	int i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

char	**get_env(const char **envp)
{
	char **out;
	int i;

	i = 0;
	while(envp[i])
		i++;
	out = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while(envp[i])
	{
		out[i] = ft_strdup(envp[i]);
		i++;
	}
	out[i] = NULL;
	return (out);
}
