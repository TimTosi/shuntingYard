/*
** push_n.c for Bistromathique in /home/tosi_t//BISTRO/src/linked-list
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 16:04:09 2013 timothee tosi
** Last update Sun Jul 28 23:28:30 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"linked_list.h"
#include		"my_flags.h"
#include		"memory.h"

static void		add_node(t_linked_list **this, t_content **node, int n)
{
  t_content		*tmp;

  tmp = (*this)->front;
  while ((n-- > 0) && (tmp->next != NULL))
    tmp = tmp->next;
  if (tmp == (*this)->back)
    {
      (*node)->prev = tmp;
      tmp->next = *node;
      (*this)->back = *node;
    }
  else
    {
      if (tmp == (*this)->front)
	(*this)->front = *node;
      else
	{
	  tmp->prev->next = *node;
	  (*node)->prev = tmp->prev;
	}
      (*node)->next = tmp;
      tmp->prev = *node;
    }
}

const int		push_n(t_linked_list *this, char *content, int n)
{
  t_content		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (RETURN_FAILURE);
  tmp->content = content;
  tmp->next = NULL;
  tmp->prev = NULL;
  if (this->size == 0)
    {
      this->back = tmp;
      this->front = tmp;
    }
  else
    add_node(&this, &tmp, n);
  return (RETURN_SUCCESS);
}
