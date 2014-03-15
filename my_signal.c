/*                                                                              
** my_signal.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 18:02:08 2014 bourge_v                                
** Last update Sun Mar  9 18:51:22 2014 bourge_v                                
*/

#include <stdio.h>
#include <signal.h>
#include "minishell2.h"

static void     my_signal_sigtstp(int sig)
{
  (void)sig;
  my_putstr("\b \b\b \b");
  signal(SIGTSTP, SIG_IGN);
}

static void     my_signal_sigint(int sig)
{
  (void)sig;
  my_putstr("\b \b\b \b\n");
  my_prompt(my_getdatas(0, NULL, NULL));
}

static void     my_signal_sigcont(int sig)
{
  (void)sig;
  my_prompt(my_getdatas(0, NULL, NULL));
}

void            my_signal(void)
{
  signal(SIGTSTP, &my_signal_sigtstp);
  signal(SIGCONT, &my_signal_sigcont);
  signal(SIGINT, &my_signal_sigint);
}
