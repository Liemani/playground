/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmt_check_syntax_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:10:01 by jeonpark          #+#    #+#             */
/*   Updated: 2021/10/07 15:18:35 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lmt_check_syntax_error.h"

typedef int	(*t_error_check_function)(t_token *p_token);

int	lmt_error_if_pre_token_type_open_parenthesis(t_token *p_token)
{
	if (lmt_is_token_type_control_operator(p_token->pre))
		return (1);
}

int	lmt_check_syntax_error(t_token *p_first_token)
{
	static t_error_check_function	error_check_function_array[1]
		= {lmt_error_if_pre_token_type_open_parenthesis};
	t_token							*element;

	element = p_first_token;
	if (lmt_is_token_type_operator(p_first_token))
	{
		return (1);
	}
	while (element != NULL)
	{
		if (lmt_is_token_type_open_parenthesis(element))
			if (lmt_error_if_pre_token_type_open_parenthesis == 1)
				return (1);
		else if (lmt_is_token_type_close_parenthesis(element))
		{
			if (lmt_is_token_type_open_parenthesis(element->pre))
				return (1);
		}
		else if (lmt_is_token_type_control_operator(element))
		{
			if (lmt_is_token_type_control_operator(element->pre))
				return (1);
		}
		else if (lmt_is_token_type_redirection(element))
		{
			if (lmt_is_token_type_COMMAND(element->next))
				return (1);
		}
		element = element->next;
	}
}
