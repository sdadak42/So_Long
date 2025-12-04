/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:06:16 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/11 20:00:58 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move(t_game *game, int keycode, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	if (keycode == KEY_W)
		y++;
	else if (keycode == KEY_S)
		y--;
	else if (keycode == KEY_A)
		x++;
	else if (keycode == KEY_D)
		x--;
	game->map[y][x] = '0';
	game->map[game->exit_y][game->exit_x] = 'E';
	game->map[game->player_y][game->player_x] = 'P';
	game->count_move++;
	ft_printf("Move count: %d\n", game->count_move);
	ft_put_to_window(game, 0, 0);
}

static void	ft_location_check(t_game *game, int keycode, int x, int y)
{
	if (game->map[y][x] == '1')
		return ;
	else if (game->map[y][x] == 'C')
	{
		game->count_coin--;
		ft_move(game, keycode, x, y);
	}
	else if (game->map[y][x] == '0')
		ft_move(game, keycode, x, y);
	else if (game->map[y][x] == 'E' && game->count_coin == 0)
	{
		ft_printf("Congratulations, you completed the game in");
		ft_printf(" %d moves!\n", game->count_move + 1);
		ft_free_and_exit(game);
	}
	else if (game->map[y][x] == 'E' && game->count_coin > 0)
		ft_move(game, keycode, x, y);
}

int	ft_key_handle(int keycode, void *game_data)
{
	t_game	*game;

	game = (t_game *)game_data;
	if (keycode == KEY_ESC)
		ft_free_and_exit(game);
	else if (keycode == KEY_W)
		ft_location_check(game, keycode, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A)
		ft_location_check(game, keycode, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S)
		ft_location_check(game, keycode, game->player_x, game->player_y + 1);
	else if (keycode == KEY_D)
		ft_location_check(game, keycode, game->player_x + 1, game->player_y);
	return (0);
}

void	so_long(char *ber)
{
	t_game	game;
	int		size_x;
	int		size_y;

	game.count_move = 0;
	ft_read_map(ber, &game);
	ft_map_check(&game);
	game.mlx_ptr = mlx_init();
	mlx_get_screen_size(game.mlx_ptr, &size_x, &size_y);
	if (size_x < game.count_columns * 64 || size_y < game.count_lines * 64)
	{
		mlx_destroy_display(game.mlx_ptr);
		ft_free_map(game.map);
		free(game.mlx_ptr);
		ft_error_and_exit("The map is larger than the screen size!");
	}
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.count_columns * 64,
			game.count_lines * 64, "so_long");
	ft_set_textures(&game);
	ft_put_to_window(&game, 0, 0);
	mlx_hook(game.win_ptr, 17, 0, &ft_close_game, &game);
	mlx_key_hook(game.win_ptr, &ft_key_handle, &game);
	mlx_loop(game.mlx_ptr);
}

int	main(int ac, char **argv)
{
	if (ac == 2)
	{
		ft_ber_control(argv[1]);
		so_long(argv[1]);
	}
	else
		return (ft_printf("Error\nWrong number of argument!"), 1);
}
