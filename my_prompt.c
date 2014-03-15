/*                                                                              
** my_prompt.c for minishell2 in /home/bourge_v/Downloads/test/minishell2       
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 17:49:45 2014 bourge_v                                
** Last update Sun Mar  9 18:46:36 2014 bourge_v                                
*/

#include "minishell2.h"

static void     my_prompt_path(char **env, int color)
{
  char          *pwd;

  pwd = my_getenv(env, "PWD");
  if (color == 1)
    my_putstr(FTSH_PROMPT_COLOR_PATH);
  my_putpath(env, pwd, 0);
}

void            my_prompt(t_datas *datas)
{
  if (datas->color == 1)
    my_putstr(FTSH_PROMPT_COLOR);
  my_putchar('(');
  my_prompt_path(datas->env, datas->color);
  if (datas->color == 1)
    my_putstr(FTSH_PROMPT_COLOR);
  my_putchar(')');
  my_putstr(FTSH_PROMPT);
  if (datas->color == 1)
    my_putstr(FTSH_PROMPT_COLOR_RESET);
}
