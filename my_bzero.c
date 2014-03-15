/*                                                                              
** my_bzero.c for minishell2 in /home/bourge_v/Downloads/test/minishell2        
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:22:35 2014 bourge_v                                
** Last update Sun Mar  9 19:23:03 2014 bourge_v                                
*/

#include "minishell2.h"

void    my_bzero(void *s, size_t n)
{
  if (n)
    {
      ((unsigned char *)s)[n - 1] = 0;
      my_bzero(s, n - 1);
    }
}
