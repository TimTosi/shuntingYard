/*
** linked_list.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 16:05:34 2013 timothee tosi
** Last update Fri Aug 16 15:41:07 2013 timothee tosi
*/

#ifndef			LINKED_LIST_H_
# define		LINKED_LIST_H_

# include		"content.h"

typedef	struct		s_linked_list
{
  unsigned int		size;
  t_content		*front;
  t_content		*back;
}			t_linked_list;

t_linked_list		*new_linked_list(void);
const int		push_front(t_linked_list *list, char *content);
const int		push_front_elem(t_linked_list *this, t_content *content);
const int		push_back(t_linked_list *list, char *content);
const int		push_back_elem(t_linked_list *this, t_content *content);
const int		push_n(t_linked_list *list, char *content, int n);
t_content		*pop_front_elem(t_linked_list *list);
void			show_list(t_linked_list *list);
void			show_reverse_list(t_linked_list *list);
void			show_node(t_linked_list *list);
void			free_node(t_content *container);

#endif			/* !LINKED_LIST_H_ */
