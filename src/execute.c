/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:42:11 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/20 19:55:23 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_not_builtin(char *str)
{
	int out;

	out = 1;
	if (ft_strncmp("echo\0", str, 5) == 0 || \
		ft_strncmp("cd\0", str, 3) == 0 || \
		ft_strncmp("pwd\0", str, 4) == 0 || \
		ft_strncmp("export\0", str, 7) == 0 || \
		ft_strncmp("unset\0", str, 6) == 0 || \
		ft_strncmp("env\0", str, 4) == 0 || \
		ft_strncmp("exit\0", str, 5) == 0)
		out = 0;
	return (out);
}

int execbuiltin(char *name, char **argv, int argc, char ***envp)
{
	if (ft_strncmp("echo\0", name, 5) == 0)
		echo(argv);
	else if (ft_strncmp("cd\0", name, 3) == 0)
		cd(argv, argc, envp);
	else if (ft_strncmp("pwd\0", name, 4) == 0)
		pwd(*envp);
	else if (ft_strncmp("export\0", name, 7) == 0)
		ft_export(argc, argv, envp);
	else if (ft_strncmp("unset\0", name, 6) == 0)
		ft_unset(argc, argv, envp);
	else if (ft_strncmp("env\0", name, 4) == 0)
		env(*envp);
	else if (ft_strncmp("exit\0", name, 5) == 0)
	{}
	return (0);
}

void execute(t_commandtable *ct, char ***envp)
{
	// save in/out
	int tmpin = dup(0);
	int tmpout = dup(1);
	//set the initial input 
	int fdin;
	if (ct->infile)
		fdin = open(ct->infile, O_RDONLY);
	else 
	{
		// Use default input
		fdin=dup(tmpin);
	}
	int ret = 0;
	int fdout;
	for (int i = 0; i < ct->num_of_commands; i++) 
	{
		//redirect input
		dup2(fdin, 0);
		close(fdin);
		//setup output
		if (i == ct->num_of_commands - 1)
		{
			// Last simple command 
			if(ct->outfile)
			{
			    fdout=open(ct->outfile, O_WRONLY);
			}
			else 
			{
				// Use default output
				fdout=dup(tmpout);
			}
		}
		else 
		{
			// Not last 
			//simple command
			//create pipe
			int fdpipe[2];
			pipe(fdpipe);
			fdout=fdpipe[1];
			fdin=fdpipe[0];
		}
		// if/else
		// Redirect output
		dup2(fdout,1);
		close(fdout);

		// Create child process
		if (is_not_builtin(ct->commands[i].argv[0]))
		{
			ret=fork();
			if(ret==0) 
			{


				search_right_bin(ct->commands[i].argv, *envp);
				// if (execve(ct->commands[i].argv[0], ct->commands[i].argv, *envp) == -1)
				// {
				// 	ft_putendl_fd(strerror(errno), 2);
				// }
				// pwd(envp);
				exit(1);
			}
		}
		else
			execbuiltin(ct->commands[i].argv[0], ct->commands[i].argv, ct->commands[i].argc, envp);
	} //  for

	//restore in/out defaults
	dup2(tmpin,0);
	dup2(tmpout,1);
	close(tmpin);
	close(tmpout);
	if(ret != 0)
		waitpid(ret, NULL, 0);
} // execute