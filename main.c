/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokim <hokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:32:09 by hokim             #+#    #+#             */
/*   Updated: 2021/06/05 16:33:37 by hokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int			main(int argc, char **argv)
{
	t_queue	queue;
	t_list	*poped_list;
	int		i;

	if (argc < 2)
		return (printf("no arg\n"));
	queue = new_queue();
	printf("push ");
	i = 0;
	while (++i < argc)
	{
		printf("%s ", argv[i]);
		push_queue(queue, new_list(atoi(argv[i])));
	}
	printf("\npop 1 arg from queue\n");
	poped_list = pop_queue(queue);
	printf("=============== result ===============\n");
	print_queue(queue);
	printf("poped : %d\n", poped_list->value);
	free(poped_list);
	free_queue(queue);
}
