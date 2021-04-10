#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define	INTUBE 1
#define OUTTUBE 0

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILNO 2

#define TOKEN_ENDL 0
#define TOKEN_DELIM 1
#define TOKEN_PIPE 2

typedef struct s_bidirect
{
	char				**args;
	int					token;
	int					pipes[2];
	int					len;
	struct s_bidirect	*next;
	struct s_bidirect	*prev;
}				t_bidirect;

int				wb_strlen(char *str);
char			*wb_strdup(char *s);
void			wb_argv_parser(t_bidirect **list, char *argv_unit);
int				wb_list_push(t_bidirect **list, char *argv_unit);
int				wb_add_elem(t_biderct *cmd, char *argv_init);
int				output_err(char *msg);
int				fatal_exit(void);
void			*fatal_exit_addr(void);
int				wb_add_elem(t_biderct *cmd, char *argv_init);
int				to_list_start(t_list **list);
int				exec_cmds(t_list **cmds, char **env); 
int				exec_cmd(t_list *cmd, char **env);

int				main(int argc, char *argv[], char *env[])
{
	t_bidirect	*heretic;
	int			i;
	int			sout;

	sout = EXIT_SUCCESS;
	heretic = NULL;
	i = 0;
	while (++i < argc)
		wb_argv_parser(&heretic, argv[i++]);
	return (0);
}

int				exec_cmd(t_list *cmd, char **env)
{
	pid_t	pid;
	int		ret;
	int		status;
	int		pipe_open;

	ret = EXIT_FAILURE;
	pipe_open = 0;
	if (cmd->token == TOKEN_PIPE ||
	(cmd->prev && cmd->prev->token == TOKEN_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->pipes))
			return (fatal_exit());
	}
	if ((pid = fork()) < 0)
		return (fatal_exit());
	else if (!pid)
	{
		if (cmd->token == TOKEN_PIPE && dup2(cmd->pipes[INTUBE], STDOUT_FILENO) < 0)
			return (fatal_exit());
		if (cmd->prev && cmd->prev->token == TIPE_PIPE &&
		dup2(cmd->prev->pipes[OUTTUBE], STDIN_FILENO) < 0)
			return (fatal_exit());
		if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			output_err()
		} 
	}
}

int				wb_strlen(char *str)
{
	int len;

	len = -1;
	while (*(str + ++len))
		;
	return (len);
}

char			*wb_strdup(char *s)
{
	int 	i;
	char 	*res;
	int		len;

	i = -1;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	res = (char *)malloc(len);
	while (s[++i])
		res[i] = s[i];
	res[i] = 0;
	return (res);
}

void			wb_argv_parser(t_bidirect **list, char *argv_unit)
{
	int	token_type;

	token_type = (!strcmp(";", argv_unit)) * TOKEN_DELIM
	+ (!strcmp("|", argv_unit)) * TOKEN_PIPE;
	if (token_type == TOKEN_DELIM && !*list)
		return (EXIT_SUCCESS);
	else if (!token_type && (!*list || (*list)->token > TOKEN_ENDL))
		return (wb_list_push(list, argv_unit));
	else if (token_type == TOKEN_PIPE)
		(*list)->token = TOKEN_PIPE;
	else if (token_type == TOKEN_DELIM)
		(*list)->token = TOKEN_DELIM;
	else
		return (wb_add_elem(*list, argv_unit));
	return (EXIT_SUCCESS);
}

int				wb_list_push(t_bidirect **list, char *argv_unit)
{
	t_bidirect	*elem;

	if (!(elem = (t_bidirect *)malloc(sizeof(t_bidirect))))
		return (EXIT_FAILURE);
	elem->args = NULL;
	elem->len = 0;
	elem->token = TOKEN_ENDL;
	elem->prev = NULL;
	elem->next = NULL;
	if (*list)
	{
		*list->next = elem;
		elem->prev = *list;
	}
	*list = elem;
	return (wb_add_elem(elem, argv_unit));
}

int				exec_cmds(char **cmds, char **env)
{
	t_list	*crt;
	int		ret;

	ret = EXIT_SUCCESS;
	to_list_start(cmds);
	while (*cmds)
	{
		crt = *cmds;
		if (!strcmp("cd", ctr->args[0]))
		{
			ret = EXIT_SUCCESS;
			if (crt->len < 2)
				ret = output_err("error: cd: bad arguments\n");
			else if (chdir(crt->args[1]))
			{
				ret = output_err("error: cd: cannot change directory to ");
				output_err(crt->args[1]);
				output_err("\n");
			}
		}
		else
	}

}

int				output_err(const char *msg)
{
	if (msg)
		write(STDERR_FILENO, msg, wb_strlen(msg));
	return (EXIT_FAILURE);
}

int				fatal_exit(void)
{
	output_err("error: fatal\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

void			*fatal_exit_addr(void)
{
	fatal_exit();
	exit(EXIT_FAILURE);
	return (NULL);
}

int				wb_add_elem(t_biderct *cmd, char *argv_unit)
{
	char	**tmp;
	int		i;

	i = -1;
	if (!(tmp = (char **)malloc(sizeof(*tmp) * (cmd->len + 2))))
		return (fatal_exit());
	while (++i < cmd_len)
		tmp[i] = cmd->args[i];
	tmp[i++] = ft_strdup(argv_unit);
	tmp[i] = 0;
	cmd->len++;
	return (EXIT_SUCCESS);
}

int				to_list_start(t_list **list)
{
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return (EXIT_SUCCESS);
}