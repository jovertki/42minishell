/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovertki <jovertki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:28:56 by jovertki          #+#    #+#             */
/*   Updated: 2021/07/12 17:15:29 by jovertki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//NOT PROTECTED AGAINST ANYTHING
void	*ft_crealloc(void **ptr, size_t old_size, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = ft_calloc(size, 1);
	while (i < old_size)
	{
		new[i] = (*(char **)ptr)[i];
		i++;
	}
	free(*ptr);
	*ptr = new;
	return (new);
}