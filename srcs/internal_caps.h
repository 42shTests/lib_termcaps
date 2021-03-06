#ifndef INTERNAL_CAPS_H
# define INTERNAL_CAPS_H

# include "caps.h"
# include "types.h"
# include "list.h"
# include <unistd.h>

# define CAPS__MAP_KEY_COUNT		144
# define CAPS__CAP_COUNT			10
# define TERMCAPS_BUFFER_MAX 4096

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
	char		termbuffer[TERMCAPS_BUFFER_MAX];
	char		*buffaddr;

	t_list		key_head;

	size_t		caps_size;
	char		*caps[CAPS__CAP_COUNT];
}				t_internal_context;

/*
** getter for caps
*/
extern void		caps__get_context (t_internal_context **context);

t_list			*node_key__create(const size_t size,
									const char *keycode, int (*func)());
void			list_key__destroy(t_list *head);

#endif
