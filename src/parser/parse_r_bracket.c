/*
** parse_r_bracket.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 15:12:09 2013 timothee tosi
** Last update Thu Aug  8 20:36:50 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"my_flags.h"

const int		parse_r_bracket(t_op *operation, t_content **tmp)
{
  if (((*tmp)->prev == NULL) || ((*tmp)->prev->type == L_BRACKET) ||
      ((*tmp)->prev->type == SP_OPERATOR) ||
      ((*tmp)->prev->type == WP_OPERATOR) ||
      (((*tmp)->next != NULL) && (((*tmp)->next->type == L_BRACKET) ||
				  ((*tmp)->next->type == N_OPERAND) ||
				  ((*tmp)->next->type == P_OPERAND))))
    return (RETURN_FAILURE);
  *tmp = (*tmp)->next;
  return (RETURN_SUCCESS);
}
