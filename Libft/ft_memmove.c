/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:29:02 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:57:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s = src;
	size_t		i;

	d = dst;
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = len;
		while (i-- > 0)
		{
			d[i] = s[i];
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	dest[20] = "Hello, World!";

	ft_memmove(dest + 7, dest, 5);
	printf("%s\n", dest); // Should print: Hello,Hello!
	return (0);
}*/
