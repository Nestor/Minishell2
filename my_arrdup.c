/*                                                                              
** my_arrdup.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:54:13 2014 bourge_v                                
** Last update Sun Mar  9 19:54:15 2014 bourge_v                                
*/

#include "minishell2.h"

char            **my_arrdup(char **arr)
{
  size_t        len;
  size_t        i;
  char          **new;

  if (!arr)
    return (NULL);
  len = (size_t)my_arrsize(arr);
  new = my_arrnew(len);
  if (new == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      new[i] = my_strdup(arr[i]);
      i++;
    }
  return (new);
}
