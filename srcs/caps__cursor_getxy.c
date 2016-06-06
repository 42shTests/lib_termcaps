#include "internal_caps.h"
#include "libft.h"


#define ANSI_Q_CURSORXY			"\033[6n"
#define ANSI_Q_CURSORXY_SIZE	 sizeof("\033[6n") - 1

bool	s_caps__cursor_getxy(int *x, int *y)
{
	t_internal_context	*context;
	char				buf[16];
	size_t				i;

	caps__get_context(&context);
	if (write(context->fd, ANSI_Q_CURSORXY, ANSI_Q_CURSORXY_SIZE) != ANSI_Q_CURSORXY_SIZE)
	{
		log_fatal("write() failed %s", "");
		return (false);
	}
	if (read(context->fd, buf, sizeof(buf)) == sizeof(buf))
	{
		log_fatal("buf too small %zu", (size_t)sizeof(buf));
		return (false);
	}
	i = sizeof("\033[") - 1;
	*y = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	i += sizeof(";") - 1;
	*x = ft_atoi(buf + i);
	return (true);
}

bool	caps__cursor_getxy(int *out_x, int *out_y)
{
	int		x;
	int		y;

	if (out_x != NULL)
		*out_x = 0;
	if (out_y != NULL)
		*out_y = 0;
	if (!s_caps__cursor_getxy(&x, &y))
	{
		log_error("s_caps__cursor_getxy() failed");
		return (false);
	}
	log_debug("x %d y %d", x, y);
	if (out_x)
		*out_x = x;
	if (out_y)
		*out_y = y;
	return (true);
}
