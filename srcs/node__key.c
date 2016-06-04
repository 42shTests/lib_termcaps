#include "internal_caps.h"
#include "libft.h"

t_list		*node_key__create(const char *keycode, int (*func)())
{
	void		*addr;
	t_node_key	*new;
	size_t		keycode_size;

	keycode_size = ft_strlen(keycode);
	addr = malloc(sizeof(t_node_key) + keycode_size + 1);
	if (!addr)
		return (NULL);
	new = addr;
	new->keycode.bytes = addr + sizeof(t_node_key);
	ft_strcpy(new->keycode.bytes, keycode);
	new->keycode.size = keycode_size;
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
