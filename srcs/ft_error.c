/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:29:30 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/28 17:58:27 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_map_error(int i, int j)
{
	printf("Map error in row %d collumn %d\n\n", i, j);
	free_memory();
}

void	ft_error(char *error)
{
	printf("%s\n", error);
	free_memory();
}
