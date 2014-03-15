/*                                                                              
** my_putendl.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:08:57 2014 bourge_v                                
** Last update Sun Mar  9 19:09:44 2014 bourge_v                                
*/

#include "minishell2.h"

void    my_putendl(const char *s)
{
  if (s)
    my_putendl_fd(s, 1);
}
