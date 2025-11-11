/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accessible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:11:48 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/11 20:04:26 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fill(char **map, int y, int x, t_game game)
{
	if (x < 1 || y < 1 || x > game.count_columns - 1
		|| y > game.count_lines - 1)
		return ;
	if (map[y][x] != '0' && map[y][x] != 'C' && map[y][x] != 'E'
		&& (map)[y][x] != 'P')
		return ;
	map[y][x] = 'X';
	ft_fill(map, y - 1, x, game);
	ft_fill(map, y + 1, x, game);
	ft_fill(map, y, x - 1, game);
	ft_fill(map, y, x + 1, game);
}

static void	ft_accessible_check(char **map, t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (map[j + 1])
	{
		i = 0;
		while (map[j][i + 1])
		{
			if (map[j][i] == 'E')
			{
				ft_free_map(map);
				ft_free_map(game->map);
				ft_error_and_exit("Exit cannot be accessible!");
			}
			if (map[j][i] == 'C')
			{
				ft_free_map(map);
				ft_free_map(game->map);
				ft_error_and_exit("Coin cannot be accessible!");
			}
			i++;
		}
		j++;
	}
}

void	ft_is_accessible(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	map_copy = (char **)malloc(sizeof(char *) * (game->count_lines + 1));
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		i++;
	}
	map_copy[i] = NULL;
	ft_fill(map_copy, game->player_y, game->player_x, *game);
	ft_accessible_check(map_copy, game);
	ft_free_map(map_copy);
}
