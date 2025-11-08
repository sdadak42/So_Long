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



void    so_long(char *ber)
{
    t_game  game;

    ft_read_map(ber, &game);
    ft_map_check(&game);


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
