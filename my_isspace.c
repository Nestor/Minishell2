/*                                                                              
** my_isspace.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:23:51 2014 bourge_v                                
** Last update Sun Mar  9 19:39:12 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_isspace(int c)
{
  if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f'
      || c == ' ')
    return (1);
  return (0);
}
