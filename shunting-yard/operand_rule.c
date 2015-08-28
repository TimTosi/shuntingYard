/*
** operand_rule.c for Bistromathique in /home/tosi_t//BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Aug  5 14:23:14 2013 timothee tosi
** Last update Mon Aug  5 14:26:48 2013 timothee tosi
*/

#include		"shunting_yard.h"
#include		"my_flags.h"

const int		operand_rule(t_op *operation, t_shunting *shunting)
{
  push_back_elem(operation->postfix_notation, pop_front_elem(shunting->infix));
  return (RETURN_SUCCESS);
}
