/*
** server.h for server in /home/catuss_a//Desktop/my_ftp
** 
** Made by axel catusse
** Login   <catuss_a@epitech.net>
** 
** Started on  Fri Mar 25 00:28:27 2011 axel catusse
** Last update Sun Apr  3 17:25:01 2011 axel catusse
*/

#ifndef _SERVER_H_
# define _SERVER_H_

# include <arpa/inet.h>

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE        1
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS        0
# endif

# define		SUCCESS 0
# define		FAIL -1

enum lol
  {
    LOGIN_IDX = 0,
    PASS_IDX
  };

# define		BUFF_SIZE 4096
# define		INVALID_SOCKET -1
# define		DIE 0
# define		LIVE 1

# define		LOGIN_PASS "ftp_server/LOGIN_PASS"

/*
** ----- REQUEST -----
*/
# define AUTH		"REQ AUTH\n"
# define WRONG_AUTH	"REQ WRONG AUTH\n"
# define SUCCESS_AUTH	"REQ SUCCESS AUTH\n"
# define REQ_LS		"ls\n"
# define REQ_CD		"cd\n"
# define REQ_GET	"get\n"
# define REQ_PUT	"put\n"
# define REQ_PWD	"pwd\n"
# define REQ_QUIT	"quit\n"
# define REQ_NOTFOUND	"REQ NOTFOUND\n"
# define REQ_SUCCESS	"REQ SUCCESS\n"
# define REQ_FAILED	"REQ FAILED\n"
# define REQ_EXITCHILD	"REQ EXIT CHILD\n"
# define END_FILE_SIZE	"REQ END FILE SIZE\n"
# define FILE_SIZE	"REQ FILE SIZE\n"

# define BYE		"Bye Bye !!!\n"

typedef int		SOCKET;
typedef int		PORT;

/*
** ----- STRUCTS -----
*/
typedef struct		s_server_req
{
  const char		*request;
  void			(*send_req)(SOCKET csock, char *buffer);
}			t_server_req;

typedef struct		s_ftp_server
{
  struct sockaddr_in    sin;
  SOCKET		sock;
  PORT			port;
  char			**login_pass;
}			t_ftp_server;

void			send_get(SOCKET csock, char *buffer);
void			exit_child(SOCKET csock, char *buffer);
void			puts_color(char *str, char *color);
void			send_cd(SOCKET csock, char *buffer);
void			send_ls(SOCKET csock, char *buffer);
void			print_login_db(char **login_pass);
void			print_welcome(void);
char			*gnl(const int fd);
void			*xmalloc(int size);
void			my_error(int err, char *func, int wht);
void			init_server(t_ftp_server *server, PORT port);
void			accept_connection(t_ftp_server *server);
int			authentification(t_ftp_server *server,
					 SOCKET csock);
int			xwrite(int fd, const void *buf, int len);
char			**split_c(char* str, char separator);
void			free_tab(char **tab);
int			strlen_tab(char **tab);
void			send_pwd(SOCKET csock, char *buffer);
void			send_quit(SOCKET csock, char *buffer);

#endif /* !_SERVER_H_ */
