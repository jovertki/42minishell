/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:30:52 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/19 20:26:38 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char **make_command(char *s1, char *s2)
{
	char **out;

	out = malloc(sizeof(char *) * 3);
	out[0] = ft_strdup(s1);
	out[1] = ft_strdup(s2);
	out[2] = NULL;
	return(out);
}

void	set_pwds(char ***envp)
{
	char **temp;
	char *strtemp; 
	char buf[PATH_MAX];

	strtemp = ft_strjoin("OLDPWD", find_env(*envp, "PWD=", 0));
	temp = make_command("export", strtemp);
	ft_export(2, temp, envp);
	free(strtemp);
	int i;
	i = 0;
	while(temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	strtemp = ft_strjoin("PWD=", getcwd(buf, PATH_MAX));
	temp = make_command("export", strtemp);
	ft_export(2, temp, envp);
	free(strtemp);
	i = 0;
	while(temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

void	cd(char **argv, int argc, char ***envp)
{
	int ret;
	char *str;
	char **temp;

	ret = 123;
	if (argc > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return ;
	}
	if (argv[1] == NULL || argv[1][0] == '\0')
	{
		str = find_env(*envp, "HOME=", 0);
	}
	else if (argv[1] != NULL && argv[1][0] == '~')
	{
		str = getenv("HOME");
	}
	else
	{
		str = argv[1];
	}
	if (chdir(str) == -1)
	{
		perror("cd");
		return ;
	}
	
	//make srt absolute path

	set_pwds(envp);

//	strtemp = find_env(envp, "OLDPWD\0", 0);//<-----------------------------SOME SHIT Segmentation fault: 11 IN BASH HERE
	



}







// void	remove_last(char *str)
// {
// 	int i;
// 	int index;

// 	i = 0;
// 	index = 0;
// 	while(str[i])
// 	{
// 		if (str[i] == '/')
// 			index = i;
// 		i++;
// 	}
// 	if (index != 0)
// 		str[index] = '\0';
// }

// void	add_last(char **buf_pwd, char *str)
// {
// 	size_t old_len;
// 	size_t new_len;
// 	old_len = ft_strlen(*buf_pwd);
// 	new_len = old_len + ft_strlen(str) + 2;
// 	*buf_pwd = ft_crealloc((void**)buf_pwd, old_len, new_len);
// 	(*buf_pwd)[old_len] = '/';
// 	old_len++;
// 	int i;
// 	i = 0;
// 	while (str[i])
// 	{
// 		(*buf_pwd)[old_len] = str[i];
// 		i++;
// 		old_len++;
// 	}
// }

// void	apply_changes(char **split_arg, char **buf_pwd)
// {
// 	int	i;

// 	i = 0;
// 	while (split_arg[i])
// 	{
// 		if (ft_strncmp(split_arg[i], ".\0", 2) == 0)
// 		{}
// 		else if (ft_strncmp(split_arg[i], "..\0", 3) == 0)
// 			remove_last(*buf_pwd);
// 		else
// 			add_last(buf_pwd, split_arg[i]);
// 		i++;
		
// 	}
// 	printf("buf_pwd = '%s'\n", *buf_pwd);
// }

// // int is_valid_dir(char *str)
// // {
// // 	struct stat path_stat;
// // 	stat(str, &path_stat); //check return value for file existance
// // 	return ((S_ISDIR(path_stat.st_mode)));
// // }

// // int is_regular_file(const char *path)
// // {
// //     struct stat path_stat;
// //     stat(path, &path_stat);
// //     return S_ISREG(path_stat.st_mode);
// // }

// void	cd(char **argv, char **envp)
// {
// 	char *str;
// 	char *buf_pwd;
// 	char **split_arg;

// 	if (argv[1] == 0)
// 		str = find_env(envp, "HOME=");
// 	else
// 		str = argv[1];
// 	if (str == NULL || str[0] == '\0')
// 	{} //DO SOME STUFF IF HOME IS BULLSHIT
// 	buf_pwd = NULL;
// 	buf_pwd = ft_strdup(find_env(envp, "PWD="));
// 	//CHECK PWD FOR BULLSHIT
// 	//DO SOME STUFF IF PWD IS NULL or BULLSHIT
// 	split_arg = ft_split(str, '/');
// 	apply_changes(split_arg, &buf_pwd);

// 	char *temp;
// 	temp = find_env(envp, "PWD=") - 4;
// 	free(temp);

// 	//check for validity

// 	// if (!(is_valid_dir(buf_pwd)))
// 	// 	printf("not a directory\n");

// 	//if is valid
	
// 	temp = ft_strjoin("PWD=", buf_pwd);
// 	free(buf_pwd);
// //DONT FORGET TO FREE SPLIT_ARG AND BUF_PWD

// 	printf("temp = '%s'\n", temp);


// 	// int i = 0;
// 	// while (split_arg[i])
// 	// {
// 	// 	printf("[%d] = '%s'\n", i, split_arg[i]);
// 	// 	i++;
// 	// }

	
// }
