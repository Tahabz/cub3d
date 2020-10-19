#include "../cub.h"
#include "../cub1.h"

void	get_image()
{
	no_image.image = mlx_xpm_file_to_image(mlx, no_image.texture, &(no_image.width), &(no_image.height));
	no_image.data = (int *)mlx_get_data_addr(no_image.image, &no_image.bpp, &no_image.sl, &no_image.end);
	sp_image.image = mlx_xpm_file_to_image(mlx, sp_image.texture, &(sp_image.width), &(sp_image.height));
	sp_image.data = (int *)mlx_get_data_addr(sp_image.image, &sp_image.bpp, &sp_image.sl, &sp_image.end);
	ea_image.image = mlx_xpm_file_to_image(mlx, ea_image.texture, &(ea_image.width), &(ea_image.height));
	ea_image.data = (int *)mlx_get_data_addr(ea_image.image, &ea_image.bpp, &ea_image.sl, &ea_image.end);
	so_image.image = mlx_xpm_file_to_image(mlx, so_image.texture, &(so_image.width), &(so_image.height));
	so_image.data = (int *)mlx_get_data_addr(so_image.image, &so_image.bpp, &so_image.sl, &so_image.end);
	we_image.image = mlx_xpm_file_to_image(mlx, we_image.texture, &(we_image.width), &(we_image.height));
	we_image.data = (int *)mlx_get_data_addr(we_image.image, &we_image.bpp, &we_image.sl, &we_image.end);  
}
