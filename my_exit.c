/*                                                                              
** my_exit.c for minishell2 in /home/bourge_v/Downloads/test/minishell2         
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:27:58 2014 bourge_v                                
** Last update Sun Mar  9 18:43:59 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

void    my_exit(t_datas *datas, int code)
{
  my_putendl("\033[1;31mLeaving Minishell v2...\033[0m");
  my_deltodo(datas);
  my_arrdel(&(datas->path));
  my_arrdel(&(datas->env));
  exit(code);
}
