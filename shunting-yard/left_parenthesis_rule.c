/*
** left_parenthesis_rule.c for Bistromathique in /home/tosi_t//BISTRO/src/shunting-yard
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Sun Aug  4 17:18:12 2013 timothee tosi
** Last update Mon Aug  5 14:05:35 2013 timothee tosi
*/

#include	"shunting_yard.h"
#include	"my_flags.h"

const int	left_parenthesis_rule(t_op *operation, t_shunting *shunting)
{
  push_front_elem(shunting->operator_stack, pop_front_elem(shunting->infix));
  return (RETURN_SUCCESS);
}
