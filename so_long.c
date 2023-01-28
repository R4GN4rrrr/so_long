#include <mlx.h>
#include <stdio.h>
#include "so_long.h"
typedef struct s_t7rk
{
    int a;
}   t_ta7arok;
int keybord(int key,t_ta7arok *move)
{
    //printf("%d\n", key);
    move->a++;
    if (key == 126)
        printf("%d: up\n", move->a);
    if (key == 125)
        printf("%d: down\n",move->a);
    if (key == 124)
        printf("%d: right\n",move->a);
    if (key == 123)
        printf("%d: left\n",move->a);
    return 0;
}
int main(int ac, char **av)
{
    t_map map;
    if (ac == 2)
    {
        int x,y;
        t_ta7arok move_nbr;
        move_nbr.a = 0;
        void *mlx_ptr = mlx_init();
        map.fd = open(av[1], O_RDWR, 0777);
        if (map.fd == -1)
            return 0;
        readmap(&map);
        check(&map);
        void *mlx_win = mlx_new_window(mlx_ptr, 500, 500, "fir3awn");
        void *mlx_img = mlx_xpm_file_to_image(mlx_ptr, "image.xpm", &x, &y);
        mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 0, 250);
        mlx_key_hook(mlx_win, keybord, &move_nbr);
        //mlx_hook()
        mlx_loop(mlx_ptr);
    }
    else
        printf("Not enough of args!");
}
