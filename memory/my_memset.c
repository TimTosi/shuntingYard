/*
** my_memset.c for Bistromathique in /home/tosi_t//TESTBASE/src
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Wed Aug 14 15:50:40 2013 timothee tosi
** Last update Wed Aug 14 20:01:54 2013 timothee tosi
*/

void		my_memset(char *array, int byte, int size)
{
  int		i;

  i = 0;
  while (i < size)
    {
      array[i] = byte;
      ++i;
    }
}
