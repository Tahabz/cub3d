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
	double	x;
	double	y;
	int		turnDirection;
	int		walkDirection;
	double	rotationAngle;
	double	rotationSpeed;
	int		moveSpeed;
}				t_player;

typedef struct s_rays {
	double 	rayAngle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		isRayFacingDown;
	int		isRayFacingUp;
	int		isRayFacingLeft;
	int		isRayFacingRight;
	int		hit_vert;
}				t_rays;

typedef struct s_image {
	int *data;
	void *image;
	int width;
	int height;
	int	bpp;
	int	sl;
	int	end;
	char *texture;
}				t_image;

typedef struct s_sprite {
	int x;
	int y;
	float distance;
}				t_sprite;


extern const int sprite_index;
t_sprite sprite[500];

extern const int WINDOW_WIDTH3D;
extern const int WINDOW_HEIGHT3D;

int win_width;
int win_height;

int floor_color[3];
int ceilling_color[3];
extern double FOV_ANGLE;
extern double distance_proj_plane;

t_image no_image;
t_image we_image;
t_image ea_image;
t_image so_image;
t_image sp_image;
t_rays *rays;
t_rays ray;
t_player player;