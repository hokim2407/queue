#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct      s_list
{
    struct s_list   *pre;
    int             value;
    struct s_list   *next;
}                   t_list;

typedef struct      s_queue
{
    t_list          *head;
    t_list          *tail;
}                   t_queue;

t_queue		        new_queue();
t_list		        *new_list(int value);
int			        push_queue(t_queue queue, t_list *new);
t_list		        *pop_queue(t_queue queue);
void		        print_queue(t_queue queue);
void		        free_queue(t_queue queue);
#endif