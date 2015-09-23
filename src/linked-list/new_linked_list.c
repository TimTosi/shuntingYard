/*
** new_linked_list.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 16:04:59 2013 timothee tosi
** Last update Sat Jul 27 20:33:54 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"

t_linked_list		*new_linked_list(void)
{
  t_linked_list		*linked_list;

  if ((linked_list = malloc(sizeof(*linked_list))) == NULL)
    return (NULL);
  linked_list->size = 0;
  linked_list->front = NULL;
  linked_list->back = NULL;
  return (linked_list);
}
