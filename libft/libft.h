/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syeresko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:37:22 by syeresko          #+#    #+#             */
/*   Updated: 2019/04/26 20:13:05 by syeresko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	This is an abridged version of libft:
**	without `t_list` conflicting with the one used in lem-in
**	and without all other unused stuff.
*/

# include <stddef.h>

void		*ft_memcpy(void *dst, const void *src, size_t n);

size_t		ft_strlen(const char *s);

char		*ft_strdup(const char *s1);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strncpy(char *dst, const char *src, size_t len);

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*
**	string functions
*/

char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);

char		**ft_strsplit(char const *s, char c);

/*
**	generic table function
*/

void		ft_clear_tab(void **tab);

/*
**	write functions
*/

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putnbr(int n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
**	get_next_line
*/

# define GNL_BUF_SIZE	32
# define GNL_ERROR		(-1)
# define GNL_EOF		0
# define GNL_OK			1

typedef struct s_flist	t_flist;

struct		s_flist
{
	int		fd;
	char	buf[GNL_BUF_SIZE];
	int		start;
	int		end;
	t_flist	*next;
};

int			get_next_line(int fd, char **line);

#endif
