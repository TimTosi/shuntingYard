/*
** check_op.c for Bistromathique in /home/tosi_t//BISTRO/src/param
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Mon Jul 22 09:05:42 2013 timothee tosi
** Last update Mon Jul 22 17:40:36 2013 timothee tosi
*/

#include		"check_param.h"
#include	       	"my_flags.h"
#include		"my_str.h"

static const int	_check_strchr(char *str)
{
  int			i;
  int			j;

  j = 0;
  while (str[j] != '\0')
    {
      i = 0;
      while (str[i] != '\0')
	{
	  if ((i != j) && (str[i] == str[j]))
	    {
	      my_puterror("Error: Same character in base or operators.\n");
	      return (RETURN_FAILURE);
	    }
	  ++i;
	}
      ++j;
    }
  return (RETURN_SUCCESS);
}

static const int	_check_operators(char *str)
{
  if (my_strlen(str) < OPERATORS_NB)
    {
      my_puterror("Error: Not enough operators in arguments.\n");
      return (RETURN_FAILURE);
    }
  else if (my_strlen(str) > OPERATORS_NB)
    {
      my_puterror("Error: Too much operators in arguments.\n");
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

static const int	_check_match(char *operand, char *operator)
{
  int			i;
  int			j;

  j = 0;
  while (operand[j] != '\0')
    {
      i = 0;
      while (operator[i] != '\0')
	{
	  if (operand[j] == operator[i])
	    {
	      my_puterror("Error: Same character in ");
	      my_puterror("operand string and operator string.\n");
	      return (RETURN_FAILURE);
	    }
	  ++i;
	}
      ++j;
    }
  return (RETURN_SUCCESS);
}

const int		check_op(char **param_tab)
{
  if ((_check_strchr(param_tab[1]) == RETURN_FAILURE) ||
      (_check_strchr(param_tab[2]) == RETURN_FAILURE) ||
      (_check_operators(param_tab[2]) == RETURN_FAILURE) ||
      (_check_match(param_tab[1], param_tab[2]) == RETURN_FAILURE))
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}
