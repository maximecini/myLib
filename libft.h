/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:41:13 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/12/14 13:28:52 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <bsd/string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/******************************/
/*         DEF FORMAT          */
/*******************************/
# define CHAR 'c'
# define STRING 's'
# define DECIMAL 'd'
# define INTEGER 'i'
# define U_INTEGER 'u'
# define HEX_LOWER_ 'x'
# define HEX_UPP 'X'
# define POINTER 'p'
# define PERCENT '%'
/*******************************/
/*         base        */
/*******************************/
# define BASE_HEX "0123456789abcdef"
# define BASE_HEX_UPP "0123456789ABCDEF"
# define BASE_DEC "0123456789"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int letter);
int					ft_isdigit(int nb);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				*ft_memset(void *s, int c, size_t n);
size_t				ft_strlen(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *string, int searchedChar);
char				*ft_strrchr(const char *string, int searchedChar);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *p1, const void *p2, size_t size);
char				*ft_strnstr(const char *str, const char *search,
						size_t size);
int					ft_atoi(const char *str);
size_t				ft_digitlen(long long n, int size);
void				*ft_calloc(size_t s, size_t size_of);
char				*ft_strdup(const char *source);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
size_t				ft_base_power(long long s, int size_base);
int					ft_istouppercase(int c);
int					ft_islowercase(int c);
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*get_next_line(int fd);
size_t				ft_putnbr_base(int nbr, char *base);
void				ft_putnbr_base_printf(size_t number, char *base, int *i);
int					ft_display_uint(int number, void f(int, int *));
int					ft_display_base(size_t number, char *str, void f(size_t,
							char *, int *));
int					ft_display_string(void *str, void (*f)(char *, int));
unsigned int		valide_base(char *base);
int					ft_int_isdigit(int n);
void				ft_putnbr_printf(int nb, int *i);
int					ft_printf(const char *format, ...);
char				ft_todigits(int n);

#endif