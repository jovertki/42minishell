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









	//test input 4

	ct->num_of_commands = 2;
	ct->commands = ft_calloc(sizeof(t_command), 5);

	ct->commands[0].argv = ft_calloc(sizeof(char*), 4);
	ct->commands[0].argv[0] = ft_strdup("unset\0");
	ct->commands[0].argv[1] = ft_strdup("VAR\0");
	ct->commands[0].argc = 1;

	ct->commands[1].argv = ft_calloc(sizeof(char*), 4);
	ct->commands[1].argv[0] = ft_strdup("/bin/lss\0");
	// ct->commands[1].argv[1] = ft_strdup("VARRR");
	ct->commands[1].argc = 1;

	// ct->commands[2].argv = ft_calloc(sizeof(char*), 4);
	// ct->commands[2].argv[0] = ft_strdup("export\0");
	// ct->commands[2].argc = 1;



	//TEST INPUT 3
	// ct->num_of_commands = 4;
	// ct->commands = ft_calloc(sizeof(t_command), 5);

	// ct->commands[0].argv = ft_calloc(sizeof(char*), 4);
	// ct->commands[0].argv[0] = ft_strdup("export\0");
	// ct->commands[0].argv[1] = ft_strdup("VAR\0");
	// ct->commands[0].argc = 2;

	// ct->commands[1].argv = ft_calloc(sizeof(char*), 4);
	// ct->commands[1].argv[0] = ft_strdup("export\0");
	// ct->commands[1].argc = 1;

	// ct->commands[2].argv = ft_calloc(sizeof(char*), 4);
	// ct->commands[2].argv[0] = ft_strdup("export\0");
	// ct->commands[2].argv[1] = ft_strdup("VAR=123\0");
	// ct->commands[2].argc = 2;

	// ct->commands[3].argv = ft_calloc(sizeof(char*), 4);
	// ct->commands[3].argv[0] = ft_strdup("env\0");
	// ct->commands[3].argc = 1;


	//TEST INPUT 2
	// ct->num_of_commands = 2;
	// ct->commands = ft_calloc(sizeof(t_command), 3);

	// ct->commands[0].argv = ft_calloc(sizeof(char*), 3);
	// ct->commands[0].argv[0] = ft_strdup("cd\0");
	// ct->commands[0].argv[1] = ft_strdup("\0");
	// ct->commands[0].argc = 2;

	// ct->commands[1].argv = ft_calloc(sizeof(char*), 3);
	// ct->commands[1].argv[0] = ft_strdup("pwd\0");
	// ct->commands[1].argc = 1;
	




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

char	**prune_env(char **envp)
{
	int i;
	int j;
	char **new_envp;
	
	i = 0;
	while ((envp)[i])
		i++;
	new_envp = ft_calloc(sizeof(char *), i + 2);
	i = 0;
	j = 0;
	while (envp[i])
	{
		if (envp[i][0] != '\0')
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


void	free_env(char **envp)
{
	int i;

	i = 0;
	while(envp[i])
	{
		free(envp[i]);
		i++;
	}
	free(envp);
}

void	free_ct(t_commandtable *ct)
{
	int i;
	i = 0;
	int j;
	while(i < ct->num_of_commands)
	{
		j = 0;
		while(ct->commands[i].argv[j])
		{
			free(ct->commands[i].argv[j]);
			j++;
		}
		free(ct->commands[i].argv);
		i++;
	}
	free(ct->commands);
}

int	main(int argc, char **argv, const char **envp)
{
	char	*str;
	t_all	all;
	ft_bzero(&all, sizeof(t_all));
	all.env = get_env(envp);
	// all.env = prune_env(all.env);


//parser with commandtable on out
//command table is
// t_command
// list of commands intended to work through pipes like "ls | grep ./a.out | wc -l" 

	t_commandtable ct;
	ft_bzero(&ct, sizeof(t_commandtable));

	get_ct(&ct);

	execute(&ct, &all.env);
	printf("main pid = %d\n", getpid());


	free_ct(&ct);
	free_env(all.env);





	// int i = 0;
	// while (envp[i])
	// {
	// 	printf("%s\n", envp[i]);
	// 	i++;
	// }
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
	usleep(1000000);
	printf("exit\n");
}
