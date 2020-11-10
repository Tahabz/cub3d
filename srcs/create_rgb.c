/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:20:26 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 12:46:14 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

unsigned long	create_rgb(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		ft_error("Error\nRgb value must not be more than 255");
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
