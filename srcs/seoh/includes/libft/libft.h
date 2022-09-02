/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:11:17 by seoh              #+#    #+#             */
/*   Updated: 2020/10/25 06:20:57 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

# define BUFFER_SIZE 4095

int			get_next_line(int fd, char **line);

int			ft_isalpha(int c);
int			ft_isascii(int a);
int			ft_isdigit(int a);
int			ft_isalnum(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);

void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);

char		*ft_itoa(int n);

void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(const char *s, char c);

void		ft_putendl_fd(char *s, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);

#endif
