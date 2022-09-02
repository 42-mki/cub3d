/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:43:30 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:43:39 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "../bmp/includes/libbmp.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isdigit(int c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char *s, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
char			*ft_strnew(size_t size);
void			ft_strdel(char **str);
int				get_next_line(int fd, char **line);
char			*ft_strcpy(char *dest, const char *src);

#endif
