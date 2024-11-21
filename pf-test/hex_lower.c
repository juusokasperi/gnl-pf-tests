/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_lower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinta- <jrinta-@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:44:26 by jrinta-           #+#    #+#             */
/*   Updated: 2024/11/14 10:50:14 by jrinta-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_lower_hex(void)
{
	int ret;
	int ret_ft;
	printf("%s--------------------\n- TESTING L_HEX -\n--------------------%s\n\n", KYEL, KNRM);
	ret = printf("PF: %x\n", -2147483648);
	ret_ft = ft_printf("FT: %x\n", -2147483648);
	cmp(ret, ret_ft);
	ret = printf("PF: %x\n", 2147483647);
	ret_ft = ft_printf("FT: %x\n", 2147483647);
	cmp(ret, ret_ft);
	ret = printf("PF: %x\n", 0);
	ret_ft = ft_printf("FT: %x\n", 0);
	cmp(ret, ret_ft);
	printf("%s--------------------\n-  L_HEX TEST ENDS -\n--------------------%s\n", KYEL, KNRM);
}
