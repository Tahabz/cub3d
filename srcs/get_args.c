/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:37:35 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/09 19:17:44 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		get_args(int c, char **v)
{
	char *ext;

	if (c == 1 || c > 3)
		ft_error("Error\ninvalid argument!");
	ext = ft_strrchr(v[1], '.');
	if (!ext)
		ft_error("Error\ninvalid argument!");
	else if (ft_strncmp(ext, ".cub", 5) != 0)
		ft_error("Error\ninvalid argument!");
	g_file = v[1];
	if (c == 3)
	{
		if (ft_strncmp("--save", v[2], ft_strlen(v[2])) == 0)
			g_att = 1;
		else
			ft_error("Error\ninvalid argument!");
	}
}
