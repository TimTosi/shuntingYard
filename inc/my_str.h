/*
** my_str.h for Bistromathique in /home/tosi_t//BISTRO/inc
** 
** Made by timothee tosi
** Login   <tosi_t@epitech.net>
** 
** Started on  Fri Jul 12 19:46:36 2013 timothee tosi
** Last update Sun Sep  8 21:02:40 2013 timothee tosi
*/

#ifndef			MY_STR_H_
# define		MY_STR_H_

const int		is_number(char *str);
const int		in_array(char needle, char *heap);
const int		str_base_cmp(char *str1, char *str2, char *base);
int				my_getnbr(char *str);
int				my_strlen(char *str);
char			*my_strcpy(char *origin, char *dest);
void			my_putstr(char *str);
const int		my_puterror(char *str);

#endif			/* !MY_STR_H_ */
