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
# include "get_next_line.h"
# define NUM_ROWS (19)
# define NUM_COLS (80)
# define TILE_SIZE 200
# define WINDOW_WIDTH2D TILE_SIZE * NUM_COLS
# define WINDOW_HEIGHT2D TILE_SIZE * NUM_ROWS
# define UP_ARROW 126
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define WALL_STRIP_WIDTH 1
# define MINIMAP_SCALE 0.2
# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122
# define K_AR_L 65361
# define K_AR_R 65363
# define K_AR_U 65362
# define K_AR_D 65364
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <string.h>

char			**ft_split(char const *str, char c);
void    render_walls();
void    ft_putchar(char c);
void	castAllRays();
void    ft_putnbr(int n);
void    rect(int tileX, int tileY, unsigned int tilecol, int size);
void    render_grid();
int		grid_hasWallAt(int x, int y);
void	line3d(int tileX, int tileY, int height, unsigned int tilecol);
void	check_map_errors();
#endif
