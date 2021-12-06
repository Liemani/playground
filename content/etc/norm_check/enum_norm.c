/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:18:16 by jeonpark          #+#    #+#             */
/*   Updated: 2021/12/06 14:13:41 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "enum_norm.h"

int	test(void)
{
	printf("there \n");
	return (0);
}

int	main(void)
{
	printf("hi ");
	test();
	printf("e_test.first -> [%d] \n", first);
	printf("e_test.second -> [%d] \n", second);
	return (0);
}
