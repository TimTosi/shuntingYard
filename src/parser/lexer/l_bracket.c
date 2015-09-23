/*
** l_bracket.c for Bistromathique in /home/tosi_t//BISTRO/src/parser/lexer
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug  8 13:14:13 2013 timothee tosi
** Last update Thu Aug  8 14:45:11 2013 timothee tosi
*/

#include		"parser.h"
#include		"memory.h"
#include		"my_flags.h"

const int		l_bracket(t_op *operation, int *i)
{
  if (operation->input[*i] == operation->operators[0])
    {
      if ((push_back(operation->lexeme_list,
		     my_strndup(&(operation->input[*i]), 1)))
	  == RETURN_FAILURE)
	return (RETURN_FAILURE);
      operation->lexeme_list->back->type = L_BRACKET;
      *i += 1;
      return (RETURN_SUCCESS);
    }
  return (RETURN_FAILURE);
}
