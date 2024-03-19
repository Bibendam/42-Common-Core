/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drizzo <drizzo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:47:08 by drizzo            #+#    #+#             */
/*   Updated: 2024/03/13 11:54:48 by drizzo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
/*
// Define a function to be used with ft_lstmap
void	*add_one(void *num)
{
	int	*new_num;

	new_num = malloc(sizeof(int));
	*new_num = *(int *)num + 1;
	return (new_num);
}

// Define a function to delete content
void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	t_list	*mapped_list;

	// Create a linked list with some numbers
	list = ft_lstnew(ft_strdup("1"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("2")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("3")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("4")));
	// Map the list to add one to each element
	mapped_list = ft_lstmap(list, &add_one, &del);
	// Display the original and mapped lists
	printf("Original list:\n");
	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	printf("\nMapped list (adding one to each element):\n");
	while (mapped_list)
	{
		printf("%s\n", (char *)mapped_list->content);
		mapped_list = mapped_list->next;
	}
	// Free the original and mapped lists
	ft_lstclear(&list, &del);
	ft_lstclear(&mapped_list, &del);
	return (0);
}*/
