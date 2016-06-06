/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__win.c										:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/05/09 15:50:33 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/05/21 18:53:30 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "libft.h"
#include <sys/ioctl.h>
#include <termios.h>

extern size_t	caps__win(const char *cmd)
{
	t_internal_context	*context;
	struct winsize		win;

	if (!cmd)
	{
		log_fatal("cmd %p", (void *)cmd);
		return 0;
	}
	caps__get_context(&context);
	if (ioctl(context->fd, TIOCGWINSZ, &win) == -1)
	{
		log_error("ioctl() failed to get the windows size");
		return (0);
	}
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
