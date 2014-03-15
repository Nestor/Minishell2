/*                                                                              
** my_arrdel.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:31:47 2014 bourge_v                                
** Last update Sun Mar  9 19:32:09 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

void    my_arrdel(char ***arr)
{
  size_t  i;
  char    **tmp;

  if (*arr == NULL)
    return ;
  i = 0;
  tmp = *arr;
  while (tmp[i] != NULL)
    {
      free((char *)tmp[i]);
      i++;
    }
  free((char **)tmp);
  *arr = NULL;
}
