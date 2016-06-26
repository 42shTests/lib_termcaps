/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__context.c									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/04/01 16:28:06 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/04/01 19:30:17 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "types.h"

void	caps__get_context(t_internal_context **out_context)
{
	static t_internal_context internal_context;

	internal_context.termtype = NULL;
	internal_context.buffaddr = NULL;
	internal_context.key_head = NULL;
	internal_context.key_head.prev = &internal_context.key_head;
	internal_context.key_head.next = &internal_context.key_head;
	internal_context.key_head = NULL;
	 = {
		.termtype = NULL,
		.buffaddr = NULL,
		.key_head = {
			.prev = &internal_context.key_head,
			.next = &internal_context.key_head
		},
	};

	*out_context = &internal_context;
}
