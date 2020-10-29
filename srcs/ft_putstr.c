/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:57:26 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/29 14:05:01 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (*(s + i) != '\0')
	{
		write(1, (s + i), 1);
		i++;
	}
}