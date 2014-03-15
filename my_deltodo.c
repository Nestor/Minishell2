/*                                                                              
** my_deltodo.c for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:15:25 2014 bourge_v                                
** Last update Sun Mar  9 18:42:17 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

void    my_deltodo(t_datas *datas)
{
  int   i;

  if (datas->todo == NULL)
    return ;
  i = 0;
  while (datas->todo[i] != NULL)
    {
      my_cmddel(&(datas->todo[i]));
      i++;
    }
  free((t_cmd **)datas->todo);
  datas->todo = NULL;
}
