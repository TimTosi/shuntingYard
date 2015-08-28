/*
** bistromathique.c for Bistromatique in /home/tosi_t//BISTRO/src
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Jul 12 17:26:37 2013 timothee tosi
** Last update Thu Aug 15 02:32:03 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"my_flags.h"
#include		"check_param.h"
#include		"my_str.h"
#include		"operation.h"
#include		"parser.h"

static const int	struct_init(t_op *operation)
{
  operation->infix_notation = NULL;
  if (((operation->lexeme_list = new_linked_list()) == NULL) ||
      ((operation->postfix_notation = new_linked_list()) == NULL))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			main(int ac, char **av)
{
  t_op			operation;

  if ((struct_init(&operation) == RETURN_FAILURE) ||
      (check_param(ac, av) == RETURN_FAILURE) ||
      (get_param(&operation, av) == RETURN_FAILURE) ||
      (parser(&operation) == RETURN_FAILURE))
    {
      my_putstr("ECHEC\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
