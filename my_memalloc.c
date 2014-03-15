/*                                                                              
** my_memalloc.c for minishell2 in /home/bourge_v/Downloads/test/minishell2     
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:18:57 2014 bourge_v                                
** Last update Sun Mar  9 20:19:16 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

void    *my_memalloc(size_t size)
{
  char  *ptr;

  if (size <= 0)
    return (NULL);
  ptr = (char *)malloc(size * sizeof(*ptr));
  return ((void *)ptr);
}
