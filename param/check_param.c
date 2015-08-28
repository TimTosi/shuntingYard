/*
** check_param.c for Bistromathique in /home/tosi_t//BISTRO/src/error
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Jul 12 19:53:12 2013 timothee tosi
** Last update Sun Sep  8 20:57:10 2013 timothee tosi
*/

#include		"check_param.h"
#include		"my_flags.h"
#include		"my_str.h"

static const int	_check_param_nb(int param_nb, char *name)
{
  if (param_nb != 4)
    {
      my_puterror("Usage : ");
      my_puterror(name);
      my_puterror(" base ops\"()+-*/%\" exp_len\n");
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

static const int	_check_size_read(char *str)
{
  if ((is_number(str) == RETURN_FAILURE))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

const int		check_param(const int param_nb, char **param_tab)
{
  if ((_check_param_nb(param_nb, param_tab[0]) == RETURN_FAILURE) ||
      (check_op(param_tab) == RETURN_FAILURE) ||
      (_check_size_read(param_tab[3]) == RETURN_FAILURE))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
