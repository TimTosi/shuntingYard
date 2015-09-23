/*
** push_back.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sat Jul 27 19:40:53 2013 timothee tosi
** Last update Fri Aug 16 14:21:59 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"memory.h"
#include		"my_flags.h"

const int		push_back(t_linked_list *this, char *content)
{
  t_content		*tmp;

  if ((content == NULL) || (tmp = malloc(sizeof(*tmp))) == NULL)
    return (RETURN_FAILURE);
  tmp->content = content;
  tmp->next = NULL;
  tmp->prev = this->back;
  if (this->size == 0)
    this->front = tmp;
  else if (this->size == 1)
    {
      this->front = this->back;
      this->front->next = tmp;
    }
  else
    this->back->next = tmp;
  this->back = tmp;
  ++(this->size);
  return (RETURN_SUCCESS);
}
