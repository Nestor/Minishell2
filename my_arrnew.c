/*                                                                              
** my_arrnew.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:48:35 2014 bourge_v                                
** Last update Sun Mar  9 19:49:05 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

char    **my_arrnew(size_t size)
{
  char    **arr;

  arr = (char **)malloc((size + 1) * sizeof(char *));
  if (arr != NULL)
    arr[size] = NULL;
  return (arr);
}
