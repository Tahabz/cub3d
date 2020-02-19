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


# define NUM_ROWS 28
# define NUM_COLS 38
# define TILE_SIZE 50
# define WINDOW_WIDTH TILE_SIZE * NUM_COLS
# define WINDOW_HEIGHT TILE_SIZE * NUM_ROWS
# define UP_ARROW 126
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS WINDOW_WIDTH / WALL_STRIP_WIDTH
# define MINIMAP_SCALE 0.2
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>

void    render_walls();
void    ft_putchar(char c);
void	castAllRays();
void    ft_putnbr(int n);
void    rect(int tileX, int tileY, int width, int height, unsigned int tilecol);
void    render_grid();
int		grid_hasWallAt(int x, int y);

#endif
