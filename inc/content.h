/*
** content.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 23 10:14:01 2013 timothee tosi
** Last update Sat Aug 10 12:31:21 2013 timothee tosi
*/

#ifndef			CONTENT_H_
# define		CONTENT_H_

typedef	struct		s_content
{
  void			*content;
  int			type;
  int			operator;
  struct s_content	*next;
  struct s_content	*prev;
}			t_content;

#endif			/* CONTENT_H_ */
