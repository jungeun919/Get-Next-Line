all:
	cc -Wall -Wextra -Werror -g3 -fsanitize=address main.c get_next_line.c get_next_line_utils.c 