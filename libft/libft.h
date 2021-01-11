/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:55:47 by acase             #+#    #+#             */
/*   Updated: 2020/11/04 11:14:04 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int			ft_atoi(char *str);
char		*ft_itoa(int n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_putchar(char c);
void		ft_putendl(char const *s);
void		ft_putstr(char *str);
char		*ft_strcpy(char *str1, char *str2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s1);
char		*ft_strncpy(char *str1, char *str2, unsigned int nb);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memset(void *s, int c, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_bzero(char *s, size_t n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		*ft_memccpy(void *dst, const void *src,
			int c, size_t n);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strnstr(char *str1, char *str2, size_t size);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(char *str1, char *str2, unsigned int nb);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strnstr(char *str1, char *str2, size_t size);
char		*ft_strrchr(const char *s, int c);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src,
			size_t dstsize);
char		**ft_split(char const *s, char c);
size_t		ft_strlcpy(char *dst, const char *src,
			size_t dstsize);

#endif
