/*
** pop_front_elem.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 30 15:44:35 2013 timothee tosi
** Last update Tue Jul 30 17:33:26 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"

t_content		*pop_front_elem(t_linked_list *list)
{
  t_content		*tmp;

  if ((list == NULL) || (list->front == NULL))
    return (NULL);
  tmp = list->front;
  if (list->size == 1)
    {
      list->front = NULL;
      list->back = NULL;
    }
  else if (list->size == 2)
    {
      list->front = list->back;
      list->back->prev = NULL;
    }
  else
    {
      list->front = list->front->next;
      list->front->prev = NULL;
    }
  --(list->size);
  tmp->prev = NULL;
  tmp->next = NULL;
  return (tmp);
}
