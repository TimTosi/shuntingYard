/*
** push_front.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sat Jul 27 19:56:14 2013 timothee tosi
** Last update Fri Aug 16 14:22:53 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"my_flags.h"

const int		push_front(t_linked_list *this, char *content)
{
  t_content		*tmp;

  if ((content == NULL) || (tmp = malloc(sizeof(*tmp))) == NULL)
    return (RETURN_FAILURE);
  tmp->content = content;
  tmp->prev = NULL;
  tmp->next = this->front;
  if (this->size == 0)
    this->back = tmp;
  else if (this->size == 1)
    {
      this->back = this->front;
      this->back->prev = tmp;
    }
  else
    this->front->prev = tmp;
  this->front = tmp;
  ++(this->size);
  return (RETURN_SUCCESS);
}
