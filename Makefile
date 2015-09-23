## Made by timothee tosi

NAME	=	shunting_yard

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I./inc						\
		-Wall						\
		-Werror						\
		-pedantic

SRC	=	src/shunting_yard.c				\
		src/param/check_param.c				\
		src/param/check_op.c				\
		src/param/get_param.c				\
		src/str/is_number.c				\
		src/str/in_array.c				\
		src/str/str_base_cmp.c				\
		src/str/my_getnbr.c				\
		src/str/my_strlen.c				\
		src/str/my_strcpy.c				\
		src/str/my_putstr.c				\
		src/str/my_puterror.c				\
		src/memory/my_strdup.c				\
		src/memory/my_strndup.c				\
		src/memory/my_memset.c				\
		src/linked-list/new_linked_list.c		\
		src/linked-list/push_front.c			\
		src/linked-list/push_front_elem.c		\
		src/linked-list/push_back.c			\
		src/linked-list/push_back_elem.c		\
		src/linked-list/push_n.c			\
		src/linked-list/pop_front_elem.c		\
		src/linked-list/show_list.c			\
		src/linked-list/show_node.c			\
		src/linked-list/show_reverse_list.c		\
		src/linked-list/free_node.c			\
		src/parser/parser.c				\
		src/parser/parse_l_bracket.c			\
		src/parser/parse_r_bracket.c			\
		src/parser/parse_sp_operator.c			\
		src/parser/parse_wp_operator.c			\
		src/parser/parse_operand.c			\
		src/parser/set_res.c				\
		src/parser/lexer/lexer.c			\
		src/parser/lexer/l_bracket.c			\
		src/parser/lexer/r_bracket.c			\
		src/parser/lexer/sp_operator.c			\
		src/parser/lexer/wp_operator.c			\
		src/parser/lexer/p_operand.c			\
		src/parser/lexer/n_operand.c			\
		src/uniform/uniform_to_zero.c			\
		src/uniform/uniform_result.c			\
		src/uniform/uniform_sym.c			\
		src/uniform/epure_sym.c				\
		src/shunting-yard/operator_rule.c		\
		src/shunting-yard/operand_rule.c		\
		src/shunting-yard/left_parenthesis_rule.c	\
		src/shunting-yard/right_parenthesis_rule.c	\
		src/shunting-yard/output_rule.c			\
		src/shunting-yard/infix_to_postfix.c		\
		src/shunting-yard/evaluate_postfix.c		\
		src/operation/op_init.c				\
		src/operation/inf_add.c				\
		src/operation/inf_sub.c				\
		src/operation/inf_mul.c				\
		src/operation/inf_div.c				\
		src/operation/set_sub_add.c			\
		src/operation/set_mul.c				\
		src/operation/set_div.c				\
		src/operation/set_dividend.c			\
		src/operation/set_mod.c

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re