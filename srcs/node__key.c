#include "internal_caps.h"
#include "libft.h"

t_list		*node_key__create(const size_t size, const char *keycode, int (*func)())
{
	void		*addr;
	t_node_key	*new;

	addr = malloc(sizeof(t_node_key) + size);
	if (!addr)
		return (NULL);
	new = addr;
	new->keycode.bytes = addr + sizeof(t_node_key);
	ft_memcpy(new->keycode.bytes, keycode, size);
	new->keycode.size = size;
	new->func = func;
	return (&new->list);
}

void		list_key__destroy(t_list *head)
{
	t_list		*pos;
	t_list		*safe;
	t_node_key	*node;

	safe = head->next;
	while ((pos = safe) && pos != head && (safe = safe->next))
	{
		node = CONTAINER_OF(pos, t_node_key, list);
		free(node);
	}
}
