/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:59:09 by msales-a          #+#    #+#             */
/*   Updated: 2020/07/30 16:28:26 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

/*
** 	pad		# padding
** 	prc		# precision
** 	siz		# size
** 	neg		# negative
** 	chf		# characters on format string
** 	pch		# char to use for padding (' ' or '0')
** 	typ		# type of char to print
** 	cis		# chars in string size
**	hpr		# has precision
**  ngi		# integer is negative
*/

typedef struct	s_prtform
{
	int		pad;
	int		prc;
	int		siz;
	int		neg;
	int		chf;
	char	pch;
	char	typ;
	int		cis;
	int		hpr;
	int		ngi;
}				t_prtform;
int				ft_printf(const char *str, ...);
t_prtform		*ft_fp_precision(t_prtform *form, char *str, va_list lst);
t_prtform		*ft_fp_width(t_prtform *form, char *str, va_list lst);
t_prtform		*ft_fp_flag(t_prtform *form, char *str, va_list lst);
t_prtform		*ft_formparser(t_prtform *form, char const *str, va_list lst);
int				ft_pchr(char c, t_prtform *form);
int				ft_phex(unsigned long int i, t_prtform *form, int swt);
int				ft_pint(long int i, t_prtform *form);
int				ft_pstr(char *s, t_prtform *form);
int				ft_puin(unsigned int i, t_prtform *form);
int				ft_testint(char c);
int				ft_testinttype(char c);
int				ft_isvalid(t_prtform *form, char *str);
int				ft_testprcpad(t_prtform *form, int num);
void			ft_padtest(t_prtform *form);
t_prtform		*ft_initform(t_prtform *form);
int				ft_countdig(unsigned long long int n, int b);
void			ft_revstr(char *s, int size);
char			*ft_itoabase(unsigned long long int n, int b);
void			ft_uppercase(char *s);
int				ft_vprintf(t_prtform *form, va_list lst, int count);
int				ft_redint(int n, t_prtform *form);
int				ft_redlint(unsigned long int n, t_prtform *form);
int				ft_reduint(unsigned int n, t_prtform *form);
void			ft_pn(int length, int *ptr);
char			*ft_precisionchar(char *s, t_prtform *form);
char			*ft_precisionint(char *s, t_prtform *form);
int				ft_padding(t_prtform *form);
char			*ft_negint(t_prtform *form, int i, char *s);
void			ft_printpad(t_prtform *form, char *s);
int				ft_isalpha(int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strchr(char *s, int c);
void			ft_putstr_fd(char *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_isdigit(char c);
int				ft_atoi(char *s);

#endif
