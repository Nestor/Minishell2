/*                                                                              
** my_exec.c for minishell2 in /home/bourge_v/Downloads/test/minishell2         
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:20:43 2014 bourge_v                                
** Last update Sun Mar  9 18:43:16 2014 bourge_v                                
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"

static void     my_exec_error(char *cmd, char *msg)
{
  if (cmd != NULL)
    my_putstr_fd(cmd, 2);
  if (cmd != NULL && msg != NULL)
    my_putstr_fd(": ", 2);
  if (msg != NULL)
    my_putstr_fd(msg, 2);
  my_putchar_fd('\n', 2);
  exit(0);
}

int             my_exec(t_datas *datas, char ***cmd)
{
  int           res;
  int           status;
  char          *exe;
  pid_t         pid;

  if ((res = my_builtin(datas, cmd)) != 42)
    return (res);
  res = 0;
  if ((exe = my_findexe(datas->path, *cmd[0])) == NULL)
    return (my_error(*cmd[0], "command not found.", NULL));
  if ((pid = fork()) < 0)
    return (my_error(FTSH_NAME, "new processus failed.", NULL));
  if (pid == 0)
    {
      res = execve(exe, *cmd, datas->env);
      if (res < 0)
        my_exec_error(*cmd[0], "command not found.");
      else
        my_putchar('\n');
    }
  if (pid > 0)
    waitpid(pid, &status, 0);
  free((char *)exe);
  return (res);
}
