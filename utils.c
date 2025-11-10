/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 23:30:55 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/05 23:30:55 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error_and_exit(char *message)
{
    ft_printf("Error\n%s\n", message);
    exit(1);
}

void    ft_free_and_exit(t_game *game)
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
