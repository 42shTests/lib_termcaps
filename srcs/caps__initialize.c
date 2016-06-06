/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__initialize.c									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/04/01 17:20:28 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/04/01 17:25:07 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "types.h"

#include <stdlib.h>
#include <termcap.h>

static bool	internal_caps__initialize_caps(t_internal_context *caps)
{
	char	*capcodes[] = {
		"nd", "le", "up", "do", "dc", "ce", "cd", "cr"
	};
	size_t	i;

	caps->caps_size = sizeof(caps->caps) / sizeof(caps->caps[0]);
	i = 0;
	while (i < caps->caps_size - 1)
	{
		caps->caps[i] = tgetstr(capcodes[i], &caps->buffaddr);
		if (i != caps->caps_size - 1 && !caps->caps[i])
		{
			log_fatal("tgetstr() failed on %s", capcodes[i]);
			return (0);
		}
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
	if (!termtype)
		log_info("getenv(\"TERM\") failed %s", "");
	caps->termtype = termtype;
	if (!tgetent(caps->termbuffer, termtype))
	{
		log_fatal("tgetent() failed termtype %s", termtype ? termtype : "(Null)");
		return (0);
	}
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
	{
		log_fatal("fd %d", fd);
		return (0);
	}
	caps__get_context(&caps);
	caps->fd = fd;
	if (!internal_caps__tgetent(caps))
	{
		log_fatal("interal_caps__tgetent() failed %s", "");
		return (0);
	}
	if (!internal_caps__initialize_caps(caps))
	{
		log_fatal("internal_caps__initialize_caps() failed %s", "");
		return (0);
	}
	return (1);
}
