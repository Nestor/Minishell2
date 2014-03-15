##                                                                              
## Makefile for minishell2 in /home/bourge_v/rendu/PSU_2013_minishell2          
##                                                                              
## Made by bourge_v                                                             
## Login   <bourge_v@epitech.net>                                               
##                                                                              
## Started on  Sat Mar 15 23:17:42 2014 bourge_v                                
## Last update Sat Mar 15 23:17:44 2014 bourge_v                                
##                                                                              

CC = cc

NAME = mysh

SRC =   main.c \
        my_prompt.c \
        my_readcmd.c \
        my_getpath.c \
        my_findexe.c \
        my_error.c \
        my_signal.c \
        my_do.c \
        my_exec.c \
        my_cd.c \
        my_getenv.c \
        my_setenv.c \
        my_unsetenv.c \
        my_env.c \
        my_exit.c \
        my_cmdsplit.c \
        my_sys_setenv.c \
        my_builtin.c \
        my_isbuiltin.c \
        my_ispiped.c \
        my_isredirected.c \
        my_getdatas.c \
        my_getcmds.c \
        my_exec_piped.c \
        my_exec_redirected.c \
        my_init.c \
        my_init_piped.c \
        my_deltodo.c \
        my_cmdadd.c \
        my_cmdnew.c \
        my_cmddel.c \
        my_cmddelone.c \
        my_putpath.c \
        my_putstr.c \
        my_putendl.c \
        my_strlen.c \
        my_strtrim.c \
        my_strnew.c \
        my_bzero.c \
        my_isspace.c \
        my_putendl_fd.c \
        my_putchar.c \
        my_strncmp.c \
        my_arrdel.c \
        my_putchar_fd.c \
        my_putstr_fd.c \
        my_atoi.c \
        my_strdup.c \
        my_strcmp.c \
        my_strsub.c \
        my_isdigit.c \
        my_arrnew.c \
        my_arradd.c \
        my_strjoin.c \
        my_arrdup.c \
        my_arrsize.c \
        my_strcat.c \
        my_strcpy.c \
        my_realpath.c \
        my_strfjoin.c \
        my_strichr.c \
        my_strchr.c \
        my_strsplit.c \
        my_strrchr.c \
        my_strrichr.c \
        my_isascii.c \
        my_memalloc.c

OBJ =   $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
        @$(CC) -o $(NAME) $(OBJ)
        @echo "COMPILING MYSH: DONE."

clean:
        @rm -rf $(OBJ)
        @echo "CLEANING MYSH OBJECTS: Done."

fclean: clean
        @rm -rf $(NAME)
        @echo "REMOVING MYSH BIN: Done."

re: fclean all

.PHONY: all re clean fclean
