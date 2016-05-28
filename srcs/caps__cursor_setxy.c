#include "internal_caps.h"
#include "termcap.h"


bool	caps__cursor_setxy(int x, int y)
{
	char	*cm;
	char	*cmd;

	cm = tgetstr("cm", NULL);
	if (!cm)
	{
		log_fatal("tgetstr() failed %s", "");
		return 0;
	}
	cmd = tgoto(cm, y, x);
	if (!cmd)
	{
		log_fatal("tgoto() failed x %d y %d", x, y);
		return 0;
	}
	caps__print(cmd, 0);
	return (TRUE);
}
