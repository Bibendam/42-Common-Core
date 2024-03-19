/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:52:41 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/04 13:24:09 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>

void	test_ft_isalpha(void)
{
	printf("\033[0;32m");
	printf("Testing ft_isalpha...\n");
	printf("\033[0m");
	printf("ft_isalpha('a'): %s\n", ft_isalpha('a') ? "Passed" : "Failed");
	assert(ft_isalpha('a'));
	printf("ft_isalpha('Z'): %s\n", ft_isalpha('Z') ? "Passed" : "Failed");
	assert(ft_isalpha('Z'));
	printf("ft_isalpha('1'): %s\n", !ft_isalpha('1') ? "Passed" : "Failed");
	assert(!ft_isalpha('1'));
	printf("ft_isalpha('~'): %s\n", !ft_isalpha('~') ? "Passed" : "Failed");
	assert(!ft_isalpha('~'));
}

void	test_ft_isdigit(void)
{
	printf("\033[0;32m");
	printf("Testing ft_isdigit...\n");
	printf("\033[0m");
	printf("ft_isdigit('0'): %s\n", ft_isdigit('0') ? "Passed" : "Failed");
	assert(ft_isdigit('0'));
	printf("ft_isdigit('9'): %s\n", ft_isdigit('9') ? "Passed" : "Failed");
	assert(ft_isdigit('9'));
	printf("ft_isdigit('a'): %s\n", !ft_isdigit('a') ? "Passed" : "Failed");
	assert(!ft_isdigit('a'));
	printf("ft_isdigit('Z'): %s\n", !ft_isdigit('Z') ? "Passed" : "Failed");
	assert(!ft_isdigit('Z'));
}

void	test_ft_isalnum(void)
{
	printf("\033[0;32m");
	printf("Testing ft_isalnum...\n");
	printf("\033[0m");
	printf("ft_isalnum('0'): %s\n", ft_isalnum('0') ? "Passed" : "Failed");
	assert(ft_isalnum('0'));
	printf("ft_isalnum('a'): %s\n", ft_isalnum('a') ? "Passed" : "Failed");
	assert(ft_isalnum('a'));
	printf("ft_isalnum('~'): %s\n", !ft_isalnum('~') ? "Passed" : "Failed");
	assert(!ft_isalnum('~'));
}

void	test_ft_isascii(void)
{
	printf("\033[0;32m");
	printf("Testing ft_isascii...\n");
	printf("\033[0m");
	printf("ft_isascii(0): %s\n", ft_isascii(0) ? "Passed" : "Failed");
	assert(ft_isascii(0));
	printf("ft_isascii(127): %s\n", ft_isascii(127) ? "Passed" : "Failed");
	assert(ft_isascii(127));
	printf("ft_isascii(128): %s\n", !ft_isascii(128) ? "Passed" : "Failed");
	assert(!ft_isascii(128));
}

void	test_ft_isprint(void)
{
	printf("\033[0;32m");
	printf("Testing ft_isprint...\n");
	printf("\033[0m");
	printf("ft_isprint(32): %s\n", ft_isprint(32) ? "Passed" : "Failed");
	assert(ft_isprint(32));
	printf("ft_isprint(126): %s\n", ft_isprint(126) ? "Passed" : "Failed");
	assert(ft_isprint(126));
	printf("ft_isprint(31): %s\n", !ft_isprint(31) ? "Passed" : "Failed");
	assert(!ft_isprint(31));
}

void	test_ft_strlen(void)
{
	printf("\033[0;32m");
	printf("Testing ft_strlen...\n");
	printf("\033[0m");
	printf("ft_strlen(\"hello\"): %s\n", ft_strlen("hello") == 5 ? "Passed" : "Failed");
	assert(ft_strlen("hello") == 5);
	printf("ft_strlen(\"\"): %s\n", ft_strlen("") == 0 ? "Passed" : "Failed");
	assert(ft_strlen("") == 0);
}

void	test_ft_memset(void)
{
	char	str[50] = "This is string.h library function";

	printf("\033[0;32m");
	printf("Testing ft_memset...\n");
	printf("\033[0m");
	ft_memset(str, '$', 7);
	printf("ft_memset(str, '$', 7): %s\n", strcmp(str,
			"$$$$$$$ string.h library function") == 0 ? "Passed" : "Failed");
	assert(strcmp(str, "$$$$$$$ string.h library function") == 0);
}

void	test_ft_bzero(void)
{
	char	str[50] = "This is string.h library function";

	printf("\033[0;32m");
	printf("Testing ft_bzero...\n");
	printf("\033[0m");
	ft_bzero(str, 7);
	printf("ft_bzero(str, 7): %s\n", strncmp(str,
			"\0\0\0\0\0\0\0 is string.h library function",
			50) == 0 ? "Passed" : "Failed");
	assert(strncmp(str, "\0\0\0\0\0\0\0 is string.h library function",
			50) == 0);
}

void	test_ft_memcpy(void)
{
	const char	src[50] = "Hello World!";
	char		dest[50];

	printf("\033[0;32m");
	printf("Testing ft_memcpy...\n");
	printf("\033[0m");
	ft_memcpy(dest, src, strlen(src) + 1);
	printf("ft_memcpy(dest, src, strlen(src) + 1): %s\n", strcmp(dest,
			"Hello World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(dest, "Hello World!") == 0);
}

void	test_ft_memmove(void)
{
	char	dest[20] = "Hello, World!";

	printf("\033[0;32m");
	printf("Testing ft_memmove...\n");
	printf("\033[0m");
	ft_memmove(dest + 7, dest, 5);
	printf("ft_memmove(dest + 7, dest, 5): %s\n", strcmp(dest,
			"Hello, Hello!") == 0 ? "Passed" : "Failed");
	assert(strcmp(dest, "Hello, Hello!") == 0);
}

void	test_ft_strlcpy(void)
{
	char	dest[50];

	printf("\033[0;32m");
	printf("Testing ft_strlcpy...\n");
	printf("\033[0m");
	assert(ft_strlcpy(dest, "Hello, World!", 50) == 13);
	printf("ft_strlcpy(dest, \"Hello, World!\", 50): %s\n", strcmp(dest,
			"Hello, World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(dest, "Hello, World!") == 0);
}

void	test_ft_strlcat(void)
{
	char	dest[50] = "Hello";

	printf("\033[0;32m");
	printf("Testing ft_strlcat...\n");
	printf("\033[0m");
	assert(ft_strlcat(dest, ", World!", 50) == 13);
	printf("ft_strlcat(dest, \", World!\", 50): %s\n", strcmp(dest,
			"Hello, World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(dest, "Hello, World!") == 0);
}

void	test_ft_toupper(void)
{
	printf("\033[0;32m");
	printf("Testing ft_toupper...\n");
	printf("\033[0m");
	printf("ft_toupper('a'): %s\n",
		ft_toupper('a') == 'A' ? "Passed" : "Failed");
	assert(ft_toupper('a') == 'A');
	printf("ft_toupper('z'): %s\n",
		ft_toupper('z') == 'Z' ? "Passed" : "Failed");
	assert(ft_toupper('z') == 'Z');
	printf("ft_toupper('A'): %s\n",
		ft_toupper('A') == 'A' ? "Passed" : "Failed");
	assert(ft_toupper('A') == 'A');
	printf("ft_toupper('1'): %s\n",
		ft_toupper('1') == '1' ? "Passed" : "Failed");
	assert(ft_toupper('1') == '1');
}

void	test_ft_tolower(void)
{
	printf("\033[0;32m");
	printf("Testing ft_tolower...\n");
	printf("\033[0m");
	printf("ft_tolower('A'): %s\n",
		ft_tolower('A') == 'a' ? "Passed" : "Failed");
	assert(ft_tolower('A') == 'a');
	printf("ft_tolower('Z'): %s\n",
		ft_tolower('Z') == 'z' ? "Passed" : "Failed");
	assert(ft_tolower('Z') == 'z');
	printf("ft_tolower('a'): %s\n",
		ft_tolower('a') == 'a' ? "Passed" : "Failed");
	assert(ft_tolower('a') == 'a');
	printf("ft_tolower('1'): %s\n",
		ft_tolower('1') == '1' ? "Passed" : "Failed");
	assert(ft_tolower('1') == '1');
}

void	test_ft_strchr(void)
{
	printf("\033[0;32m");
	printf("Testing ft_strchr...\n");
	printf("\033[0m");
	printf("ft_strchr(\"Hello, World!\", 'W'): %s\n",
		strcmp(ft_strchr("Hello,World!", 'W'),
			"World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(ft_strchr("Hello, World!", 'W'), "World!") == 0);
	printf("ft_strchr(\"Hello, World!\", 'z'): %s\n", ft_strchr("Hello, World!",
			'z') == NULL ? "Passed" : "Failed");
	assert(ft_strchr("Hello, World!", 'z') == NULL);
}

void	test_ft_strrchr(void)
{
	printf("\033[0;32m");
	printf("Testing ft_strrchr...\n");
	printf("\033[0m");
	printf("ft_strrchr(\"Hello, World!\", 'o'): %s\n",
		strcmp(ft_strrchr("Hello,World!", 'o'),
			"orld!") == 0 ? "Passed" : "Failed");
	assert(strcmp(ft_strrchr("Hello, World!", 'o'), "orld!") == 0);
	printf("ft_strrchr(\"Hello, World!\", 'z'): %s\n",
		ft_strrchr("Hello,World!", 'z') == NULL ? "Passed" : "Failed");
	assert(ft_strrchr("Hello, World!", 'z') == NULL);
}

void	test_ft_strncmp(void)
{
	printf("\033[0;32m");
	printf("Testing ft_strncmp...\n");
	printf("\033[0m");
	printf("ft_strncmp(\"Hello\", \"Hello, World!\", 5): %s\n",
		ft_strncmp("Hello", "Hello, World!", 5) == 0 ? "Passed" : "Failed");
	assert(ft_strncmp("Hello", "Hello, World!", 5) == 0);
	printf("ft_strncmp(\"Hello\", \"Hello, World!\", 6): %s\n",
		ft_strncmp("Hello", "Hello, World!", 6) != 0 ? "Passed" : "Failed");
	assert(ft_strncmp("Hello", "Hello, World!", 6) != 0);
}

void	test_ft_memchr(void)
{
	printf("\033[0;32m");
	printf("Testing ft_memchr...\n");
	printf("\033[0m");
	printf("memcmp(ft_memchr(\"Hello, World!\", 'W', 13), \"World!\", 6): %s\n",
		memcmp(ft_memchr("Hello, World!", 'W', 13), "World!",
			6) == 0 ? "Passed" : "Failed");
	assert(memcmp(ft_memchr("Hello, World!", 'W', 13), "World!", 6) == 0);
	printf("ft_memchr(\"Hello, World!\", 'z', 13): %s\n",
		ft_memchr("Hello,World!", 'z', 13) == NULL ? "Passed" : "Failed");
	assert(ft_memchr("Hello, World!", 'z', 13) == NULL);
}

void	test_ft_memcmp(void)
{
	printf("\033[0;32m");
	printf("Testing ft_memcmp...\n");
	printf("\033[0m");
	printf("ft_memcmp(\"Hello\", \"Hello, World!\", 5): %s\n",
		ft_memcmp("Hello", "Hello, World!", 5) == 0 ? "Passed" : "Failed");
	assert(ft_memcmp("Hello", "Hello, World!", 5) == 0);
	printf("ft_memcmp(\"Hello\", \"Hello, World!\", 6): %s\n",
		ft_memcmp("Hello", "Hello, World!", 6) != 0 ? "Passed" : "Failed");
	assert(ft_memcmp("Hello", "Hello, World!", 6) != 0);
}

void	test_ft_strnstr(void)
{
	printf("\033[0;32m");
	printf("Testing ft_strnstr...\n");
	printf("\033[0m");
	printf("strcmp(ft_strnstr(\"Hello, World!\", \"World\", 13),\"World!\"):%s\n",
	strcmp(ft_strnstr("Hello, World!", "World", 13),
	"World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(ft_strnstr("Hello, World!", "World", 13), "World!") == 0);
	printf("ft_strnstr(\"Hello, World!\", \"world\", 13): %s\n",
		ft_strnstr("Hello, World!", "world", 13) == NULL ? "Passed" : "Failed");
	assert(ft_strnstr("Hello, World!", "world", 13) == NULL);
}

void	test_ft_atoi(void)
{
	printf("\033[0;32m");
	printf("Testing ft_atoi...\n");
	printf("\033[0m");
	printf("ft_atoi(\"123\"): %s\n",
		ft_atoi("123") == 123 ? "Passed" : "Failed");
	assert(ft_atoi("123") == 123);
	printf("ft_atoi(\"-123\"): %s\n", ft_atoi("-123") ==
		-123 ? "Passed" : "Failed");
	assert(ft_atoi("-123") == -123);
	printf("ft_atoi(\"   123\"): %s\n",
		ft_atoi("   123") == 123 ? "Passed" : "Failed");
	assert(ft_atoi("   123") == 123);
	printf("ft_atoi(\"abc\"): %s\n", ft_atoi("abc") == 0 ? "Passed" : "Failed");
	assert(ft_atoi("abc") == 0);
}

void	test_ft_strdup(void)
{
	char	*src;
	char	*dup;

	src = "Hello, World!";
	dup = ft_strdup(src);
	printf("\033[0;32m");
	printf("Testing ft_strdup...\n");
	printf("\033[0m");
	printf("strcmp(dup, src): %s\n", strcmp(dup,
			src) == 0 ? "Passed" : "Failed");
	assert(strcmp(dup, src) == 0);
	free(dup);
}

void	test_ft_calloc(void)
{
	size_t	count;
	size_t	size;
	int		*arr;

	count = 10;
	size = sizeof(int);
	arr = (int *)ft_calloc(count, size);
	printf("\033[0;32m");
	printf("Testing ft_calloc...\n");
	printf("\033[0m");
	for (size_t i = 0; i < count; i++)
	{
		printf("arr[%zu]: %s\n", i, arr[i] == 0 ? "Passed" : "Failed");
		assert(arr[i] == 0);
	}
	free(arr);
}

void	test_ft_substr(void)
{
	char	*s;
	char	*sub;

	s = "Hello, World!";
	sub = ft_substr(s, 7, 5);
	printf("\033[0;32m");
	printf("Testing ft_substr...\n");
	printf("\033[0m");
	printf("strcmp(sub, \"World\"): %s\n", strcmp(sub,
			"World") == 0 ? "Passed" : "Failed");
	assert(strcmp(sub, "World") == 0);
	free(sub);
}

void	test_ft_strjoin(void)
{
	char	*s1;
	char	*s2;
	char	*join;

	s1 = "Hello";
	s2 = ", World!";
	join = ft_strjoin(s1, s2);
	printf("\033[0;32m");
	printf("Testing ft_strjoin...\n");
	printf("\033[0m");
	printf("strcmp(join, \"Hello, World!\"): %s\n", strcmp(join, "Hello, World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(join, "Hello, World!") == 0);
	free(join);
}

void	test_ft_strtrim(void)
{
	char	*s1;
	char	*set;
	char	*trim;

	printf("\033[0;32m");
	printf("Testing ft_strtrim...\n");
	printf("\033[0m");
	s1 = "   Hello, World!   ";
	set = " ";
	trim = ft_strtrim(s1, set);
	printf("strcmp(trim, \"Hello, World!\"): %s\n", strcmp(trim, "Hello, World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(trim, "Hello, World!") == 0);
	free(trim);
}

void	test_ft_split(void)
{
	char	*s;
	char	**split;

	printf("\033[0;32m");
	printf("Testing ft_split...\n");
	printf("\033[0m");
	s = "Hello, World!";
	split = ft_split(s, ',');
	printf("strcmp(split[0], \"Hello\"): %s\n", strcmp(split[0],
			"Hello") == 0 ? "Passed" : "Failed");
	assert(strcmp(split[0], "Hello") == 0);
	printf("strcmp(split[1], \" World!\"): %s\n", strcmp(split[1],
			" World!") == 0 ? "Passed" : "Failed");
	assert(strcmp(split[1], " World!") == 0);
	// Remember to free each string and the array itself
	for (int i = 0; split[i] != NULL; i++)
	{
		free(split[i]);
	}
	free(split);
}

void	test_ft_itoa(void)
{
	printf("\033[0;32m");
	printf("Testing ft_itoa...\n");
	printf("\033[0m");
	printf("strcmp(ft_itoa(123), \"123\"): %s\n", strcmp(ft_itoa(123),
			"123") == 0 ? "Passed" : "Failed");
	assert(strcmp(ft_itoa(123), "123") == 0);
	printf("strcmp(ft_itoa(-123555), \"-123555\"): %s\n", strcmp(ft_itoa(-123555),
			"-123555") == 0 ? "Passed" : "Failed");
	assert(strcmp(ft_itoa(-123555), "-123555") == 0);
}

char	test_func(unsigned int, char c)
{
	return (c + 1);
}

void	test_ft_strmapi(void)
{
	char	*s;
	char	*mapped;

	printf("\033[0;32m");
	printf("Testing ft_strmapi...\n");
	printf("\033[0m");
	s = "Hello";
	mapped = ft_strmapi(s, test_func);
	printf("strcmp(mapped, \"Ifmmp\"): %s\n", strcmp(mapped,
			"Ifmmp") == 0 ? "Passed" : "Failed");
	assert(strcmp(mapped, "Ifmmp") == 0);
	free(mapped);
}

void	test_func_iteri(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c = (*c - 'a' + i) % 26 + 'a';
	}
	else if (*c >= 'A' && *c <= 'Z')
	{
		*c = (*c - 'A' + i) % 26 + 'A';
	}
}

void	test_ft_striteri(void)
{
	char	s[] = "Hello";

	printf("\033[0;32m");
	printf("Testing ft_striterti...\n");
	printf("\033[0m");
	ft_striteri(s, test_func_iteri);
	printf("strcmp(s, \"Hfnos\"): %s\n", strcmp(s,
			"Hfnos") == 0 ? "Passed" : "Failed");
	assert(strcmp(s, "Hfnos") == 0);
}

void	test_ft_putchar_fd(void)
{
	int		fd;
	char	c;

	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	ft_putchar_fd('H', fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	printf("\033[0;32m");
	printf("Testing ft_putchar_fd...\n");
	printf("\033[0m");
	read(fd, &c, 1);
	close(fd);
	printf("c == 'H': %s\n", c == 'H' ? "Passed" : "Failed");
	assert(c == 'H');
}

void	test_ft_putstr_fd(void)
{
	int		fd;
	char	s[6];

	printf("\033[0;32m");
	printf("Testing ft_putstr_fd...\n");
	printf("\033[0m");
	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	ft_putstr_fd("Hello", fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	read(fd, s, 5);
	s[5] = '\0';
	close(fd);
	printf("strcmp(s, \"Hello\"): %s\n", strcmp(s, "Hello") == 0 ? "Passed" : "Failed");
	assert(strcmp(s, "Hello") == 0);
}

void	test_ft_putendl_fd(void)
{
	int		fd;
	char	s[7];
	printf("\033[0;32m");
	printf("Testing ft_putendl_fd...\n");
	printf("\033[0m");
	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	ft_putendl_fd("Hello", fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	read(fd, s, 6);
	s[6] = '\0';
	close(fd);
	printf("strcmp(s, \"Hello\\n\"): %s\n", strcmp(s, "Hello\n") == 0 ? "Passed" : "Failed");
	assert(strcmp(s, "Hello\n") == 0);
}

void	test_ft_putnbr_fd(void)
{
	int		fd;
	char	s[4];

	printf("\033[0;32m");
	printf("Testing ft_putnbr_fd...\n");
	printf("\033[0m");
	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	ft_putnbr_fd(123, fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	read(fd, s, 3);
	s[3] = '\0';
	close(fd);
	printf("strcmp(s, \"123\"): %s\n", strcmp(s, "123") == 0 ? "Passed" : "Failed");
	assert(strcmp(s, "123") == 0);
}

void	del_func(void *content)
{
	free(content);
}

void	*add_one(void *content)
{
	int	*new_content;

	new_content = malloc(sizeof(int));
	*new_content = *(int *)content + 1;
	return (new_content);
}

void	del(void *content)
{
	free(content);
}

void	*map_func(void *content)
{
	int	*new_content;

	new_content = malloc(sizeof(int));
	*new_content = *(int *)content + 1;
	return (new_content);
}

void	test_ft_lstnew(void)
{
	int		*content;
	t_list	*node;

	printf("\033[0;32m");
	printf("Testing ft_lstnew...\n");
	printf("\033[0m");
	content = malloc(sizeof(int));
	*content = 123;
	node = ft_lstnew(content);
	printf("*(int *)node->content == 123: %s\n", *(int *)node->content == 123 ? "Passed" : "Failed");
	assert(*(int *)node->content == 123);
	assert(node->next == NULL);
	ft_lstdelone(node, del_func);
}

void	test_ft_lstadd_front(void)
{
	t_list	*lst;
	int		*content;
	t_list	*new_node;

	printf("\033[0;32m");
	printf("Testing ft_lstadd_front...\n");
	printf("\033[0m");
	lst = NULL;
	content = malloc(sizeof(int));
	*content = 123;
	new_node = ft_lstnew(content);
	ft_lstadd_front(&lst, new_node);
	printf("lst == new_node: %s\n", lst == new_node ? "Passed" : "Failed");
	assert(lst == new_node);
	ft_lstdelone(lst, del_func);
}

void	test_ft_lstsize(void)
{
	t_list	*lst;
	int		*content;
	t_list	*new_node;

	printf("\033[0;32m");
	printf("Testing ft_lstsize...\n");
	printf("\033[0m");
	lst = NULL;
	for (int i = 0; i < 5; i++)
	{
		content = malloc(sizeof(int));
		*content = i;
		new_node = ft_lstnew(content);
		ft_lstadd_front(&lst, new_node);
	}
	printf("ft_lstsize(lst) == 5: %s\n", ft_lstsize(lst) == 5 ? "Passed" : "Failed");
	assert(ft_lstsize(lst) == 5);
	ft_lstclear(&lst, del_func);
}

void	test_ft_lstlast(void)
{
	t_list	*lst;
	t_list	*last_node;
	int		*content;
	t_list	*new_node;

	printf("\033[0;32m");
	printf("Testing ft_lstlast...\n");
	printf("\033[0m");
	lst = NULL;
	last_node = NULL;
	for (int i = 0; i < 5; i++)
	{
		content = malloc(sizeof(int));
		*content = i;
		new_node = ft_lstnew(content);
		if (i == 0)
		{
			last_node = new_node;
		}
		ft_lstadd_front(&lst, new_node);
	}
	printf("ft_lstlast(lst) == last_node: %s\n", ft_lstlast(lst) == last_node ? "Passed" : "Failed");
	assert(ft_lstlast(lst) == last_node);
	ft_lstclear(&lst, del_func);
}

void	test_ft_lstadd_back(void)
{
	t_list	*lst;
	int		*content;
	t_list	*new_node;

	printf("\033[0;32m");
	printf("Testing ft_lstadd_back...\n");
	printf("\033[0m");
	lst = NULL;
	content = malloc(sizeof(int));
	*content = 123;
	new_node = ft_lstnew(content);
	ft_lstadd_back(&lst, new_node);
	printf("ft_lstlast(lst) == new_node: %s\n", ft_lstlast(lst) == new_node ? "Passed" : "Failed");
	assert(ft_lstlast(lst) == new_node);
	ft_lstdelone(lst, del_func);
}

void	test_ft_lstdelone(void)
{
	int		*content;
	t_list	*node;

	content = malloc(sizeof(int));
	*content = 123;
	node = ft_lstnew(content);
	ft_lstdelone(node, del_func);
}

void	test_ft_lstclear(void)
{
	t_list	*lst;
	int		*content;
	t_list	*new_node;

	lst = NULL;
	for (int i = 0; i < 5; i++)
	{
		content = malloc(sizeof(int));
		*content = i;
		new_node = ft_lstnew(content);
		ft_lstadd_front(&lst, new_node);
	}
	ft_lstclear(&lst, del_func);
}

void	test_ft_lstiter(void)
{
	t_list	*lst;
	int		*content;
	t_list	*new_node;

	lst = NULL;
	for (int i = 0; i < 5; i++)
	{
		content = malloc(sizeof(int));
		*content = i;
		new_node = ft_lstnew(content);
		ft_lstadd_front(&lst, new_node);
	}
	ft_lstiter(lst, del_func);
}

void	test_ft_lstmap(void)
{
	t_list	*lst;
	int		*num;
	t_list	*mapped_lst;
	t_list	*temp;

	printf("\033[0;32m");
	printf("Testing ft_lstmap...\n");
	printf("\033[0m");
	lst = NULL;
	for (int i = 1; i <= 4; i++)
	{
		num = malloc(sizeof(int));
		*num = i;
		ft_lstadd_back(&lst, ft_lstnew(num));
	}
	mapped_lst = ft_lstmap(lst, add_one, del);
	temp = mapped_lst;
	for (int i = 1; i <= 4; i++)
	{
		printf("*(int *)temp->content == i + 1: %s\n", *(int *)temp->content == i + 1 ? "Passed" : "Failed");
		assert(*(int *)temp->content == i + 1);
		temp = temp->next;
	}
	ft_lstclear(&mapped_lst, del);
}
int	main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strnstr();
	test_ft_atoi();
	test_ft_strdup();
	test_ft_calloc();
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();
	test_ft_striteri();
	test_ft_putchar_fd();
	test_ft_putstr_fd();
	test_ft_putendl_fd();
	test_ft_putnbr_fd();
	test_ft_lstnew();
	test_ft_lstadd_front();
	test_ft_lstsize();
	test_ft_lstlast();
	test_ft_lstadd_back();
	test_ft_lstdelone();
	test_ft_lstclear();
	test_ft_lstiter();
	test_ft_lstmap();
	printf("\033[0;32m");
	printf("All tests passed!\n");
	printf("\033[0m");
	return (0);
}

// Compile with "cc -Wall -Werror -Wextra -o tests tests.c -L. -lft"
