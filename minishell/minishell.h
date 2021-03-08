/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wildboarg <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:54:05 by wildboarg         #+#    #+#             */
/*   Updated: 2021/03/08 17:00:16 by lchantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include "./srcs/libft/libft.h"
# include <sys/types.h>
# include <dirent.h> 
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <signal.h>

# define BUFFER_SIZE 2048
# define SQUOTE 0b10
# define DQUOTE 0b1
# define ISQUOTE 0b11
# define ESCCHAR 0b100
# define PARAMEXP 0b1000
# define COMCHAR 0b10000
# define TOKTWIDDLE 0b100000
# define HANPIPE 0b1000000
# define HANSEMI 0b10000000
# define ENVSPACE 0b100000000

# define SH_INT_MAX 2147483647

static int			sig_state;

typedef struct		s_gnl
{
	int 			st;
	char			buf[2048];
	int				byte;
	int				i;
	int				fd_pipe[2];
	pid_t			gnl_fork;
	int				wstatus;
	int				orig_stdout;
	int				len;
}					t_gnl;

typedef struct		s_shell
{
	char			**argv;	// пока не применил
	char			**envp; // переменные окружения 
	char			**cmd; // команды
	char			**tmp; // временное хранилище
	char 			**bin; 
	char			**clean2;
	char			**pipe_block;
	char			**bin_args;
	char			**envp_secure;
	char			*backup;
	char			*bin_search;
	char			*line;
	char			*recycle;
	char			*argstr;
	char			*clunit;
	char			*oldpwd;
	void			*clean;
	int				readenv;
	int				err_status;
	int				fd_pipe[2];
	int				fd_err[2];
	int				fd_redir[2];
	int				argc;
	int				len;
	int				status[3];
	int				fd_recover[3];
	int				if_child;
	int				roll;
	int				lst_flag[2];
	int				pipe_pos[2];
	int				cmd_flag;
	int				env_is_home;
	int				err_fst;
	int				err_pos;
	int				is_export;
	int				err_fd[2];
	char			loop;
	char			eol;
	char			exit;
	char			spec_char;
	pid_t			sh_pid[2];
	pid_t			child;
	DIR				*sh_dir;
	struct dirent	*binary;
	t_list			*lst_start;
	t_list			*lst_head;
	t_list			*lst_newoper;
}					t_shell;

int					sh_gnl(int fd, char **line);
int					ft_minishell_pwd(t_shell *obj);
void				sh_line_ansys(t_shell *obj);
void 				alloc_free_2(void **mem);
void				ft_minishell_echo(t_shell *obj);
char				*sh_envp_search(const char *str, t_shell *obj);
void				ft_minishell_env(t_shell *obj);
char				*addchar(char *s, char c);
int					sh_user_bin(t_shell *obj);
char 				**execve_args(t_shell *obj);
int 				change_dir(t_shell *obj);
char				**ft_minishell_export_add(char *str, char ***envp);
char				**ft_minishell_export_sort(char **envp);
int					ft_minishell_export_envplen(char **envp);
void				ft_minishell_export(t_shell *obj);
int					check_export_input(char *str, int count, char *cmd, int bit_eq);
void				*memrealloc(void *mem, int oldsize, int addbyte);
int 				unset_envp(t_shell *obj);
int 				sh_exit(t_shell *obj);
void				sh_read_escape(int sig);
int					check_line(char *line);
int					sh_parcer(t_shell *obj);
void				sh_func_quit(int sig);
void				err_arrow_case(char *str, int count, char c);
int					err_analisys(t_shell *obj);
char				**change_pwd(t_shell *obj, char *envpwd, char *dir);
int					sh_redirects(t_shell *obj, int *index);
int					sh_env_linefix(t_shell *obj, int *st);
void				sh_free_str(char **str);
void				sh_parcer_envp_fix(char **str, int st);
char				**sh_pipe_block_fix(t_shell *obj);
char				*sh_ignore_colon(char *str);
int					err_set_var(t_shell *obj, char *src,
					char *templ, int err_case);
int					sh_err_analisys(char *str, t_shell *obj);
void				err_output(t_shell obj);
int					sh_line_err_parse(t_shell *obj);
int					sh_err_noarg_com(t_list *subj, t_shell *obj);

#endif
