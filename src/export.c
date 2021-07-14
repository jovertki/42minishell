/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:54:16 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/14 18:08:16 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_env(char **envp, char *str, int mode)
{	
	int i;

	i = 0;
	while (ft_strncmp(envp[i], str, ft_strlen(str)) && envp[i])
		i++;
	if (envp[i] == NULL)
		return (NULL);
	else if (mode == 0)
		return (&envp[i][ft_strlen(str)]);
	else
		return (envp[i]);
}

void	print_line(char *minp, int len)
{
	char str[len + 15];
	int i;
	int j;

	ft_bzero(str, len + 15);
	ft_strlcpy(str, "export -x ", len + 15);
	i = 10;
	j = 0;
	while (minp[j] != '=')
	{
		str[i] = minp[j];
		i++;
		j++;
	}
	str[i] = minp[j];
	i++;
	j++;
	str[i] = '\"';
	i++;
	while (minp[j])
	{
		str[i] = minp[j];
		i++;
		j++;
	}
	str[i] = '\"';
	i++;
	ft_putendl_fd(str, 1);
}

void	print_sorted_env(char **envp, int envplen)
{
	char *maxp;
	char *minp;
	char *prev_min;
	int i;
	int j;

	j = 0;
	i = 0;
	prev_min = NULL;
	maxp = NULL;


	i = 0;
	while (i < envplen)
	{
		if (maxp == NULL || (ft_strncmp(maxp, envp[i], max(ft_strlen(envp[i]), ft_strlen(maxp))) < 0))
			maxp = envp[i];
		i++;
	}
	minp = maxp;
	i = 0;
	while(i < envplen)
	{
		j = 0;
		while (j < envplen)
		{
			if ((minp == NULL) || (ft_strncmp(minp, envp[j], max(ft_strlen(envp[j]), ft_strlen(minp))) > 0 && \
				(prev_min == NULL || \
				ft_strncmp(prev_min, envp[j], max(ft_strlen(envp[j]), ft_strlen(prev_min))) < 0)))
				minp = envp[j];
			j++;
		}
		if (minp != NULL && minp[0] != '\0')
			print_line(minp, ft_strlen(minp));
		// if ((ft_strchr(minp, '=')) != NULL && *(ft_strchr(minp, '=') + 1) == '\0' && minp != NULL && minp[0] != '\0')
		// 	printf("export -x %s''\n", minp);
		// else if (minp != NULL && minp[0] != '\0')
		// 	printf("export -x %s\n", minp); //NAME="VALUE"    add ""
		prev_min = minp;
		minp = maxp;
		i++;
	}
}

char *find_var_name(char *str)
{
	int i;

	i = 0;
	while (str[i] != '=')
		i++;
	char *out;
	out = ft_substr(str, 0, i + 1);
	return (out);
}

void	ft_export(int argc, char **argv, char ***envp)
{
	int envplen;
	int i;
	char *name;
	i = 0;
	while ((*envp)[i])
		i++;
	envplen = i;
	if (argc == 1)
		print_sorted_env(*envp, envplen);
	else
	{
		//check var name for validity
	
		name = find_var_name(argv[1]);
		i = 0;
		while ((*envp)[i])
		{
			if (ft_strncmp((*envp)[i], name, ft_strlen(name)) == 0)
				break ;
			i++;
		}
		if ((*envp)[i] != NULL)
		{
			//update existing
			free((*envp)[i]);
			(*envp)[i] = ft_strdup(argv[1]);
		} else
		{
			//add new
			ft_crealloc(*(void**)envp, (i * sizeof(char *)), ((i)* sizeof(char *)));
			(*envp)[i] = ft_strdup(argv[1]);
			(*envp)[i + 1] = NULL;
		}
	}

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