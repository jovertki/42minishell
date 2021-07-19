/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 20:19:24 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/19 20:55:04 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **create_new_envp(char **envp, char *temp)
{
	int i;
	int j;
	char **new_envp;
	
	i = 0;
	while ((envp)[i])
		i++;
	new_envp = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (envp[i] != temp)
		{
			new_envp[j] = ft_strdup(envp[i]);
			j++;
		}
		i++;
	}
	i = 0;
	while (envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
	new_envp[j] = NULL;
	return(new_envp);
}

void	ft_unset(int argc, char **argv, char ***envp)
{
	char *temp = NULL;
	char *temp_name;
	temp = find_env(*envp, argv[1], 1);
	if (temp == NULL)
	{
		temp_name = ft_strjoin(argv[1], "=");
		temp = find_env(*envp, argv[1], 1);
		free(temp_name);
		if (temp == NULL)
			return ;
		else
			*envp = create_new_envp(*envp, temp);
	}
	else
		*envp = create_new_envp(*envp, temp);
}