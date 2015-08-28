/*
** n_operand.c for Bistromathique in /home/tosi_t//BISTRO/src/parser/lexer
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 13:53:46 2013 timothee tosi
** Last update Sun Sep  8 21:46:59 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"memory.h"
#include		"uniform.h"
#include		"my_str.h"
#include		"my_flags.h"

const int		n_operand(t_op *operation, int *i)
{
  int			j;

  j = 1;
  while ((in_array(operation->input[*i + j], operation->operands))
	 != RETURN_FAILURE)
    ++j;
  if ((push_back(operation->lexeme_list,
		 my_strndup(&(operation->input[*i]), j)))
      == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if ((operation->lexeme_list->back->content =
       uniform_result(operation->lexeme_list->back->content, operation->operands,
		      operation->operators[3])) == NULL)
    return (RETURN_FAILURE);
  operation->lexeme_list->back->type = N_OPERAND;
  *i += j;
  return (RETURN_SUCCESS);
}
