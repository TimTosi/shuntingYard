/*
** op_init.c for Bistromathique in /home/tosi_t//BISTRO/src/operation
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Thu Aug 15 02:15:48 2013 timothee tosi
** Last update Sun Aug 18 15:25:22 2013 timothee tosi
*/

#include		<stdlib.h>
#include		"operation.h"
#include		"my_str.h"
#include		"memory.h"

char			*op_init(t_add *add, char *first_op, char *second_op,
				 char *base)
{
  char			*result;

  add->carry = 0;
  add->carry2 = 0;
  add->i = my_strlen(first_op);
  add->j = my_strlen(second_op);
  add->k = (add->i > add->j ? add->i + 2 : add->j + 2);
  if ((result = malloc(sizeof(*result) * (add->k + 1))) == NULL)
    return (NULL);
  result[add->k] = '\0';
  my_memset(result, base[0], add->k);
  --(add)->i;
  --(add)->j;
  --(add)->k;
  return (result);
}
