/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrasezin <rrasezin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:21:08 by bchifour          #+#    #+#             */
/*   Updated: 2023/08/05 10:42:47 by rrasezin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int keycode, t_beta *beta)
{
	check_state_door(beta, keycode);
	if (keycode == 99999)
	{
		beta->pdx = cos(30 * 0.0174532925);
		beta->pdy = sin(30 * 0.0174532925);
		beta->shift_y += beta->pdy * 5;
		beta->shift_x += beta->pdx * 5;
		beta->pdx = cos(beta->_const);
		beta->pdy = sin(beta->_const);
	}
	esc(beta, keycode);
	mouvement(beta, keycode);
	_fold_of_view(beta, keycode);
	mlx_clear_window(beta->mlx, beta->win);
	ft_bzero(beta->world.addr, SCREENHEIGHT * SCREENWIDTH * sizeof(int));
	backgrand(beta);
	randring(beta);
	mlx_put_image_to_window(beta->mlx, beta->win, beta->world.img, 0, 0);
	mlx_put_image_to_window(beta->mlx, beta->win, beta->image.img,
		0, SCREENHEIGHT - B * beta->map->height);
	return (0);
}
