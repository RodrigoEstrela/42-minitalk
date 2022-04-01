/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:46:29 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/02 14:52:16 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdarg.h>
# include<stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long long	ft_atoi(const char *str);

int			ft_isascii(int c);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		ft_putendl_fd(char *s, int fd);

char		*ft_strdup(const char *s1);

size_t		ft_strlen(const char *s);

char		*ft_strtrim(const char *s1, const char *set);

void		ft_bzero(void *s, size_t n);

int			ft_isdigit(int c);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		ft_putnbr_fd(int n, int fd);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

char		*ft_substr(const char *s, unsigned int start, size_t len);

void		*ft_calloc(size_t count, size_t size);

int			ft_isprint(int c);

void		*ft_memmove(void *dst, const void *src, size_t len);

void		ft_putstr_fd(char *s, int fd);

char		*ft_strjoin(const char *s1, const char *s2);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			ft_tolower(int c);

int			ft_isalnum(int c);

char		*ft_itoa(int n);

void		*ft_memset(void *b, int c, size_t len);

char		**ft_split(const char *s, char c);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

int			ft_toupper(int c);

int			ft_isalpha(int c);

void		*ft_memchr(const void *s, int cm, size_t n);

void		ft_putchar_fd(char c, int fd);

char		*ft_strchr(const char *s, int c);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

char		*ft_strrchr(const char *s, int c);

void		ft_puthex(int nbr, char *base);

void		ft_putptr(void *ptr);

t_list		*ft_lstnew(void *content);

void		ft_lstadd_front(t_list **lst, t_list *new);

int			ft_lstsize(t_list *lst);

t_list		*ft_lstlast(t_list *lst);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst, void (*del)(void *));

void		ft_lstclear(t_list **lst, void (*del)(void *));

void		ft_lstiter(t_list *lst, void (*f)(void *));

void		ft_putunbr_fd(unsigned int nb, int fd);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
