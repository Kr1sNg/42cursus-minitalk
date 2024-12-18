/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:09:12 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/11/08 17:17:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** :::::::::::::::::::::::::::::::::* HEADERS *:::::::::::::::::::::::::::::: **
*/

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

/*
** :::::::::::::::::::::::::::* STRUCT DECLARATION *::::::::::::::::::::::::: **
*/

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

/*
** ::::::::::::::::::::::::::* FUNCTION PROTOTYPES *::::::::::::::::::::::::: **
*/

/*
**	is
*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);

/*
**	lst
*/

t_list	*ft_create_elem(void *data);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
void	ft_list_clear_fct(t_list *begin_list, void (*free_fct)(void *));
void	ft_list_clear(t_list *begin_list);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
			void *data_ref, int (*cmp)());
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list	*ft_list_last(t_list *begin_list);
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_list_reverse(t_list **begin_list);
int		ft_list_size(t_list	*begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void	ft_sorted_list_merge(t_list **begin_list1,
			t_list *begin_list2, int (*cmp)());

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *data);
int		ft_lstsize(t_list *lst);

/*
**	mem
*/

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

/*
**	put
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putendl(char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putstr(char *s);

/*
**	str
*/

char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
** to
*/

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*
**	
*/

#endif

/* 9
ft_lstadd_back.c
ft_lstadd_front.c
ft_lstclear.c
ft_lstdelone.c
ft_lstiter.c
ft_lstlast.c
ft_lstmap.c
ft_lstnew.c
ft_lstsize.c
*/
/* 11
ft_itoa.c
ft_putchar_fd.c
ft_putendl_fd.c
ft_putnbr_fd.c
ft_putstr_fd.c
ft_split.c
ft_striteri.c
ft_strjoin.c
ft_strmapi.c
ft_strtrim.c
ft_substr.c
*/
/* 23
ft_atoi.c
ft_bzero.c
ft_calloc.c
ft_isalnum.c
ft_isalpha.c
ft_isascii.c
ft_isdigit.c
ft_isprint.c
ft_memchr.c
ft_memcmp.c
ft_memcpy.c
ft_memmove.c
ft_memset.c
ft_strchr.c
ft_strdup.c
ft_strlcat.c 
ft_strlcpy.c 
ft_strlen.c
ft_strncmp.c
ft_strnstr.c
ft_strrchr.c
ft_tolower.c 
ft_toupper.c
*/