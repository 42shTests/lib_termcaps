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
#include "context.h"

void	caps__get_context(t_internal_context **out_context)
{
	*out_context = &internal_context;
}
