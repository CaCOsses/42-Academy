

#include "engine.h"

void
	display_crosshair(t_game *game)
{
	t_pos	pixel;
	int		i;

	if (game->window.size.x < 11 || game->window.size.y < 11)
		return ;
	i = -10;
	while (i < 10)
	{
		if (i < -4 || i > 4 || i == 0)
		{
			set_pos(&pixel, game->window.half.x + i, game->window.half.y);
			draw_pixel(&game->window, &pixel, 0x9922FF44);
			set_pos(&pixel, game->window.half.x, game->window.half.y + i);
			draw_pixel(&game->window, &pixel, 0x9922FF44);
		}
		i++;
	}
}
