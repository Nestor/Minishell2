/*                                                                              
** my_strnew.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:14:33 2014 bourge_v                                
** Last update Sun Mar  9 19:15:04 2014 bourge_v                                
*/

#include "minishell2.h"

char            *my_strnew(size_t size)
{
  size_t        i;
  char          *str;

  i = 0;
  str = (char *)malloc((size + 1) * sizeof(char));
  if (str == NULL)
    return (NULL);
  while (i <= (size + 1))
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}
