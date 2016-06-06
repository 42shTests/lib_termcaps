/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::	  */
/*	 caps__finalize.c									:+:		 :+:	:+:	  */
/*													  +:+ +:+		  +:+	  */
/*	 By: abombard <marvin@42.fr>					+#+	 +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2016/04/01 16:32:25 by abombard		   #+#	  #+#			  */
/*	 Updated: 2016/04/01 16:32:26 by abombard		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "internal_caps.h"
#include "types.h"


bool	caps__finalize(void)
{
	t_internal_context	*context;

	caps__get_context(&context);
	list_key__destroy(&context->key_head);
	return (TRUE);
}
