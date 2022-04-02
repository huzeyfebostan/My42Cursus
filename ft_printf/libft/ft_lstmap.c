/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbostan <hbostan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:28:54 by hbostan           #+#    #+#             */
/*   Updated: 2022/02/13 14:30:40 by hbostan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	new = ft_lstnew(f(tmp->content));
	if (!new)
		return (NULL);
	tmp2 = new;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp2->next = ft_lstnew(f(tmp->content));
		if (!tmp2->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmp2 = tmp2->next;
	}
	return (new);
}
