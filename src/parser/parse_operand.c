/*
** parse_operand.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 20:45:58 2013 timothee tosi
** Last update Sat Aug 10 11:17:55 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"my_flags.h"

const int		parse_operand(t_op *operation, t_content **tmp)
{
  if (((*tmp)->next != NULL) && (((*tmp)->next->type == L_BRACKET) ||
				 ((*tmp)->next->type == P_OPERAND) ||
				 ((*tmp)->next->type == N_OPERAND)))
    return (RETURN_FAILURE);
  *tmp = (*tmp)->next;
  return (RETURN_SUCCESS);
}
