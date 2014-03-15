/*                                                                              
** my_exec_redirected.c for minishell2 in /home/bourge_v/Downloads/test/minishe\
ll2                                                                             
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:26:52 2014 bourge_v                                
** Last update Sun Mar  9 18:43:47 2014 bourge_v                                
*/

#include "minishell2.h"

int     my_exec_redirected(t_datas *datas, char *str)
{
  (void)datas;
  my_error(FTSH_NAME, str, "is redirected !");
  return (0);
}
