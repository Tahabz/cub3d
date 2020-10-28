/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:07:29 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/28 18:09:01 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

const int		g_bytes_per_pixel = 4;
const int		g_file_header_size = 14;
const int		g_info_header_size = 40;

void			screenshot(void)
{
	generate_bitmap_image();
	printf("Image generated!!");
}

void			generate_bitmap_image(void)
{
	int						fd;
	int						i;
	t_screenshot			screenshot;
	static unsigned char	padding[3] = {0, 0, 0};

	screenshot.widthInBytes = g_win_width * g_bytes_per_pixel;
	screenshot.paddingSize = (4 - (screenshot.widthInBytes) % 4) % 4;
	screenshot.stride = screenshot.widthInBytes + screenshot.paddingSize;
	fd = open("screenshot.bmp", O_RDWR, S_IRUSR | S_IWUSR);
	screenshot.file_header = create_bitmap_file_header(screenshot.stride);
	write(fd, screenshot.file_header, g_file_header_size);
	screenshot.info_header = create_bitmap_info_header();
	write(fd, screenshot.info_header, g_info_header_size);
	i = g_win_height;
	while (i)
	{
		write(fd, (unsigned char *)g_data + (i * screenshot.widthInBytes),
				g_bytes_per_pixel * g_win_width);
		write(fd, padding, screenshot.paddingSize);
		i--;
	}
	close(fd);
}

unsigned char	*create_bitmap_file_header(int stride)
{
	int						file_size;
	static unsigned char	file_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	file_size = g_file_header_size + g_info_header_size + stride * g_win_height;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(g_file_header_size + g_info_header_size);
	return (file_header);
}

unsigned char	*create_bitmap_info_header(void)
{
	static unsigned char info_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0
	};

	info_header[0] = (unsigned char)(g_info_header_size);
	info_header[4] = (unsigned char)(g_win_width);
	info_header[5] = (unsigned char)(g_win_width >> 8);
	info_header[6] = (unsigned char)(g_win_width >> 16);
	info_header[7] = (unsigned char)(g_win_width >> 24);
	info_header[8] = (unsigned char)(g_win_height);
	info_header[9] = (unsigned char)(g_win_height >> 8);
	info_header[10] = (unsigned char)(g_win_height >> 16);
	info_header[11] = (unsigned char)(g_win_height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(g_bytes_per_pixel * 8);
	return (info_header);
}
