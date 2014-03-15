/*                                                                              
** my_putendl_fd.c for minishell2 in /home/bourge_v/Downloads/test/minishell2   
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 19:26:41 2014 bourge_v                                
** Last update Sun Mar  9 19:27:06 2014 bourge_v                                
*/

void    my_putendl_fd(char const *s, int fd)
{
  if (s && fd)
    {
      my_putstr_fd(s, fd);
      my_putchar_fd('\n', fd);
    }
}
