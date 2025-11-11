/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:18:34 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/11 19:48:29 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_rect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((game->map)[0][i])
		i++;
	if (i <= 2)
	{
		ft_free_map(game->map);
		ft_error_and_exit("Number of column is 2 or less!");
	}
	game->count_columns = i;
	while ((game->map)[j])
	{
		i = 0;
		while ((game->map)[j][i])
			i++;
		if (i != game->count_columns)
		{
			ft_free_map(game->map);
			ft_error_and_exit("The map is not rectangular!");
		}
		j++;
	}
}

static void	ft_wall_check(t_game *game, int cline, int ccolumn)
{
	int	i;

	i = 0;
	while ((game->map)[0][i])
	{
		if (((game->map)[0][i] != '1') || ((game->map)[cline - 1][i] != '1'))
		{
			ft_free_map(game->map);
			ft_error_and_exit("The map is not walled!");
		}
		i++;
	}
	i = 0;
	while ((game->map)[i])
	{
		if (((game->map)[i][0] != '1') || ((game->map)[i][ccolumn - 1] != '1'))
		{
			ft_free_map(game->map);
			ft_error_and_exit("The map is not walled!");
		}
		i++;
	}
}

static void	ft_value_count(t_game *game, char value, int y, int x)
{
	if (value == 'C')
		game->count_coin++;
	else if (value == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->count_p++;
	}
	else if (value == 'E')
	{
		game->count_e++;
		game->exit_x = x;
		game->exit_y = y;
	}
	if (game->count_p > 1)
	{
		ft_free_map(game->map);
		ft_error_and_exit("There can be a maximum of one player!");
	}
	if (game->count_e > 1)
	{
		ft_free_map(game->map);
		ft_error_and_exit("There can be a maximum of one exit!");
	}
}

static void	ft_char_check(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 1;
	j = 1;
	map = game->map;
	while ((game->map)[j + 1])
	{
		i = 0;
		while ((game->map)[j][i + 1])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != 'C'
				&& map[j][i] != 'P' && map[j][i] != 'E')
			{
				ft_free_map(game->map);
				ft_error_and_exit("Unknown value on the map!");
			}
			if (map[j][i] != '0' && map[j][i] != '1')
				ft_value_count(game, map[j][i], j, i);
			i++;
		}
		j++;
	}
}

void	ft_map_check(t_game *game)
{
	game->count_coin = 0;
	game->count_p = 0;
	game->count_e = 0;
	ft_is_rect(game);
	ft_wall_check(game, game->count_lines, game->count_columns);
	ft_char_check(game);
	if (game->count_coin == 0 || game->count_p == 0 || game->count_e == 0)
		ft_free_map(game->map);
	if (game->count_coin == 0)
		ft_error_and_exit("There must be at least one coin!");
	if (game->count_p == 0)
		ft_error_and_exit("There must be a player!");
	if (game->count_e == 0)
		ft_error_and_exit("There must be an exit!");
	ft_is_accessible(game);
}
