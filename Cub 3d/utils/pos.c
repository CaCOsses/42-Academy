
#include "utils.h"

void
	set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void
	copy_pos(t_pos *pos, t_pos *org)
{
	pos->x = org->x;
	pos->y = org->y;
}
