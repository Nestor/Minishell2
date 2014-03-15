/*                                                                              
** my_putstr_fd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2    
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:37:14 2014 bourge_v                                
** Last update Sun Mar  9 19:37:39 2014 bourge_v                                
*/

#include <unistd.h>
#include "minishell2.h"

void    my_putstr_fd(char const *s, int fd)
{
  if (!s || !fd)
    return ;
  write(fd, s, my_strlen(s));
}
