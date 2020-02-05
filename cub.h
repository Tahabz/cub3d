/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:34 by mobaz             #+#    #+#             */
/*   Updated: 2020/02/04 18:28:52 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H


# define NUM_ROWS 14
# define NUM_COLS 29
# define TILE_SIZE 32
# define WINDOW_WIDTH TILE_SIZE * NUM_COLS
# define WINDOW_HEIGHT TILE_SIZE * NUM_ROWS
# define UP_ARROW 126
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
void    ft_putchar(char c);
void    ft_putnbr(int n);

#endif
