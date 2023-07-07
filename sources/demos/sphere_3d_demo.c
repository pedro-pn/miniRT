#include "minirt.h"

static t_intxs	*xs(void)
{
	static t_intxs	_xs;
	
	return (&_xs);
}

static t_sdemo	sdemo_init(int _width)
{
	t_sdemo	sdemo;

	sdemo._sphere = sphere();
	sdemo.wall_z = 10;
	sdemo.wall_size = 7.0;
	sdemo.pixel_size = sdemo.wall_size / _width;
	sdemo.half_wall = sdemo.wall_size / 2;
	sdemo.ray_origin = point(0, 0, -5);
	sdemo._sphere->material = material();
	sdemo._sphere->material.color = tcolor(81.0/255.0, 2.0/255.0, 2.0/255.0);

	return (sdemo);
}

static t_c3d	cast_ray(t_sdemo sdemo)
{
	t_c3d		color;
	t_p3d		_point;
	t_ray		_ray;
	t_intxs		*_xs;
	t_intx		*inter;
	t_lgt_param	params;

	_xs = xs();
	_point = point(sdemo.world_x, sdemo.world_y, sdemo.wall_z);
	_ray = ray(sdemo.ray_origin, normalize(sub(_point, sdemo.ray_origin)));
	*_xs = intersect_sphere(sdemo._sphere, _ray);
	inter = hit(*xs());
	if (inter == NULL)
		return (tcolor(0, 0, 0));
	params.position = position(inter->t, _ray);
	params.normalv = normal_at(*inter->object, params.position, *inter);
	params.eyev = neg(_ray.direction);
	color = lighting(*inter->object, *light(), params);
	ft_lstclear(&xs()->intersections, free);
	return (color);
}

static void	draw_sdemo(t_mlx_img *img, t_sdemo sdemo)
{
	t_c3d	color;
	int		x;
	int		y;

	x = 0;
	while (x < img->_width)
	{
		sdemo.world_x = -sdemo.half_wall + sdemo.pixel_size * x;
		y = 0;
		while (y < img->_height)
		{
			sdemo.world_y = sdemo.half_wall - sdemo.pixel_size * y;
			color = cast_ray(sdemo);
			mlx_draw_pixel_rgb(img, x, y, tcolor_to_rgb(color));
			y++;
		}
		x++;
	}
}

void	sphere_3d_demo(void)
{
	t_mlx_img	*img;
	t_sdemo		sdemo;

	set_camera(1000, 1000, MY_PI / 2);
	img = image();
	set_light(point(5, 0, -5), 1.0);
	set_ambient_light(1.0, white_rgb());
	sdemo = sdemo_init(img->_width);
	draw_sdemo(img, sdemo);
	free(sdemo._sphere);
	mlx_save_img_to_ppm(img, "sphere_3d.ppm");
}
