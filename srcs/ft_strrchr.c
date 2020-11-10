/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:42:57 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/08 14:27:43 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	int				i;
	int				a;
	int				count;

	count = 0;
	a = ft_strlen(s);
	i = 0;
	str = (unsigned char *)s;
	if (a == 0 && *str != c)
		return (0);
	while (i <= a)
	{
		if (*(str + i) == (unsigned char)c)
			count = i;
		i++;
	}
	if (*(str + count) == (unsigned char)c)
		return ((void *)(str + count));
	return (0);
}
