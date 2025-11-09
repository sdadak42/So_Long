/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:06:16 by sdadak            #+#    #+#             */
/*   Updated: 2025/10/27 22:06:16 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_set_textures(t_game *game)
{
    int width;
    int height;

    game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
        "textures/player.xpm", &width, &height);
    game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "textures/floor.xpm",
        &width, &height);
    game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "textures/wall.xpm",
        &width, &height);
    game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "textures/exit.xpm",
        &width, &height);
    game->img_coin = mlx_xpm_file_to_image(game->mlx_ptr, "textures/coin.xpm",
        &width, &height);
}
void    ft_put_to_window(t_game *game, int x, int y)
{
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
                game->img_floor, x * 64, y * 64);
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
            x++;
        }
        y++;
    }
}

void    so_long(char *ber)
{
    t_game  game;

    ft_read_map(ber, &game);
    ft_map_check(&game);
    game.mlx_ptr = mlx_init();
    game.win_ptr = mlx_new_window(game.mlx_ptr, game.count_columns * 64, game.count_lines * 64, "so_long");
    ft_set_textures(&game);
    ft_put_to_window(&game, 0, 0);

    ft_free_map(game.map);
}
int main(int ac, char **argv)
{
    if (ac == 2)
    {
        ft_ber_control(argv[1]);
        so_long(argv[1]);
    }
    else
        return (ft_printf("Error\nWrong number of argument!"), 1);
}
