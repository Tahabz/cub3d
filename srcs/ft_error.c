/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:29:30 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/06 18:40:46 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_map_error(int i, int j)
{
	char *row;
	char *col;

	row = ft_itoa(i);
	col = ft_itoa(j);
	ft_putstr("Error\nMap error in row ");
	ft_putstr(row);
	ft_putstr(" column ");
	ft_putstr(col);
	free(row);
	free(col);
	free_memory(EXIT_FAILURE);
}

void	ft_error(char *error)
{
	ft_putstr(error);
	free_memory(EXIT_FAILURE);
}
