#include "minishell.h"

int	main(int argc, char **argv, const char **envp)
{
	char	*str;
	t_all	all;
	ft_bzero(&all, sizeof(t_all));
	all.env = get_env(envp);
	all.workdir = getcwd(NULL, 0);
	while (1)
	{
		str = readline("minishell$ ");
		if (ft_strncmp(str, "exit", 4) == 0)
			break ;
		printf("str = '%s'\n", str);
		if (ft_strncmp(str, "pwd", 3) == 0)
			pwd(&all);
		if (ft_strncmp(str, "env", 3) == 0)
			env(&all);
		free(str);
	}
	printf("exit\n");
}
