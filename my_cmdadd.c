/*                                                                              
** my_cmdadd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:05:35 2014 bourge_v                                
** Last update Sun Mar  9 18:40:33 2014 bourge_v                                
*/

#include "minishell2.h"

void    my_cmdadd(t_cmd **alst, t_cmd *new)
{
  t_cmd *tmp;

  if (new == NULL)
    return ;
  if (*alst == NULL)
    {
      *alst = new;
      return ;
    }
  tmp = *alst;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
}
