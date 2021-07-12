#include "minishell.h"


void	get_ct(t_commandtable *ct)
{
	// ct->num_of_commands = 1;
	// ct->commands = ft_calloc(sizeof(t_command), 2);
	// ct->commands[0].argv = ft_calloc(sizeof(char*), 4);
	// ct->commands[0].argv[0] = ft_strdup("echo\0");
	// ct->commands[0].argv[1] = ft_strdup("-n");
	// ct->commands[0].argv[2] = ft_strdup("line 2");
	// ct->commands[0].argc = 3;

	ct->num_of_commands = 1;
	ct->commands = ft_calloc(sizeof(t_command), 2);
	ct->commands[0].argv = ft_calloc(sizeof(char*), 3);
	ct->commands[0].argv[0] = ft_strdup("cd\0");
	ct->commands[0].argv[1] = ft_strdup("Makefil");
	ct->commands[0].argc = 2;




	//TEST INPUT 1
	// ct->num_of_commands = 3;
	// ct->commands = ft_calloc(sizeof(t_command), 4);
	// ct->commands[0].argv = ft_calloc(sizeof(char*), 2);
	// ct->commands[0].argv[0] = ft_strdup("/bin/ls\0");
	// ct->commands[0].argc = 1;
		
	// ct->commands[1].argv = ft_calloc(sizeof(char*), 3);	
	// ct->commands[1].argv[0] = ft_strdup("/usr/bin/grep\0");
	// ct->commands[1].argv[1] = ft_strdup("l");
	// ct->commands[1].argc = 2;

	// ct->commands[2].argv = ft_calloc(sizeof(char*), 3);
	// ct->commands[2].argv[0] = ft_strdup("/usr/bin/wc\0");
	// ct->commands[2].argv[1] = ft_strdup("-l");
	// ct->commands[2].argc = 3;


	
}
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

	t_commandtable ct;
	ft_bzero(&ct, sizeof(t_commandtable));

	get_ct(&ct);

	execute(&ct, all.env);


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
