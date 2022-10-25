/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:00:00 by gponcele          #+#    #+#             */
/*   Updated: 2022/10/18 15:40:03 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>
# include	<limits.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_element	t_element;
typedef struct s_list		t_list;

struct	s_element
{
	int					number;
	int					index;
	int					pos;
	int					target_pos;
	int					cost_a;
	int					cost_b;
	t_element			*next;
};

struct s_list
{
	t_element			*first;
	char				label;
};

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int				ft_atoi(char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_printf(const char *s, ...);
// int				ft_formats(va_list ap, const char format);
int				ft_check_formats(char c, char *set);
int				ft_print_str(char *str);
int				ft_print_percent(void);
int				ft_print_char(char c);
int				ft_strlen_int(int n);
char			*ft_itoa_printf(int n);
int				ft_print_nbr(int nb);
int				ft_strlen_int_unsigned(unsigned int n);
char			*ft_itoa_unsigned(unsigned int n);
int				ft_print_unsigned(unsigned int nb);
int				ft_print_hex(unsigned int n, const char format);
int				ft_print_ptr(unsigned long ptr);
int				ft_get_hex_ptr_len(unsigned long n);
char			*ft_get_hex(unsigned int num, const char format,
					unsigned int len);
char			*ft_get_ptr(unsigned long num, unsigned int len);
void			error(char *msg);
void			error2(char *msg, t_list *a, t_list *b);
void			error4(void);
void			success(char *msg, t_list *a, t_list *b);
void			success2(char *msg, t_list *a, t_list *b);
void			success3(t_list *a, t_list *b, int op);
void			success4(t_list *a, t_list *b, int op);
void			ft_free(t_list *stack);
int				ft_iszero(char *str);
// get_next_line.c
char			*get_next_line(int fd);
char			*read_and_stash(int fd, char *str);
char			*make_new_line(char *str);
char			*ft_clean(char *str);
// get_next_line_utils.c
char			*empty_string(void);

#endif