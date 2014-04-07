#include "chain_handle.h"

static void chain_base_ops_add(struct chan_handle *base, struct chan_handle *next)
{
	if (base->next)
		chain_base_add(base->next, next);
	else
		base->next = next;
}

static void chain_base_ops_handle(struct chan_handle *base, int data)
{
	if (base->next)
		chain_base_handle(base->next, data);
	else
		assert(0); /* virtual: assume override */
}

struct chain_base_ops chain_base_ops = {
	._add = chain_base_ops_add,
	.handle = chain_base_ops_handle,
};
struct chain_base_ops *chain_base_ops_get(struct chan_handle *base)
{
	return base->ops;
}

void chain_base_init(struct chan_handle *base)
{
	base->ops = &chain_base_ops;
	base->next = 0;
}

