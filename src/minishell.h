/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:26:58 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/12 17:53:18 by jovertki         ###   ########.fr       */
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
# include <sys/stat.h>

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
void	env(char **envp);
char	**get_env(const char **envp);
void	echo(char **str);
void	execute(t_commandtable *ct, char **envp);
void	cd(char **argv, char **envp);
#endif