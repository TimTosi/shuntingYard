/*
** push_front_elem.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 30 14:00:43 2013 timothee tosi
** Last update Tue Jul 30 14:06:28 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"my_flags.h"

const int		push_front_elem(t_linked_list *this, t_content *content)
{
  content->prev = NULL;
  content->next = this->front;
  if (this->size == 0)
    this->back = content;
  else if (this->size == 1)
    {
      this->back = this->front;
      this->back->prev = content;
    }
  else
    this->front->prev = content;
  this->front = content;
  ++(this->size);
  return (RETURN_SUCCESS);
}
