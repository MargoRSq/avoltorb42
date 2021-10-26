/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avoltorb <avoltorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:15:43 by avoltorb          #+#    #+#             */
/*   Updated: 2021/10/22 16:51:41 by avoltorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*next;

	if (!lst || !(*lst) || !(*del))
		return ;
	cur = (*lst);
	next = cur;
	while (cur)
	{
		next = cur->next;
		(*del)((void *)(cur->content));
		free(cur);
		cur = next;
	}
	*lst = NULL;
}
