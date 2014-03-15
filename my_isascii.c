/*                                                                              
** my_isascii.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 20:17:42 2014 bourge_v                                
** Last update Sun Mar  9 20:18:02 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_isascii(int c)
{
  if (c >= 0 && c <= 127)
    return (1);
  return (0);
}
