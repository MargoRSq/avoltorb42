/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margo <margo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:16:46 by margo             #+#    #+#             */
/*   Updated: 2021/10/23 09:39:14 by margo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst;
	t_list	*new_elem;
	
	if (!lst || !*f)
		return (NULL);

	new_elem = ft_lstnew(f(lst->content));
	if (!new_elem)
		return (NULL);
	res_lst = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&res_lst, del);
			break;
		}
		lst = lst->next;
		ft_lstadd_back(&res_lst, new_elem);
	}
	return (res_lst);
}
