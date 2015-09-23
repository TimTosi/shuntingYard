/*
** str_base_cmp.c for Bistromathique in
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Aug 14 22:13:30 2013 timothee tosi
** Last update Fri Aug 16 23:17:05 2013 timothee tosi
*/

#include		"my_str.h"
#include		"my_flags.h"

static const int	_check_in_base(char c1, char c2, char *base)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (base[i] != c1)
    ++i;
  while (base[j] != c2)
    ++j;
  if (c1 > c2)
    return (1);
  else if (c1 < c2)
    return (-1);
  return (0);
}

static const int	_check_len(char *str1, char *str2)
{
  int			len1;
  int			len2;

  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if (len1 > len2)
    return (1);
  else if (len1 < len2)
    return (-1);
  return (0);
}

const int		str_base_cmp(char *str1, char *str2, char *base)
{
  int			i;
  int			j;
  int			k;

  i = 0;
  j = 0;
  my_putstr(str2);
  if (in_array(str1[0], base) == RETURN_FAILURE)
    ++i;
  if (in_array(str2[0], base) == RETURN_FAILURE)
    ++j;
  if ((k = _check_len(&str1[i], &str2[j])) != 0)
    return (k);
  while (str1[i] && str2[j])
    {
      if ((k = _check_in_base(str1[i], str2[j], base)) != 0)
	return (k);
      ++i;
      ++j;
    }
  if ((str1[i] != '\0') && (str2[j] == '\0'))
    return (1);
  else if ((str1[i] == '\0') && (str2[j] != '\0'))
    return (-1);
  return (0);
}
