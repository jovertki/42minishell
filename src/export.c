/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:54:16 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/13 21:25:59 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(int argc, char **argv, char ***envp)
{
	int envplen;
	int i;

	i = 0;
	while ((*envp)[i])
		i++;
	envplen = i;
	ft_crealloc(*(void**)envp, (i * sizeof(char *)), ((i + 1)* sizeof(char *)));
	(*envp)[i] = ft_strdup(argv[1]);
	(*envp)[i + 1] = NULL;


//	printf("envp[%d] = '%s'\n", i, (*envp)[i]);
	// i = 0;
	// while (envp[i])
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
	// printf("--------------------------\n");
	// env(envp);
	// printf("--------------------------\n");
}