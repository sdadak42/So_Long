/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdadak <sdadak@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:58:43 by sdadak            #+#    #+#             */
/*   Updated: 2025/10/30 16:58:43 by sdadak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_free_map(char **str)
{
    int i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}

void    ft_ber_control(char *fname)
{
    int i;

    i = 0;
    while (fname[i])
        i++;
    if (fname[i - 1] != 'r' || fname[i - 2] != 'e' || fname[i - 3] != 'b'
        || fname[i - 4] != '.')
        ft_error_and_exit("Wrong file name!");
}

static void ft_line_count(char *ber, t_game *game)
{
    int i;
    int fd;
    char    *input;

    i = 0;
    fd = open(ber, O_RDONLY);
    if (fd < 0)
        ft_error_and_exit("File could not be opened!");
    input = get_next_line(fd);
    if (!input)
    {
        close(fd);
        ft_error_and_exit("Map file is empty!");
    }
    while (input)
    {
        i++;
        free(input);
        input = get_next_line(fd);
    }
    close(fd);
    if (i <= 2)
        ft_error_and_exit("Number of lines is 2 or less!");
    game -> count_lines = i;
}

static char **ft_trimmed(char **str)
{
    int i;
    char    *temp;

    i = 0;
    while (str[i])
    {
        temp = ft_strtrim(str[i], "\n");
        if (!temp)
        {
            ft_free_map(str);
            ft_error_and_exit("Memory could not be allocated!");
        }
        free(str[i]);
        str[i] = temp;
        i++;
    }
    return (str);
}

void    ft_read_map(char *ber, t_game *game)
{
    int     i;
    int     fd;
    char    **map;
    char    *input;

    i = 0;
    ft_line_count(ber, game);
    map = (char **)malloc(sizeof(char *) * (game->count_lines + 1));
    if (!map)
        ft_error_and_exit("Memory could not be allocated!");
    fd = open(ber, O_RDONLY);
    if (fd < 0)
    {
        ft_free_map(map);
        ft_error_and_exit("File could not be opened!");
    }
    input = get_next_line(fd);
    while (input)
    {
        map[i++] = input;
        input = get_next_line(fd);
    }
    map[i] = NULL;
    close(fd);
    game -> map = ft_trimmed(map);
}
