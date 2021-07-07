/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:02:53 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/07 22:36:36 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(t_all *all)
{
	int i = 0;
	while (all->env[i])
	{
		printf("%s\n", all->env[i]);
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
	out = ft_calloc(i, sizeof(char *));
	i = 0;
	while(envp[i])
	{
		out[i] = ft_calloc(ft_strlen(envp[i]) + 1, sizeof(char));
		ft_strcpy(out[i], envp[i]);
		i++;

	}
	out[i] = NULL;
	return (out);
}
