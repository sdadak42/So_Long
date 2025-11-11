/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:26:27 by sdadak            #+#    #+#             */
/*   Updated: 2025/11/11 19:39:08 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "Libft/Libft/libft.h"
# include "Libft/Printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		count_lines;
	int		count_columns;
	int		count_coin;
	int		count_e;
	int		count_p;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	void	*img_player;
	void	*img_coin;
	void	*img_exit;
	void	*img_floor;
	void	*img_wall;
	int		count_move;
}	t_game;

char	*get_next_line(int fd);
void	ft_read_map(char *ber, t_game *game);
void	ft_ber_control(char *fname);
void	ft_free_map(char **str);

void	ft_map_check(t_game *game);
void	ft_is_accessible(t_game *game);

void	ft_error_and_exit(char *message);
void	ft_free_and_exit(t_game *game);
void	ft_set_textures(t_game *game);
void	ft_put_to_window(t_game *game, int x, int y);
int		ft_close_game(void *game);

#endif
