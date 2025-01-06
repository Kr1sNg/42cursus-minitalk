/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:04:40 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/02 18:33:22 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	LIBRARY: stdlib.h
**	SYNOPSIS: convert string into int.
**
**	DESCRIPTION:
** 	The atoi() function converts the initial portion of the string pointed to
**	by 'nptr' to int.
**
**	RETURN VALUE:
**	The converted value or 0 on error. 
*/

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) != 0)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}

/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	char *str = "    2147483647";
	printf("atoi: %i\n", atoi(str));
	printf("ft_atoi: %i\n", ft_atoi(str));
}
*/