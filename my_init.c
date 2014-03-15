/*                                                                              
** my_init.c for minishell2 in /home/bourge_v/Downloads/test/minishell2         
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:41:40 2014 bourge_v                                
** Last update Sun Mar  9 18:45:33 2014 bourge_v                                
*/

#include <stdlib.h>
#include "minishell2.h"

static int      my_init_count(char **arr)
{
  int           i;
  int           n;

  i = 0;
  n = 0;
  while (arr[i] != NULL)
    {
      if (my_strlen(arr[i]) > 0)
        n++;
      i++;
    }
  return (n);
}

static int      my_init_cmd(t_cmd **acmds, char *str, char ***arr)
{
  int           res;
  t_datas       *datas;

  res = 0;
  datas = my_getdatas(0, NULL, NULL);
  if (my_ispiped(str) == 1)
    res = my_init_piped(acmds, str);
  else if (my_isredirected(str) == 1)
    {
      *acmds = NULL;
      my_exec_redirected(datas, str);
    }
  else
    *acmds = my_cmdnew(datas, str);
  if (*acmds != NULL)
    return (res);
  else
    my_arrdel(arr);
  return (-1);
}

t_cmd           **my_init(char *str)
{
  int           i;
  int           j;
  char          **arr;
  t_cmd         **cmds;

  if ((arr = my_getcmds(str, ';')) == NULL || (j = my_init_count(arr)) == 0)
    return (NULL);
  if ((cmds = (t_cmd **)malloc((j + 1) * sizeof(t_cmd *))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (arr[i] != NULL)
    {
      if (my_strlen(arr[i]) > 0)
        {
          if (my_init_cmd(&(cmds[j]), arr[i], &arr) < 0)
            return (NULL);
          else
            j++;
        }
      i++;
    }
  cmds[j] = NULL;
  my_arrdel(&arr);
  return (cmds);
}
