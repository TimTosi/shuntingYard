/*
** wp_operator.c for Bistromathique in /home/tosi_t//BISTRO/src/parser/lexer
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 13:29:56 2013 timothee tosi
** Last update Fri Aug 16 16:03:29 2013 timothee tosi
*/

#include		"parser.h"
#include		"memory.h"
#include		"my_str.h"
#include		"my_flags.h"

static void		_define_id(t_op *operation, int *i)
{
  operation->lexeme_list->back->type = WP_OPERATOR;
  if (operation->input[*i] == operation->operators[2])
    operation->lexeme_list->back->operator = ADDITION;
  else
    operation->lexeme_list->back->operator = SUBTRACTION;
}

const int		wp_operator(t_op *operation, int *i)
{
  if ((operation->input[*i] == operation->operators[2]) ||
      (operation->input[*i] == operation->operators[3]))
    {
      if ((operation->input[*i] == operation->operators[3]) &&
	  ((in_array(operation->input[*i + 1], operation->operands))
	   != RETURN_FAILURE) &&
	  ((*i == 0) ||
	   (((in_array(operation->input[*i - 1], operation->operators))
	     != RETURN_FAILURE) &&
	    (operation->input[*i - 1] != operation->operators[1]))))
	return (n_operand(operation, i));
      if ((push_back(operation->lexeme_list,
		     my_strndup(&(operation->input[*i]), 1))) == RETURN_FAILURE)
	return (RETURN_FAILURE);
      _define_id(operation, i);
      *i += 1;
      return (RETURN_SUCCESS);
    }
  return (RETURN_FAILURE);
}
