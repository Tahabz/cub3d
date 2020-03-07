// int map[NUM_ROWS][NUM_COLS] =
// 	{
// 			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
// 			{1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,1,1,1,1,0,1,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1},
// 			{1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
// 			{1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
// 			{1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,1,1,1,1,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
// 			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };


char **map;
void *image;
int *data;
void *window;
void *mlx;


typedef struct s_player {
	float	x;
	float	y;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	rotationSpeed;
	int		moveSpeed;
}				t_player;

typedef struct s_rays {
	float 	rayAngle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		isRayFacingDown;
	int		isRayFacingUp;
	int		isRayFacingLeft;
	int		isRayFacingRight;
}				t_rays;

typedef struct s_image {
	int *data;
	int *image;
	int width;
	int height;
	int	bpp;
	int	sl;
	int	end;
	char *texture;
}				t_image;

const int WINDOW_WIDTH3D = 2000;
const int WINDOW_HEIGHT3D = 1200;

char *sprite_texture;
int win_width;
int win_height;

int floor_color[3];
int ceilling_color[3];
float FOV_ANGLE = 60 * (M_PI / 180);

t_image no_image;
t_image we_image;
t_image ea_image;
t_image so_image;
t_rays *rays;
t_rays ray;
t_player player;