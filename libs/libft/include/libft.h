/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 04:02:09 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/08 15:47:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define INT_MAX 2147483647
# define CONV_TYPE "cspdiuxX%"
# define HEXADECIMAL_U "0123456789ABCDEF"
# define HEXADECIMAL_L "0123456789abcdef"
# define DECIMAL "1234546789"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

enum e_flags {minus = 1, zero = 2, dot = 4, sharp = 8, space = 16, plus = 32};

typedef struct s_conversions
{
	int		flags;
	int		width;
	int		precision;
}				t_flags;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// libft functions

double	ft_atof(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
int		ft_atoi_base(char *str, char *base);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
char	*ft_strrpl(const char *str, int old, int new);
void	*ft_memrpl(char *s, int old, int new, size_t n);

// ft_printf

int		ft_printf(const char *format, ...);

// get conversion specification functions

int		count_input(const char *f_string);
void	fill_inputs(char ***inputs, const char *format);

// format and output string functions

void	m_output(const char *format, char ***inputs, va_list args, int *l_out);
int		output(const char *format, int start, int end);
int		conv_args(va_list args, char ***inputs, int *i_format);

// get all flags

void	get_flags(char ***inputs, t_flags *flags);

// conv_type functions

int		p_conv(va_list arg, t_flags flags);
int		c_conv(va_list arg, t_flags flags);
int		s_conv(va_list arg, t_flags flags);
int		id_conv(va_list arg, t_flags flags);
int		u_conv(va_list arg, t_flags flags);
int		x_conv(va_list arg, t_flags flags);
int		xu_conv(va_list arg, t_flags flags);
int		perc_conv(void);

// hexadecimal convert functions

char	*hex_concat(char *src, char c);
void	ft_putnbr_base(unsigned int nbr, char *base, char **output);
void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output);
int		check_base(char *base);

// unsigned int conversion to string

char	*ft_utoa(unsigned int n);

// [width field] and [flags: '-0']

int		width_conv(t_flags flags, int l_out);
int		width_get(char ***inputs);
int		pad_output(t_flags flags, char *output);
int		check_zero(char ***inputs);
void	fill_zero(char **output, int width, char sign);
void	fill_zero_x(char **output, int width);

// [.precision]

int		check_precision(char ***inputs);
char	*number_precision(t_flags flags, char *output);

// [flags: '# +']

void	fill_sharp(char **output, char x);
void	fill_space(char **output);
void	fill_plus(char **output);

#endif
