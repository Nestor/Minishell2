/*                                                                              
** my_arradd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:49:56 2014 bourge_v                                
** Last update Sun Mar  9 19:50:51 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

int             my_arradd(char ***arr, char *str)
{
  size_t        i;
  char          **tmp;
  char          **new;

  if ((!arr || *arr == NULL) && !str)
    return (-1);
  i = 0;
  tmp = *arr;
  new = (tmp == NULL ? my_arrnew(1) : my_arrnew((size_t)my_arrsize(tmp) + 1));
  if (new == NULL)
    return (-1);
  if (tmp != NULL)
    {
      while (tmp[i] != NULL)
        {
          new[i] = tmp[i];
          tmp[i] = NULL;
          i++;
        }
      free((char **)tmp);
    }
  new[i] = str;
  *arr = new;
  return (0);
}
