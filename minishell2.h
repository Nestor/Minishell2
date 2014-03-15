/*                                                                              
** minishell2.h for minishell2 in /home/bourge_v/Downloads/test/minishell2      
**                                                                              
** Made by bourge_v                                                             
** Login   <bourge_v@epitech.net>                                               
**                                                                              
** Started on  Sun Mar  9 18:15:11 2014 bourge_v                                
** Last update Sun Mar  9 23:25:26 2014 bourge_v                                
*/

#ifndef MINISHELL2_H
# define MINISHELL2_H
# define FTSH_NAME      ("mysh")
# define FTSH_PROMPT    ("-$> ")
# define FTSH_PROMPT_COLOR      ("\033[0;31m")
# define FTSH_PROMPT_COLOR_PATH ("\033[1;36m")
# define FTSH_PROMPT_COLOR_RESET        ("\033[0m")
# include <stdlib.h>
# include <stddef.h>

typedef struct          s_cmd
{
  char                  *str;
  char                  *exe;
  char                  **args;
  struct s_cmd          *prev;
  struct s_cmd          *next;
}                       t_cmd;

typedef struct          s_datas
{
  t_cmd                 **todo;
  char                  **env;
  char                  **path;
  int                   color;
}                       t_datas;

int     my_error(char *cmd, char *msg, char *arg);
int     my_do(t_datas *datas);
int     my_ispiped(char *cmd);
int     my_isredirected(char *cmd);
int     my_isbuiltin(char *cmd);
int     my_builtin(t_datas *datas, char ***cmd);
int     my_exec(t_datas *datas, char ***cmd);
int     my_init_piped(t_cmd **acmds, char *str);
int     my_exec_piped(t_datas *datas, t_cmd **acmds);
int     my_exec_redirected(t_datas *datas, char *str);
int     my_cd(t_datas *datas, char **cmd);
int     my_env(t_datas *datas, char **cmd);
int     my_setenv(t_datas *datas, char **cmd);
int     my_sys_setenv(t_datas *datas, char *cmd, char *key, char *val);
int     my_unsetenv(t_datas *datas, char **cmd);
char    *my_getenv(char **env, char *key);
char    *my_readcmd(int fd);
char    *my_findexe(char **path, char *exe);
char    **my_getcmds(char *str, char c);
char    **my_getpath(char *path);
char    **my_cmdsplit(char *s);
void    my_putpath(char **env, char *path, int nl);
void    my_prompt(t_datas *datas);
void    my_signal(void);
void    my_exit(t_datas *datas, int code);
void    my_deltodo(t_datas *datas);
void    my_cmdadd(t_cmd **alst, t_cmd *new);
void    my_cmddel(t_cmd **alst);
t_cmd   *my_cmddelone(t_cmd *del);
t_cmd   *my_cmdnew(t_datas *datas, char *cmd);
t_cmd   **my_init(char *str);
t_datas *my_getdatas(int ac, char **av, char **ep);
int     my_strlen(const char *s);
void    my_putstr(const char *s);
void    my_putendl(const char *s);
char    *my_strnew(size_t size);
char    *my_strtrim(char *s);
void    my_bzero(void *s, size_t n);
int     my_isspace(int c);
void    my_putendl_fd(char const *s, int fd);
void    my_putchar(char c);
int     my_strncmp(const char *s1, const char *s2, size_t n);
void    my_arrdel(char ***arr);
void    my_putchar_fd(char c, int fd);
void    my_putstr_fd(char const *s, int fd);
int     my_atoi(const char *s);
char    *my_strdup(const char *s);
int     my_strcmp(const char *s1, const char *s2);
char    *my_strsub(char const *s, unsigned int start, size_t len);
int     my_isdigit(int c);
char    **my_arrnew(size_t size);
int     my_arradd(char ***arr, char *str);
char    *my_strjoin(char const *s1, char const *s2);
char    **my_arrdup(char **arr);
int     my_arrsize(char **arr);
char    *my_strcat(char *dest, const char *src);
char    *my_strcpy(char *s1, const char *s2);
char    *my_strchr(const char *s, int c);
char    *my_realpath(char *path);
char    *my_strfjoin(char const *s1, char const *s2);
int     my_strichr(const char *s, int c);
char    *my_strchr(const char *s, int c);
char    **my_strsplit(char const *s, char c);
char    *my_strrchr(const char *s, int c);
int     my_strrichr(const char *s, int c);
int     my_isascii(int c);
void    *my_memalloc(size_t size);

#endif /* !MINISHELL2_H */
