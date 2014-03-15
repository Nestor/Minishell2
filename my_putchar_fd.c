/*                                                                              
** my_putchar_fd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2   
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:34:46 2014 bourge_v                                
** Last update Sun Mar  9 19:35:21 2014 bourge_v                                
*/

#include <unistd.h>
#include "minishell2.h"

void    my_putchar_fd(char c, int fd)
{
  if (c && fd)
    write(fd, &c, 1);
}
