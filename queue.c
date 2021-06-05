/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokim <hokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:32:13 by hokim             #+#    #+#             */
/*   Updated: 2021/06/05 16:34:59 by hokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue		new_queue(void)
{
	t_queue queue;

	queue.head = new_list(0);
	queue.tail = new_list(0);
	queue.head->next = queue.tail;
	queue.tail->pre = queue.head;
	return (queue);
}

t_list		*new_list(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->pre = NULL;
	new->value = value;
	new->next = NULL;
	return (new);
}

int			push_queue(t_queue queue, t_list *new)
{
	t_list *tail;

	if (queue.tail == NULL)
		return (0);
	tail = queue.tail;
	new->pre = tail->pre;
	new->next = tail;
	tail->pre->next = new;
	tail->pre = new;
	return (1);
}

t_list		*pop_queue(t_queue queue)
{
	t_list	*first_list;
	t_list	*head;

	if (queue.head == NULL)
		return (NULL);
	head = queue.head;
	first_list = head->next;
	head->next = first_list->next;
	first_list->next->pre = head;
	first_list->pre = NULL;
	first_list->next = NULL;
	return (first_list);
}

void		free_queue(t_queue queue)
{
	t_list	*temp;

	temp = queue.head;
	while (temp != queue.tail)
	{
		temp = temp->next;
		free(temp->pre);
	}
	free(temp);
}

void		print_queue(t_queue queue)
{
	t_list	*temp;

	temp = queue.head->next;
	while (temp != queue.tail)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
