#include "internal_caps.h"
#include "types.h"

#include <stdlib.h>
#include <termcap.h>

static int	s_init_capscode(char **capcodes)
{
	capcodes[0] = "nd";
	capcodes[1] = "le";
	capcodes[2] = "up";
	capcodes[3] = "do";
	capcodes[4] = "dc";
	capcodes[5] = "ce";
	capcodes[6] = "cd";
	capcodes[7] = "cl";
	capcodes[8] = "cr";
	return (1);
}

static bool	internal_caps__initialize_caps(t_internal_context *caps)
{
	char	*capcodes[CAPS__CAP_COUNT];
	size_t	i;

	s_init_capscode(capcodes);
	caps->caps_size = sizeof(caps->caps) / sizeof(caps->caps[0]);
	i = 0;
	while (i < caps->caps_size - 1)
	{
		caps->caps[i] = tgetstr(capcodes[i], &caps->buffaddr);
		if (i != caps->caps_size - 1 && !caps->caps[i])
			return (0);
		i++;
	}
	caps->caps[i] = tgetstr("bc", &caps->buffaddr);
	if (!caps->caps[i])
	{
		caps->caps[i] = "\b";
	}
	return (1);
}

static bool	internal_caps__tgetent(t_internal_context *caps)
{
	char		*termtype;
	char		*temp;

	termtype = CAPS__TERMTYPE;
	caps->termtype = termtype;
	if (!tgetent(caps->termbuffer, termtype))
		return (0);
	caps->buffaddr = caps->termbuffer;
	temp = tgetstr("pc", &caps->buffaddr);
	PC = temp ? *temp : 0;
	BC = tgetstr("le", &caps->buffaddr);
	UP = tgetstr("up", &caps->buffaddr);
	return (1);
}

bool		caps__initialize(const int fd)
{
	t_internal_context	*caps;

	if (fd < 0)
		return (0);
	caps__get_context(&caps);
	caps->fd = fd;
	if (!internal_caps__tgetent(caps))
		return (0);
	if (!internal_caps__initialize_caps(caps))
		return (0);
	return (1);
}
