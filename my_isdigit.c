/*                                                                              
** my_isdigit.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:46:44 2014 bourge_v                                
** Last update Sun Mar  9 19:47:10 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_isdigit(int c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
