#include "so_long.h"

int main()
{
	void *mlx;
	void *mlx_win;
	void *img;
	int h = 0;
	int w = 0;

	mlx = mlx_init();
	if (!mlx)
    {
        printf("Erro: mlx_init falhou\n");
        return (1);
    }
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Benficaaaa");
	if (!mlx_win)
    {
        printf("Erro: janela não criada\n");
        return (1);
    }
	img = mlx_xpm_file_to_image(mlx, "bathroom_grass.xpm", &h, &w);
	if (!img)
    {
        printf("Erro: imagem não carregada\n");
        return (1);
    }
	mlx_put_image_to_window(mlx, mlx_win, img, 200, 400);
	mlx_loop(mlx);
}


void init_player(t_game game)
{
	t_player player;
	player.moves = 0;
	player.collectibles = 0;
	player.point = set_begin(game.map.grid);
	player.p_sprite.img_ptr = mlx_xpm_file_to_image(game.mlx, "sprites/shrek_grass.xpm", &player.p_sprite.heigth, &player.p_sprite.width);
	if(!player.p_sprite.img_ptr)
		perror("fuck this");
	
}

void init_window(t_game game)
{
	game.mlx = mlx_init();
	if(!game.mlx)
		perror("img fuckeed");
	game.win = mlx_new_window(game.mlx, 1920, 1080, "SHREK");
	if(!game.win)
		perror("fuck windohhhhhhh");
}

void init_collectibles(t_game game)
{
	game.collect.sprite.img_ptr = mlx_xpm_file_to_image(game.mlx, "sprites/burro_grass.xml", &game.collect.sprite.heigth, &game.collect.sprite.width);
	
}