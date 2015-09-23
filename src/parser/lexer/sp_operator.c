/*
** sp_operator.c for Bistromathique in /home/tosi_t//BISTRO/src/parser/lexer
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 13:25:58 2013 timothee tosi
** Last update Sat Aug 10 12:36:20 2013 timothee tosi
*/

#include		"parser.h"
#include		"memory.h"
#include		"my_flags.h"

static void		_define_id(t_op *operation, int *i)
{
  operation->lexeme_list->back->type = SP_OPERATOR;
  if (operation->input[*i] == operation->operators[4])
    operation->lexeme_list->back->operator = DIVISION;
  else if (operation->input[*i] == operation->operators[5])
    operation->lexeme_list->back->operator = MULTIPLICATION;
  else
    operation->lexeme_list->back->operator = MODULO;
}

const int		sp_operator(t_op *operation, int *i)
{
  if ((operation->input[*i] == operation->operators[4]) ||
      (operation->input[*i] == operation->operators[5]) ||
      (operation->input[*i] == operation->operators[6]))
    {
      if ((push_back(operation->lexeme_list,
		     my_strndup(&(operation->input[*i]), 1)))
	  == RETURN_FAILURE)
	return (RETURN_FAILURE);
      _define_id(operation, i);
      *i += 1;
      return (RETURN_SUCCESS);
    }
  return (RETURN_FAILURE);
}
