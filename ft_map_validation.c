#include "so_long.h"

void check_rect(t_map *map)
{
    int i;

    i = 0;
    map->height = ft_strlen(map->map);
    while (map->map[i])
    {
        if (map->width != (int)ft_strlen(map->map[i]))
            ft_error("Height/width mismatch\n");
        write (1, &i, 1);
        i++;
    }
    map->height = i;
}

