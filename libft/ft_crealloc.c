/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:28:56 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/09 23:01:02 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//NOT PROTECTED AGAINST ANYTHING
void	*ft_crealloc(void **ptr, size_t old_size, size_t size)
{
	char	*old;
	char	*new;
	size_t	i;

	old = *(char **)ptr;
	printf("old = %s\n", old);
	i = 0;
	new = ft_calloc(size, 1);
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	free(*ptr);
	return (new);
}