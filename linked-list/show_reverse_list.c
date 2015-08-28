/*
** show_reverse_list.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sun Aug  4 11:35:32 2013 timothee tosi
** Last update Sun Aug  4 11:36:59 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"my_str.h"

void			show_reverse_list(t_linked_list *list)
{
  t_content		*tmp;

  tmp = list->back;
  while (tmp != NULL)
    {
      my_putstr(tmp->content);
      tmp = tmp->prev;
    }
}
