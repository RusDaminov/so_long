#include "so_long.h"

void ft_error(const char *text)
{
    ft_putstr_fd(text, 1);
    ft_putstr_fd("\n", 1);
    exit(EXIT_FAILURE);
}