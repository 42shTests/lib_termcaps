/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 internal_caps.h									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/04/01 15:58:22 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/04/01 19:29:50 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef INTERNAL_CAPS_H
# define INTERNAL_CAPS_H

# include "caps.h"
# include "types.h"
# include "list.h"
# include <unistd.h>

# define CAPS__MAP_KEY_COUNT		144
# define CAPS__CAP_COUNT			10

typedef struct	s_node_key
{
	t_buffer	keycode;
	int			(*func)();
	t_list		list;
}				t_node_key;

typedef struct	s_internal_context
{
	int			fd;
	char		*termtype;
	char		termbuffer[2048];
	char		*buffaddr;

	t_list		key_head;

	size_t		caps_size;
	char		*caps[CAPS__CAP_COUNT];
}				t_internal_context;


/*
** getter for caps
*/
extern void		caps__get_context (t_internal_context **context);

t_list			*node_key__create(const size_t size, const char *keycode, int (*func)());
void			list_key__destroy(t_list *head);

#endif
