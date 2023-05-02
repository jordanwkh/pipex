/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jhoekstr <jhoekstr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 16:29:56 by jhoekstr      #+#    #+#                 */
/*   Updated: 2022/02/25 18:40:30 by jhoekstr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*save;

	if (!*lst)
		*lst = new;
	else
	{
		save = ft_lstlast(*lst);
		save->next = new;
	}	
}
