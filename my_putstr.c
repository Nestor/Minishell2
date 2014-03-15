/*                                                                              
** my_putstr.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:07:27 2014 bourge_v                                
** Last update Sun Mar  9 19:10:01 2014 bourge_v                                
*/

#include "minishell2.h"

void    my_putstr(const char *s)
{
  if (s)
    my_putstr_fd(s, 1);
}
