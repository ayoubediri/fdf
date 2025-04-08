/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiri <adiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:14:47 by adiri             #+#    #+#             */
/*   Updated: 2025/01/05 10:23:55 by adiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_button(int k, t_data *d)
{
	ft_full_button(k, d);
	if (d->pp == 0 && d->k == 1)
	{
		ft_reinitialize_data_iso(d);
		d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
		d->data = mlx_get_data_addr(d->img, &d->bpp, &d->s_l, &d->endian);
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
		(ft_isometric(d), mlx_destroy_image(d->mlx, d->img));
		d->img = NULL;
	}
	else if (d->pp == 1 && d->k == 1)
	{
		ft_reinitialize_data_pers(d);
		d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
		d->data = mlx_get_data_addr(d->img, &d->bpp, &d->s_l, &d->endian);
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
		(ft_perspective(d), mlx_destroy_image(d->mlx, d->img));
		d->img = NULL;
	}
	return (0);
}

void	ft_button_else(int k, t_data *d)
{
	if (k == XK_KP_Subtract)
		d->dp *= 0.95;
	else if (k == 65431)
		d->r_y += 0.05;
	else if (k == 65437)
		d->r_y -= 0.05;
	else if (k == 65430)
		d->r_x += 0.05;
	else if (k == 65432)
		d->r_x -= 0.05;
	else if (k == 65429)
		d->r_z += 0.05;
	else if (k == 65434)
		d->r_z -= 0.05;
	else if (k == 65436)
		d->pp = 0;
	else if (k == 65433)
		d->pp = 1;
}

void	ft_full_button(int k, t_data *d)
{
	if (k == XK_Escape)
		ft_close(d);
	else if (d->k == 0 && (k == XK_KP_Enter || k == XK_Return))
	{
		mlx_destroy_image(d->mlx, d->img_intro);
		(1) && (d->k = 1, d->img_intro = NULL);
	}
	else if (k == XK_Left)
		d->tx -= 5;
	else if (k == XK_Up)
		d->ty -= 5;
	else if (k == XK_Right)
		d->tx += 5;
	else if (k == XK_Down)
		d->ty += 5;
	else if (k == XK_KP_Add)
		d->dp *= 1.05;
	else
		ft_button_else(k, d);
}

int	ft_mouse(int k, int x, int y, t_data *d)
{
	((void)x, (void)y);
	if (k == 4)
		d->z *= 1.01;
	else if (k == 5)
		d->z *= 0.99;
	if (d->pp == 0 && d->k == 1)
	{
		ft_reinitialize_data_iso(d);
		d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
		d->data = mlx_get_data_addr(d->img, &d->bpp, &d->s_l, &d->endian);
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
		(ft_isometric(d), mlx_destroy_image(d->mlx, d->img));
		d->img = NULL;
	}
	else if (d->pp == 1 && d->k == 1)
	{
		ft_reinitialize_data_pers(d);
		d->img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
		d->data = mlx_get_data_addr(d->img, &d->bpp, &d->s_l, &d->endian);
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
		(ft_perspective(d), mlx_destroy_image(d->mlx, d->img));
		d->img = NULL;
	}
	return (1);
}

void	ft_use_windows(t_data *d)
{
	(ft_get_mlx(d), ft_get_win(d));
	mlx_hook(d->win, 12, (1L << 15), ft_show_map, d);
	mlx_hook(d->win, 2, (1L << 0), ft_button, d);
	mlx_hook(d->win, 4, (1L << 2), ft_mouse, d);
	mlx_hook(d->win, 17, 0, ft_close, d);
}
