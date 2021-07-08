#include "minishell.h"


void execute(t_commandtable *ct, char **envp)
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
	int ret;
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
		ret=fork();
		if(ret==0) 
		{



			// СЮДА ВОТКНУТЬ ПРОВЕРКУ НА БИЛТИН
			




			
			// pwd(envp);
			execve(ct->commands[i].argv[0], ct->commands[i].argv, envp);
			exit(1);
		}
	} //  for

	//restore in/out defaults
	dup2(tmpin,0);
	dup2(tmpout,1);
	close(tmpin);
	close(tmpout);

	waitpid(ret, NULL, 0);
} // execute


int	main(int argc, char **argv, const char **envp)
{
	char	*str;
	t_all	all;
	ft_bzero(&all, sizeof(t_all));
	all.env = get_env(envp);

//parser with commandtable on out
//command table is
// t_command
// list of commands intended to work through pipes like "ls | grep ./a.out | wc -l" 

	t_commandtable *ct;
	ct = ft_calloc(sizeof(t_commandtable), 1);
	ct->num_of_commands = 3;
	ct->commands = ft_calloc(sizeof(t_command), 4);
	ct->commands[0].argv = ft_calloc(sizeof(char*), 2);
	ct->commands[0].argv[0] = ft_strdup("/bin/ls\0");
	ct->commands[0].argc = 1;
		
	ct->commands[1].argv = ft_calloc(sizeof(char*), 3);	
	ct->commands[1].argv[0] = ft_strdup("/usr/bin/grep\0");
	ct->commands[1].argv[1] = ft_strdup("l");
	ct->commands[1].argc = 2;

	ct->commands[2].argv = ft_calloc(sizeof(char*), 3);
	ct->commands[2].argv[0] = ft_strdup("/usr/bin/wc\0");
	ct->commands[2].argv[1] = ft_strdup("-l");
	ct->commands[2].argc = 3;
	execute(ct, all.env);


	// while (1)
	// {
	// 	str = readline("minishell$ ");
	// 	if (ft_strncmp(str, "exit", 4) == 0)
	// 		break ;
	// 	printf("str = '%s'\n", str);
	// 	if (ft_strncmp(str, "pwd", 3) == 0)
	// 		pwd(&all);
	// 	if (ft_strncmp(str, "env", 3) == 0)
	// 		env(&all);
	// 	// if (ft_strncmp(str, "echo", 4) == 0)
	// 	// 	echo(&all);
	// 	free(str);
	// }
	usleep(100000);
	printf("exit\n");
}
