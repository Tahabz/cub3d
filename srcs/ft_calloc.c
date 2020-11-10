/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:53:05 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/08 13:52:24 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		i;

	i = 0;
	ptr = malloc(size * count);
	if (ptr)
	{
		while ((int)(count * size) > i)
		{
			*(char*)(ptr + i) = 0;
			i++;
		}
		return (ptr);
	}
	return (0);
}
