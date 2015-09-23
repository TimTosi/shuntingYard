/*
** parser.c for Bistromathique in /home/tosi_t//BISTRO/src/parser
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 30 09:16:50 2013 timothee tosi
** Last update Sun Sep  8 21:17:07 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"parser.h"
#include		"shunting_yard.h"
#include		"my_flags.h"
#include		"my_str.h"

static t_parser_rule	g_parser_rule[]=
{
  {&parse_l_bracket, L_BRACKET},
  {&parse_r_bracket, R_BRACKET},
  {&parse_sp_operator, SP_OPERATOR},
  {&parse_wp_operator, WP_OPERATOR},
  {&parse_operand, P_OPERAND},
  {&parse_operand, N_OPERAND},
  {NULL, RETURN_FAILURE}
};

static const int	_parser_rule(t_op *operation, t_content **tmp)
{
  int			i;

  i = 0;
  while (g_parser_rule[i].id != RETURN_FAILURE)
    {
      if ((*tmp)->type == g_parser_rule[i].id)
	return (g_parser_rule[i].ptr_func(operation, tmp));
      ++i;
    }
  return (RETURN_FAILURE);
}

const int		parser(t_op *operation)
{
  t_content		*tmp;

  if (lexer(operation) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  tmp = operation->lexeme_list->front;
  while (tmp != NULL)
    {
      if (_parser_rule(operation, &tmp) == RETURN_FAILURE)
	return (my_puterror(SYNTAXE_ERROR_MSG));
    }
  if ((infix_to_postfix(operation) == RETURN_FAILURE) ||
      (evaluate_postfix(operation) == RETURN_FAILURE))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
