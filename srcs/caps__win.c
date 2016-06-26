#include "internal_caps.h"
#include "libft.h"
#include <sys/ioctl.h>
#include <termios.h>

extern size_t	caps__win(const char *cmd)
{
	t_internal_context	*context;
	struct winsize		win;

	if (!cmd)
		return (0);
	caps__get_context(&context);
	if (ioctl(context->fd, TIOCGWINSZ, &win) == -1)
		return (0);
	if (!ft_strcmp(cmd, "co"))
	{
		return (win.ws_col);
	}
	else if (!ft_strcmp(cmd, "li"))
	{
		return (win.ws_row);
	}
	return (0);
}
