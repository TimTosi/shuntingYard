/*
** push_back_elem.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 30 14:06:46 2013 timothee tosi
** Last update Tue Jul 30 14:10:33 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"my_flags.h"

const int		push_back_elem(t_linked_list *this, t_content *content)
{
  content->next = NULL;
  content->prev = this->back;
  if (this->size == 0)
    this->front = content;
  else if (this->size == 1)
    {
      this->front = this->back;
      this->front->next = content;
    }
  else
    this->back->next = content;
  this->back = content;
  ++(this->size);
  return (RETURN_SUCCESS);
}
