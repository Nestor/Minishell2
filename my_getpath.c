/*                                                                              
** my_getpath.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:41:08 2014 bourge_v                                
** Last update Sun Mar  9 18:49:44 2014 bourge_v                                
*/

#include <stdio.h>
#include "minishell2.h"

char    **my_getpath(char *path)
{
  if (path != NULL)
    return (my_strsplit(path, ':'));
  return (NULL);
}
