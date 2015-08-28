/*
** infix_to_postfix.c for Bistromathique in /home/tosi_t/BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Tue Jul 30 09:36:54 2013 timothee tosi
** Last update Sat Aug 10 12:18:09 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"shunting_yard.h"
#include		"my_flags.h"
#include "my_str.h"

static const t_infix	g_determine_rule[] = {
  {L_BRACKET, &left_parenthesis_rule},
  {R_BRACKET, &right_parenthesis_rule},
  {SP_OPERATOR, &operator_rule},
  {WP_OPERATOR, &operator_rule},
  {P_OPERAND, &operand_rule},
  {N_OPERAND, &operand_rule},
  {-1, NULL}
};

static const int	_determine_rule(t_op *operation, t_shunting *shunting)
{
  int			i;

  i = 0;
  while (g_determine_rule[i].id != -1)
    {
      if (g_determine_rule[i].id == shunting->infix->front->type)
	return (g_determine_rule[i].ptr_func(operation, shunting));
      ++i;
    }
  return (RETURN_FAILURE);
}

static const int	_shunting_init(t_shunting *shunting, t_op *operation)
{
  shunting->infix = operation->lexeme_list;
  if ((shunting->operator_stack = new_linked_list()) == NULL)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

const int		infix_to_postfix(t_op *operation)
{
  t_shunting		shunting;

  if (_shunting_init(&shunting, operation) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  while (shunting.infix->size > 0)
    {
      if (_determine_rule(operation, &shunting) == RETURN_FAILURE)
	return (RETURN_FAILURE);
    }
  if (output_rule(operation, &shunting) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  free(shunting.operator_stack);
  my_putstr("SHUNTING YARD RESULT :\n");
  show_list(operation->postfix_notation);
  my_putstr("\n\n");
  return (RETURN_SUCCESS);
}
