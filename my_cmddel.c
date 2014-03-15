/*                                                                              
** my_cmddel.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:07:13 2014 bourge_v                                
** Last update Sun Mar  9 18:40:56 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

void    my_cmddel(t_cmd **alst)
{
  t_cmd *tmp;

  if (*alst == NULL)
    return ;
  while (*alst != NULL)
    {
      tmp = *alst;
      free((char *)tmp->str);
      free((char *)tmp->exe);
      my_arrdel(&(tmp->args));
      *alst = tmp->next;
      if (*alst != NULL)
        (*alst)->prev = NULL;
      free((t_cmd *)tmp);
    }
}
