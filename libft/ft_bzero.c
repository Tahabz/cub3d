/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:20:49 by mobaz             #+#    #+#             */
/*   Updated: 2019/10/17 17:23:07 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	int		i;
	char	*ptr;

	ptr = dst;
	i = 0;
	while (i < (int)n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}
