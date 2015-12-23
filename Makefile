#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/22 16:20:31 by                   #+#    #+#             *#
#*   Updated: 2015/12/22 16:20:41 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit
SRCS = src/*.c
INCLUDES = includes/
OBJ = *.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRCS)
			gcc -o $(NAME) $(OBJ) -L libft/ -lft

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all
