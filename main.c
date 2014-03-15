/*
** main.c for minishell2 in /home/bourge_v/Downloads/test/minishell2
** 
** Made by bourge_v
** Login   <bourge_v@epitech.net>
** 
** Started on  Sun Mar  9 18:07:29 2014 bourge_v
** Last update Sun Mar  9 18:38:50 2014 bourge_v
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "minishell2.h"

static void     my_exit_eof(t_datas *datas)
{
  my_putstr("\b \b\b \b\n");
  my_exit(datas, 0);
}

int             main(int ac, char **av, char **ep)
{
  char          *tmp;
  t_datas       *datas;

  datas = my_getdatas(ac, av, ep);
  if (datas == NULL)
    return (my_error(FTSH_NAME, "running failed.", NULL));
  my_putendl("\033[1;32mWelcome in Minishell v2 !\033[0m");
  my_signal();
  while (42)
    {
      my_prompt(datas);
      tmp = my_strtrim(my_readcmd(0));
      if (tmp == NULL)
        my_exit_eof(datas);
      if (my_strlen(tmp) == 0)
        continue ;
      datas->todo = my_init(tmp);
      free((char *)tmp);
      my_do(datas);
      my_deltodo(datas);
    }
  return (0);
}
