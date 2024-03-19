/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:34:06 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:50:33 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate_empty_string(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str)
		str[0] = '\0';
	return (str);
}

static char	*copy_substring(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (allocate_empty_string());
	if (len > str_len - start)
		len = str_len - start;
	i = start;
	j = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (allocate_empty_string());
	return (copy_substring(s, start, len));
}
/*
int	main(void)
{
	char const *s = "Hello, World!";
	unsigned int start = 7;
	size_t len = 5;

	char *substring = ft_substr(s, start, len);
	if (substring)
	{
		printf("Substring: %s\n", substring);
		free(substring); // Don't forget to free the allocated memory
	}
	else
	{
		printf("Failed to allocate memory for substring\n");
	}

	return (0);
}*/
