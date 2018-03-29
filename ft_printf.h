/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:48:12 by skholodn          #+#    #+#             */
/*   Updated: 2017/03/20 12:47:17 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** LIBRARIES
*/

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <string.h>
# include <stddef.h>

# define DIGIT(d) (d >= '0' && d <= '9' ? 1 : 0)
# define MOD(x) ((x) < 0 ? -(x) : (x))

# define SPEC "sSpdDioOuUxXcC"

# define H_H (**fmt == 'h' && *(*fmt + 1) == 'h')
# define L_L (**fmt == 'l' && *(*fmt + 1) == 'l')
# define P_N_U (e->precision - u->size_nbr)
# define W_N_U (e->width - u->size_nbr)
# define P_N_X (e->precision - oxp->size_nbr)
# define W_N_X (e->width - oxp->size_nbr)
# define P_PRE (e->precision)
# define P_P (oxp->size_prefix)
# define P_Z (oxp->size_nbr + oxp->size_zero)
# define GET_O (e->spec == 'o' || e->spec == 'O')
# define GET_NB (!nb && (e->f->hash || e->precision == 0))
# define GET_HEX (e->precision != -1 && !nb)

# define BLACK           	"\033[22;30m"
# define BLACK_COLOR     	"{black}"
# define RED             	"\033[22;31m"
# define RED_COLOR       	"{red}"
# define GREEN           	"\033[22;32m"
# define GREEN_COLOR     	"{green}"
# define BROWN           	"\033[22;33m"
# define BROWN_COLOR     	"{brown}"
# define BLUE            	"\033[22;34m"
# define BLUE_COLOR      	"{blue}"
# define MAGENTA         	"\033[22;35m"
# define MAGENTA_COLOR   	"{magenta}"
# define CYAN            	"\033[22;36m"
# define CYAN_COLOR      	"{cyan}"
# define GRAY            	"\033[22;37m"
# define GRAY_COLOR      	"{gray}"
# define DARK_GRAY       	"\033[01;30m"
# define DARK_GRAY_COLOR 	"{dark gray}"
# define LIGHT_RED			"\033[01;31m"
# define LIGHT_RED_COLOR 	"{light red}"
# define LIGHT_GREEN     	"\033[01;32m"
# define LIGHT_GREEN_COLOR	"{light green}"
# define LIGHT_YELLOW   		"\033[01;33m"
# define LIGHT_YELLOW_COLOR  "{light yellow}"
# define LIGHT_BLUE     		"\033[01;34m"
# define LIGHT_BLUE_COLOR    "{light blue}"
# define LIGHT_MAGENTA  		"\033[01;35m"
# define LIGHT_MAGENTA_COLOR "{light magenta}"
# define LIGHT_CYAN     		"\033[01;36m"
# define LIGHT_CYAN_COLOR    "{light cyan}"
# define WHITE          		"\033[01;37m"
# define WHITE_COLOR     	"{white}"
# define EOC            		"\033[0m"
# define EOC_COLOR           "{eoc}"

# define NP_NULL "<NULL>"
# define NP_SOH "<SOH>"
# define NP_STX "<STX>"
# define NP_ETX "<ETX>"
# define NP_EOT "<EOT>"
# define NP_ENQ "<ENQ>"
# define NP_ACK "<ACK>"
# define NP_BEL "<BEL>"
# define NP_BS "<BS>"
# define NP_HT "<HT>"
# define NP_LF "<LF>"
# define NP_VT "<VT>"
# define NP_FF "<FF>"
# define NP_CR "<CR>"
# define NP_SO "<SO>"
# define NP_SI "<SI>"
# define NP_DLE "<DLE>"
# define NP_DC1 "<DC1>"
# define NP_DC2 "<DC2>"
# define NP_DC3 "<DC3>"
# define NP_DC4 "<DC4>"
# define NP_NAK "<NAK>"
# define NP_SYN "<SYN>"
# define NP_ETB "<ETB>"
# define NP_CAN "<CAN>"
# define NP_EM "<EM>"
# define NP_SUB "<SUB>"
# define NP_ESC "<ESC>"
# define NP_FS "<FS>"
# define NP_GS "<GS>"
# define NP_RS "<RS>"
# define NP_US "<US>"
# define NP_CHAR "<NOT A NON-PRINTABLE CHAR>"

# define NULLSTR (ft_strncpy_p(s->str, "(null)", (size_t)s->size_str))
# define BASICSTR (ft_strncpy_p(s->str, arg, (size_t)s->size_str))

typedef struct	s_di
{
	int			size_zero;
	int			size_space;
	int			size_nbr;
	int			size_sign;
	char		*zero;
	char		*space;
	char		*nbr;
	char		*sign;
}				t_di;

typedef struct	s_u
{
	int			size_zero;
	int			size_space;
	int			size_nbr;
	char		*zero;
	char		*space;
	char		*nbr;
}				t_u;

typedef struct	s_oxp
{
	int			size_zero;
	int			size_space;
	int			size_nbr;
	int			size_prefix;
	char		*zero;
	char		*space;
	char		*nbr;
	char		*prefix;
}				t_oxp;

typedef struct	s_float
{
	int			total_size;
	int			size_sign;
	int			size_width_len;
	int			size_exponenta;
	int			size_dot;
	int			size_presigion;
	char		sign;
	char		*str;
	char		*s;
	long long	round_nb;
}				t_float;

typedef struct	s_s
{
	int			size_space;
	int			size_str;
	char		*space;
	char		*str;
}				t_s;

typedef struct	s_fl
{
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			zero;
}				t_fl;

typedef struct	s_e
{
	int			bits_count;
	t_fl		*f;
	int			mod;
	int			width;
	int			precision;
	int			dollar;
	char		spec;
	int			fd;
}				t_e;

void			make_fprintf(t_e *e, va_list ar);
void			select_bonus(t_e *e, va_list ar);
void			select_efga(t_e *e, va_list ar);
void			select_oxp(t_e *e, va_list ar);
void			select_u(t_e *e, va_list ar);
void			select_di(t_e *e, va_list ar);
void			apply_width(t_e *e);
t_s				*str_c_init(t_e *e);
void			free_str_c(t_s *s);
void			get_char(int c, t_e *e);
t_s				*c_init(t_e *e);
void			free_c(t_s *s);
void			get_nbr(intmax_t nb, t_e *e);
t_di			*init_di(intmax_t nb, t_e *e);
void			init_char_di(t_di *di, intmax_t nb, t_e *e);
int				get_size_nb(uintmax_t nb);
void			free_di(t_di *di);
void			get_f(long double nb, t_e *e);
t_float			*init_float(long double *val, t_e *e);
void			round_me(long double nb, t_e *e, char *str);
void			round_me_d(long double nb, t_e *e, char *str);
void			put_nb_str(uintmax_t nb, char **str);
long double		fraction_nb(long double nbr);
long double		ft_floor(long double nbr);
long double		ft_ceil(long double nbr);
int				ft_atoi_p(const char *s);
int				ft_printf(char *fmt, ...);
int				ft_vsprintf(int bits_count, char *fmt, va_list ar);
void			str_cpy(t_e *e, char **fmt);
t_e				*env_init(int bits);
t_fl			*init_flags(void);
char			*ft_strcat_p(char *dest, const char *src);
char			*ft_strchr_p(const char *s, int c);
char			*ft_strcpy_p(const char *dest, const char *src);
size_t			ft_strlen_p(const char *str);
char			*ft_strncpy_p(char *dest, const char *src, size_t len);
char			*ft_strnew_p(size_t size);
int				ft_tolower_p(int c);
void			get_binary(unsigned char c, t_e *e);
void			get_iso_data(long date, t_e *e);
void			char_iso(long date, t_e *e);
int				check_isodate(int *ymd);
char			*str_iso(int *ymd);
void			get_n(int *n, t_e *e);
void			get_str(char *arg, t_e *e);
t_s				*str_init(char *arg, t_e *e);
void			free_str(t_s *s);
void			get_wstr(wchar_t *wstr, t_e *e);
int				wchar_len(wchar_t *wstr);
char			*get_wchar_cpy(char *str, int wchar, int j, int n);
char			*wstrncpy(char *str, wchar_t *wstr, int n);
t_s				*wstr_init(wchar_t *wstr, t_e *e);
void			free_wstr(t_s *s);
void			u_make_str(uintmax_t value, uintmax_t base, char *str, int *i);
char			*u_itoa_base(uintmax_t value, uintmax_t base);
void			itoa_float(t_e *e, t_float *f, int i);
char			*itoa_double(long double val, t_e *e);
char			*ft_strdup_p(const char *src);
void			ft_strdel_p(char **str);
void			get_if_oxp(uintmax_t *nb, t_e *e, t_oxp *oxp);
void			get_noprint(char *str, t_e *e);
void			noprt_f(char c, t_e *e);
void			noprt_s(char c, t_e *e);
void			noprt_t(char c, t_e *e);
void			noprtswitch(char c, t_e *e);
void			get_oxp(uintmax_t nb, t_e *e);
void			get_lower(t_oxp *oxp);
void			init_char_oxp(t_oxp *oxp, t_e *e);
t_oxp			*init_oxp(uintmax_t nb, t_e *e);
void			free_oxp(t_oxp *oxp);
void			find_color(t_e *e, char **fmt, va_list ar);
int				parse_color(t_e *e, char *fmt, va_list ar);
int				parse_color_inside(t_e *e, char *fmt);
int				ft_strstr_stop(const char *str, const char *to_find);
int				find_flag(t_e *e, char c);
int				find_mod_mv(char **fmt);
int				find_mod_mv_two(char **fmt);
int				find_mod(t_e *e, char **fmt);
int				find_conver(t_e *e, char c);
void			find_precision(t_e *e, char **fmt);
void			find_width(t_e *e, char **fmt);
void			free_e(t_e *e);
void			find_star(t_e *e, char **fmt, va_list ar);
void			find_dollar(char **fmt, t_e *e);
void			apply_dollar(va_list ar, va_list tmp, int i);
void			parse_persent(t_e *e, char **fmt, va_list ar, va_list tmp);
void			get_unbr(uintmax_t nb, t_e *e);
void			init_char_u(t_e *e, t_u *u, uintmax_t nb);
t_u				*init_u(uintmax_t nb, t_e *e);
void			free_u(t_u *u);

#endif
