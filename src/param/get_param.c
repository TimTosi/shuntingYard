/*
** get_param.c for Bistromathique in /home/tosi_t//BISTRO/src/param
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Jul 18 17:47:17 2013 timothee tosi
** Last update Sun Sep  8 21:18:09 2013 timothee tosi
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"operation.h"
#include		"my_str.h"
#include		"memory.h"
#include		"my_flags.h"

static const int	_check_input(t_op *operation)
{
  int			i;

  i = 0;
  while (operation->input[i] != '\0')
    {
      if (((in_array(operation->input[i], operation->operators))
	   == RETURN_FAILURE) &&
	  ((in_array(operation->input[i], operation->operands))
	   == RETURN_FAILURE))
	return (my_puterror(SYNTAXE_ERROR_MSG));
      ++i;
    }
  return (RETURN_SUCCESS);
}

static const int	_get_input(t_op *operation)
{
  if (((operation->input = malloc(sizeof(*(operation->input)) *
		       (operation->size_read + 1))) == NULL))
    return (RETURN_FAILURE);
  operation->input[operation->size_read] = '\0';
  if (read(0, operation->input, operation->size_read) != operation->size_read)
    return (my_puterror("Could not read\n"));
  return (_check_input(operation));
}

const int		get_param(t_op *operation, char **av)
{
  if ((operation->size_read = my_getnbr(av[3])) <= 0)
    return (my_puterror("Bad expr len\n"));
  if (((operation->operands = my_strdup(av[1])) == NULL) ||
      ((operation->operators = my_strdup(av[2])) == NULL) ||
      (_get_input(operation) == RETURN_FAILURE))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
