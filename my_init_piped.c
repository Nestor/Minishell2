/*                                                                              
** my_init_piped.c for minishell2 in /home/bourge_v/Downloads/test/minishell2   
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:44:36 2014 bourge_v                                
** Last update Sun Mar  9 18:45:46 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

int             my_init_piped(t_cmd **acmds, char *str)
{
  int           i;
  int           n;
  char          **arr;
  t_cmd         *new;
  t_datas       *datas;

  if ((arr = my_getcmds(str, '|')) == NULL)
    return (0);
  datas = my_getdatas(0, NULL, NULL);
  i = 0;
  *acmds = NULL;
  while (arr[i] != NULL)
    {
      if (my_strlen(arr[i]) == 0)
        return (my_error(FTSH_NAME, "Invalid null command.", NULL));
      if ((new = my_cmdnew(datas, arr[i])) != NULL)
        {
          if (new->args != NULL)
            n++;
          my_cmdadd(acmds, new);
        }
      i++;
    }
  my_arrdel(&arr);
  return (n);
}
