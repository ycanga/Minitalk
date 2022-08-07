SRCSERVER			= server.c	minitalk_utils.c
SRCCLIENT			= client.c	minitalk_utils.c

CC				= gcc
RM				= rm -f
#CFLAGS			= -Wall -Wextra -Werror -I.

OBJSERVER		= $(SRCSERVER:.c=.o)

OBJSCLIENT 		= $(SRCCLIENT:.c=.o)

NAME			= minitalk.a

all:			$(NAME)

$(NAME): server client $(OBJSERVER) $(OBJSCLIENT)
		
server: 
		$(CC) -o server $(SRCSERVER) 

client: 
		$(CC) -o client $(SRCCLIENT) 

clean:
				$(RM) $(OBJSERVER) $(OBJSCLIENT)

fclean:			clean
				$(RM) server
				$(RM) client

re:				fclean $(NAME)

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re norm