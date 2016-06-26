#ifndef CONTEXT_H
# define CONTEXT_H

static t_internal_context g_internal_context = {
	.termtype = NULL,
	.buffaddr = NULL,
	.key_head = {
		.prev = &g_internal_context.key_head,
		.next = &g_internal_context.key_head
	},
};

void			caps__get_context(t_internal_context **out_context);
#endif
