/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:40:49 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/27 14:46:02 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"










static int		ft_count(int n)
{
	unsigned int	nbr;
	int				i;

	i = 1;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	else
		nbr = n;
	while (nbr / 10 > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*s;
	int				count;

	count = ft_count(n);
	if (!(s = (char *)malloc(count + 1)))
		return (0);
	if (n == 0)
		*s = '0';
	if (n < 0)
	{
		s[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	s[count--] = '\0';
	while (nbr > 0)
	{
		if (count == 0 && n < 0)
			break ;
		*(s + count--) = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (s);
}









void	put_walls_to_image(double walltop, double wallbottom, int i)
{
	int j;

	j = 0;
	while (j < walltop)
		g_data[(j++ * g_win_width) + i] = 0;
	j = wallbottom;
	while (j < g_win_height)
		g_data[(j++ * g_win_width) + i] = 200;
}


const int BYTES_PER_PIXEL = 4;
const int FILE_HEADER_SIZE = 14;
const int INFO_HEADER_SIZE = 40;

void generateBitmapImage(char* imageFileName);
unsigned char* createBitmapFileHeader(int stride);
unsigned char* createBitmapInfoHeader();


void mainy ()
{
    char* imageFileName = (char*) "bitmapImage.bmp";
    generateBitmapImage(imageFileName);
    printf("Image generated!!");
}


void generateBitmapImage (char* imageFileName)
{
	printf("bb %d\n", size_line);
    int widthInBytes = g_win_width * BYTES_PER_PIXEL;

    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (widthInBytes) % 4) % 4;

	int stride = (widthInBytes) + paddingSize;
	
    FILE* imageFile = fopen(imageFileName, "wb");

    unsigned char* fileHeader = createBitmapFileHeader(stride);
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);

    unsigned char* infoHeader = createBitmapInfoHeader();
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);

    int i;
    for (i = g_win_height; i > 0; i--) {
        fwrite((unsigned char *)g_data + (i*widthInBytes), BYTES_PER_PIXEL, g_win_width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}

unsigned char* createBitmapFileHeader (int stride)
{
    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + stride * g_win_height;

    static unsigned char fileHeader[] = {
        0,0,     /// signature
        0,0,0,0, /// image file size in bytes
        0,0,0,0, /// reserved
        0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* createBitmapInfoHeader ()
{
    static unsigned char infoHeader[] = {
        0,0,0,0, /// header size
        0,0,0,0, /// image width
        0,0,0,0, /// image height
        0,0,     /// number of color planes
        0,0,     /// bits per pixel
        0,0,0,0, /// compression
        0,0,0,0, /// image size
        0,0,0,0, /// horizontal resolution
        0,0,0,0, /// vertical resolution
        0,0,0,0, /// colors in color table
        0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(g_win_width);
    infoHeader[ 5] = (unsigned char)(g_win_width >>  8);
    infoHeader[ 6] = (unsigned char)(g_win_width >> 16);
    infoHeader[ 7] = (unsigned char)(g_win_width >> 24);
    infoHeader[ 8] = (unsigned char)(g_win_height);
    infoHeader[ 9] = (unsigned char)(g_win_height >>  8);
    infoHeader[10] = (unsigned char)(g_win_height >> 16);
    infoHeader[11] = (unsigned char)(g_win_height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}

void	render_walls(void)
{
	int		i;
	double	ray_distance;
	double	wall_strip_height;
	double	walltop;
	double	wallbottom;

	i = 0;
	g_distance_proj_plane = (g_win_width / 2) / tanf(g_fov_angle / 2);
	while (i < g_win_width)
	{
		ray_distance = g_rays[i].distance * cosf(
						g_rays[i].ray_angle - g_player.rotation_angle);
		wall_strip_height = ((double)TILE_SIZE / ray_distance)
								* (double)g_distance_proj_plane;
		walltop = ((double)g_win_height / 2) - (wall_strip_height / 2);
		walltop = walltop < 0 ? 0 : walltop;
		wallbottom = ((double)g_win_height / 2) + (wall_strip_height / 2);
		wallbottom = wallbottom > g_win_height ? g_win_height : wallbottom;
		put_walls_to_image(walltop, wallbottom, i);
		line3d_walls(walltop, wallbottom, wall_strip_height, i++);
	}
	render_sprite();
	if (att == 0)
		mainy();
	att++;
	mlx_put_image_to_window(g_mlx, g_window, g_image, 0, 0);
}
