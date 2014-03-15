/*                                                                              
** my_exec_piped.c for minishell2 in /home/bourge_v/Downloads/test/minishell2   
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:22:49 2014 bourge_v                                
** Last update Sun Mar  9 21:50:17 2014 bourge_v                                
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell2.h"

static int      my_pipe_piped(t_datas *datas, t_cmd *cmd, int fdin, int *pfd)
{
  int           res;

  res = 0;
  if (cmd->prev != NULL)
    {
      if (dup2(fdin, 0) < 0)
        exit(my_error(FTSH_NAME, "pipe error", "input"));
    }
  if (cmd->next != NULL)
    {
      if (dup2(pfd[1], 1) < 0)
        exit(my_error(FTSH_NAME, "pipe error", "output"));
      close(pfd[0]);
    }
  if ((res = my_builtin(datas, &(cmd->args))) != 42)
    return (res);
  if (cmd->exe == NULL)
    exit(my_error(cmd->args[0], "command not found.", NULL));
  if ((res = execve(cmd->exe, cmd->args, datas->env)) < 0)
    exit(my_error(FTSH_NAME, "execution failed", cmd->str));
  return (res);
}

static void     my_run_father(pid_t pid, int *pfd, int *fdin, t_cmd *cmd)
{
  int           status;

  waitpid(pid, &status, 0);
  close(pfd[1]);
  *fdin = pfd[0];
  if (my_strcmp(cmd->args[0], "exit") == 0)
    exit(my_atoi(cmd->args[1]));
}

static int      my_run_piped(t_datas *datas, t_cmd *cmd, int *fdin)
{
  pid_t         pid;
  int           pfd[2];
  int           res;

  res = 0;
  while (cmd != NULL)
    {
      while (cmd->args == NULL)
        {
          my_error(FTSH_NAME, "command failed", cmd->str);
          if ((cmd = my_cmddelone(cmd)) == NULL)
            return (res);
        }
      pipe(pfd);
      if ((pid = fork()) < 0)
        return (my_error(FTSH_NAME, "new processus failed.", NULL));
      else if (pid == 0)
        res = my_pipe_piped(datas, cmd, *fdin, pfd);
      else
        {
          my_run_father(pid, pfd, fdin, cmd);
          cmd = cmd->next;
        }
    }
  return (res);
}

int             my_exec_piped(t_datas *datas, t_cmd **acmds)
{
  int           res;
  int           fdin;

  if (*acmds == NULL)
    return (-1);
  res = my_run_piped(datas, *acmds, &fdin);
  return (res);
}
