/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_right_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:00:18 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/20 21:09:16 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *insert_home(char *var, int tild)
{
	char *new_var;
	char *home;
	
	home = getenv("HOME");

	new_var = ft_calloc(ft_strlen(var) + ft_strlen(home) + 10, sizeof(char));
	int i;
	i = 0;
	int j;
	while (i < tild)
	{
		new_var[i] = var[i];
		i++;
	}
	j = 0;
	while(home[j])
	{
		new_var[i] = home[j];
		i++;
		j++;
	}
	tild++;
	while (var[tild])
	{
		new_var[i] = var[tild];
		i++;
		tild++;
	}
	free(var);
	return(new_var);

}

void	interpret_tild(char **vars)
{
	int i;
	int j;

	i = 0;
	while(vars[i])
	{
		j = 0;
		while(vars[i][j])
		{
			if (vars[i][j] == '~' && vars[i][j + 1] != '~')
			{
				vars[i] = insert_home(vars[i], j);
				j = 0;
			} else
				j++;
		}
		if (j > 0 && vars[i][j - 1] != '/')
			vars[i][j] = '/';
		i++;
	}
}

void add_program_name(char **variants, char **argv)
{
	int i;
	char *temp;
	i = 0;

	while (variants[i])
	{
		variants[i] = ft_strjoin_fb(variants[i], ft_strjoin("/", argv[0]));
		printf("'%s'\n", variants[i]);
		i++;
	}
}

void	search_right_bin(char **argv, char **envp)
{
	char **variants;
	char *temp;
	variants = ft_split(find_env(envp, "PATH=", 0), ':');

	int i = 0;
	if (variants)
	{
		interpret_tild(variants);
		add_program_name(variants, argv);
		while(variants[i])
		{
			execve(variants[i], argv, envp);
			i++;
		}
		execve(argv[0], argv, envp);
		i = 0;
		while (variants[i])
		{
			free(variants[i]);
			i++;
		}
		free(variants);
	}
	if ((ft_strchr(argv[0], '/') != '\0' && stat(argv[0], NULL) == -1))
	{
		temp = ft_strjoin_fs("minishell: ", ft_strjoin_ff(ft_strjoin(argv[0], ": "), strerror(errno)));
		ft_putendl_fd(temp, 2);
		free(temp);
	}
	else if (find_env(envp, "PATH=", 1) == NULL)
	{
		temp = ft_strjoin_fs("minishell: ", ft_strjoin(argv[0], ": command not found"));
		ft_putendl_fd(temp, 2);
		free(temp);
	} 
	else
	{
		temp = ft_strjoin_fs("minishell: ", ft_strjoin(argv[0], ": command not found"));
		ft_putendl_fd(temp, 2);
		free(temp);
	}
	
	                            //not final!!
	

	// i = 0;
	// while (variants[i])
	// {
	// 	printf("Line[%d] == '%s'\n", i, variants[i]);
	// 	i++;
	// }



	//FREE ALL VARIANTS NOT NEEDEDE HERE

}