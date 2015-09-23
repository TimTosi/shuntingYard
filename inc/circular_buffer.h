/*
** circular_buffer.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 10:09:41 2013 timothee tosi
** Last update Tue Jul 23 10:27:39 2013 timothee tosi
*/

#ifndef			CIRCULAR_BUFFER_H_
# define		CIRCULAR_BUFFER_H_

typedef	struct		s_circular_buffer
{
  unsigned int		size;
  unsigned int		free_cells;
  t_content		*front;
  t_content		*back;
  t_content		*actual_pos;
  char			*(*pop_from)(struct s_circular_buffer *this);
  const int		(*push)(struct s_circular_buffer *this, char *content);
  void			(*show)(struct s_stack *this);
}			t_cbuffer;

t_cbuffer		*new_cbuffer(unsigned int size);

#endif			/* CIRCULAR_BUFFER_H_ */
