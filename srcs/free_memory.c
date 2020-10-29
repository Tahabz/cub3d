/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:19:09 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/29 13:46:29 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_double_pointer(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	free_memory(void)
{
	free_double_pointer(g_map);
	exit(0);
}
