##
## Makefile for Makefile in /home/catuss_a//Desktop/my_ftp
## 
## Made by axel catusse
## Login   <catuss_a@epitech.net>
## 
## Started on  Sun Apr  3 04:23:56 2011 axel catusse
## Last update Sun Apr  3 17:51:00 2011 axel catusse
##

####################################################
## VARIABLES
####################################################

CC		=	gcc
RM		=	rm -f
CFLAGS		+=	-W -Wall -g
IFLAGS		=	-I./include/
LDFLAGS		=	-lncurses

####################################################
## SERVER
####################################################

SRV_NAME	=	serveur
SRV_OBJS	=	$(SRV_SRCS:.c=.o)
SRV_DIR		=	./ftp_server/

SRV_SRCS	=	$(SRV_DIR)main.c		\
			$(SRV_DIR)my_error.c		\
			$(SRV_DIR)my_gnl.c		\
			$(SRV_DIR)print_login_db.c	\
			$(SRV_DIR)print_welcome.c	\
			$(SRV_DIR)authentification.c	\
			$(SRV_DIR)my_split.c		\
			$(SRV_DIR)xwrite.c		\
			$(SRV_DIR)strlen_tab.c		\
			$(SRV_DIR)free_tab.c		\
			$(SRV_DIR)xmalloc.c		\
			$(SRV_DIR)init_server.c		\
			$(SRV_DIR)accept_connection.c	\
			$(SRV_DIR)send_cd.c		\
			$(SRV_DIR)send_quit.c		\
			$(SRV_DIR)send_pwd.c		\
			$(SRV_DIR)send_get.c		\
			$(SRV_DIR)send_ls.c		

####################################################
## CLIENT
####################################################

CLT_NAME	=	client
CLT_OBJS	=	$(CLT_SRCS:.c=.o)
CLT_DIR		=	./ftp_client/

CLT_SRCS	=	$(CLT_DIR)main.c		\
			$(CLT_DIR)my_error.c		\
			$(CLT_DIR)my_gnl.c		\
			$(CLT_DIR)puts_color.c		\
			$(CLT_DIR)print_welcome.c	\
			$(CLT_DIR)my_split.c		\
			$(CLT_DIR)xwrite.c		\
			$(CLT_DIR)xfree.c		\
			$(CLT_DIR)strlen_tab.c		\
			$(CLT_DIR)free_tab.c		\
			$(CLT_DIR)init_client.c		\
			$(CLT_DIR)xmalloc.c		\
			$(CLT_DIR)auth_successful.c	\
			$(CLT_DIR)req_ls.c		\
			$(CLT_DIR)req_get.c		\
			$(CLT_DIR)req_cd.c		\
			$(CLT_DIR)req_quit.c		\
			$(CLT_DIR)req_pwd.c		\
			$(CLT_DIR)auth_wrongful.c	\
			$(CLT_DIR)send_login_pass.c	\
			$(CLT_DIR)req_notfound.c	\
			$(CLT_DIR)req_success.c

####################################################
## RULES
####################################################

all		:	$(SRV_NAME) $(CLT_NAME)

$(SRV_NAME)	:	$(SRV_OBJS)
		$(CC) -o $(SRV_NAME) $(IFLAGS) $(SRV_OBJS)

$(CLT_NAME)	:	$(CLT_OBJS)
		$(CC) -o $(CLT_NAME) $(IFLAGS) $(CLT_OBJS)

clean		:
		$(RM) $(SRV_OBJS)
		$(RM) $(CLT_OBJS)

fclean		:	clean
		$(RM) $(SRV_NAME)
		$(RM) $(CLT_NAME)

re		:	fclean all

.c.o            :
		$(CC) $(IFLAGS) $< -c -o $@ $(CFLAGS)