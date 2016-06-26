#include "internal_caps.h"
#include "termcap.h"

bool	caps__cursor_setxy(int x, int y)
{
	t_internal_context	*context;
	static char			*cm = NULL;
	char				*cmd;

	if (cm == NULL)
	{
		caps__get_context(&context);
		cm = tgetstr("cm", &context->buffaddr);
		if (!cm)
			return (0);
	}
	cmd = tgoto(cm, y, x);
	if (!cmd)
		return (0);
	caps__print(cmd, 0);
	return (TRUE);
}
