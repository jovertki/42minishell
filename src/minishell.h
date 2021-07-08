/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:26:58 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/08 20:57:38 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_command
{
	int input;
	int output;
	int error;
	char **argv;// NULL terminated
	int argc;// not nesessary
}t_command;

typedef struct s_commandtable
{
	char *infile;
	char *outfile;
	char *errfile;
	t_command *commands;
	int	num_of_commands;
} t_commandtable;


typedef struct s_all
{
	char **env;
}t_all;


void	pwd(char **envp);
void	env(t_all *all);
char	**get_env(const char **envp);
void	echo(char **str);
#endif