/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:30:52 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/09 23:01:51 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_env(char **envp, char *str)
{	
	int i;

	i = 0;
	while (ft_strncmp(envp[i], str, ft_strlen(str)) && envp[i])
		i++;
	if (envp[i] == NULL)
		return (NULL);
	else
		return (&envp[i][ft_strlen(str)]);
}


void	remove_last(char *str)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while(str[i])
	{
		if (str[i] == '/')
			index = i;
		i++;
	}
	if (index != 0)
		str[index] = '\0';
}

void	add_last(char **buf_pwd, char *str)
{
	size_t old_len;
	size_t new_len;
	old_len = ft_strlen(*buf_pwd);
	new_len = old_len + ft_strlen(str) + 1;
	printf("TROOOOOL\n");
	ft_crealloc(*(void**)buf_pwd, old_len, new_len);
	printf("TROOOOOL\n");

	int i;
	i = 0;
	while (str[i])
	{
		*buf_pwd[old_len] = str[i];
		i++;
		old_len++;
	}
}

void	apply_changes(char **split_arg, char **buf_pwd)
{
	int	i;

	i = 0;
	while (split_arg[i])
	{
		if (ft_strncmp(split_arg[i], ".\0", 2) == 0)
		{}
		else if (ft_strncmp(split_arg[i], "..\0", 3) == 0)
			remove_last(*buf_pwd);
		else
		{
			printf("bufp = %p\n", buf_pwd);
			add_last(buf_pwd, split_arg[i]);
			
		}
		i++;
	}
	printf("buf_pwd = '%s'\n", *buf_pwd);
}

void	cd(char **argv, char **envp)
{
	char *str;
	char *buf_pwd;
	char **split_arg;

	if (argv[1] == 0)
		str = find_env(envp, "HOME=");
	else
		str = argv[1];
	if (str == NULL || str[0] == '\0')
	{} //DO SOME STUFF IF HOME IS BULLSHIT
	buf_pwd = find_env(envp, "PWD=");
	//CHECK PWD FOR BULLSHIT
	//DO SOME STUFF IF PWD IS NULL or BULLSHIT
	split_arg = ft_split(str, '/');

	apply_changes(split_arg, &buf_pwd);
	// int i = 0;
	// while (split_arg[i])
	// {
	// 	printf("[%d] = '%s'\n", i, split_arg[i]);
	// 	i++;
	// }

	
}
