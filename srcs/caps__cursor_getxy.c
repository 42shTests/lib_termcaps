#include "internal_caps.h"
#include "libft.h"


#define ANSI_Q_CURSORXY			"\033[6n"
#define ANSI_Q_CURSORXY_SIZE	 sizeof("\033[6n") - 1

bool	caps__cursor_getxy(int *x, int *y)
{
	char	buf[16];
	size_t	i;

	*x = 0;
	*y = 0;
	if (write(1, ANSI_Q_CURSORXY, ANSI_Q_CURSORXY_SIZE) != ANSI_Q_CURSORXY_SIZE)
	{
		log_fatal("write() failed %s", "");
		return 0;
	}
	if (read(0, buf, sizeof(buf)) == sizeof(buf))
	{
		log_fatal("buf too small %zu", (size_t)sizeof(buf));
		return 0;
	}
	i = sizeof("\033[") - 1;
	*x = ft_atoi(buf + i);
	while (ft_isdigit(buf[i]))
		i++;
	i += sizeof(";") - 1;
	*y = ft_atoi(buf + i);
	return (TRUE);
}

