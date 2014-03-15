/*                                                                              
** my_putchar.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:28:16 2014 bourge_v                                
** Last update Sun Mar  9 19:28:45 2014 bourge_v                                
*/

#include "minishell2.h"

void    my_putchar(char c)
{
  if (c)
    my_putchar_fd(c, 1);
}
