/*
** show_node.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sun Jul 28 21:40:15 2013 timothee tosi
** Last update Wed Aug  7 14:21:21 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"my_str.h"

void			show_node(t_linked_list *list)
{
  t_content		*tmp;

  tmp = list->front;
  while (tmp != NULL)
    {
      my_putstr(tmp->content);
      my_putstr("\n");
      tmp = tmp->next;
    }
}
