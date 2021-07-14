/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:02:53 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/14 18:12:30 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(char **envp)
{
	int i = 0;
	while (envp[i])
	{
		if (envp[i][0] != '\0')
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
