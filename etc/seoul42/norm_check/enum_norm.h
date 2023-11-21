/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_norm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonpark <jeonpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:18:19 by jeonpark          #+#    #+#             */
/*   Updated: 2021/12/08 15:30:22 by jeonpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_NORM_H
# define ENUM_NORM_H

# define TEST1			1
# define TEST2		2
# define TEST3	3
//	# define TEST_DEFINE	(TEST + TEST)

enum
{
	first = TEST1 + TEST2,
	second,
	third = second + TEST3,
};

int	test(void);

#endif
