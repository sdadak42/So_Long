/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:30:55 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/11 19:54:10 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_and_exit(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(1);
}

void	ft_free_and_exit(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_coin);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_floor);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_free_map(game->map);
	free(game->mlx_ptr);
	exit(0);
}

void	ft_set_textures(t_game *game)
{
	int	width;
	int	height;

	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player.xpm", &width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/floor.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm",
			&width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm",
			&width, &height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin.xpm",
			&width, &height);
}

void	ft_put_to_window(t_game *game, int x, int y)
{
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_wall, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_exit, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_coin, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_player, x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->img_floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	ft_close_game(void *game)
{
	ft_free_and_exit(game);
	exit(0);
}
