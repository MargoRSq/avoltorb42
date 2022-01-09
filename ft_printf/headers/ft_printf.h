/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svyatoslav <svyatoslav@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:21:45 by avoltorb          #+#    #+#             */
/*   Updated: 2022/01/03 13:39:28 by svyatoslav       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define TRUE 1

typedef struct putnbr_params
{
	int						hex;
	int						neg;
	int						unsgnd;
	int						num_len;
	int						base_len;
	char					*base;
	unsigned long long int	print_num;
	long long				num;
}	t_num_params;

typedef struct conversion_params
{
	int			left_width;
	int			right_width;
	int			width_zero;
	char		flag;
	const char	*str;
	va_list		*args;
	int			dot;
	int			skip;
	int			zero;
	int			plus;
	int			sharp;
	int			minus;
	int			space;

}	t_conv_params;

int		ft_printf(const char *str, ...);

int		ft_handle_conversions(int *i, const char *str,
			char flag, va_list *args);
int		ft_putchar_move(int *i, const char *c_ptr);
int		ft_print_space(t_conv_params *params);
void	ft_put_chars(int count, char c);

int		ft_search_flag(int *i, char *flags, const char *str);
char	ft_flagschr(char *flags, const char *str);
char	ft_strchr(const char *str, char c);

int		ft_putchar(t_conv_params params);
int		ft_putstr(t_conv_params params);
int		ft_putprocent(void);
int		ft_putnbr(t_conv_params params, int unsd, int hex);

void	ft_put_str(t_conv_params params, char *str);
int		ft_print_nonzero(t_conv_params params, int len, char *str);
int		ft_print_space_string(t_conv_params params, int len);
int		ft_print_double_width(t_conv_params params, int len, char *str);
int		ft_count_printed_str(t_conv_params params, char *str);
void	ft_put_nonwidth(t_conv_params params, char *str, int right);
void	ft_put_dot(t_conv_params params, char *str, int left, int right);
void	ft_put_left_greater(t_conv_params params,
			char *str, int left, int right);
void	ft_put_right_greater(t_conv_params params,
			char *str, int left, int right);

void	ft_put_nbr(t_conv_params params, t_num_params num_params);
void	ft_put_prefix_space(t_conv_params params, t_num_params num_params);
void	ft_put_prefix_zeros(t_conv_params params, t_num_params num_params);
void	ft_isneg(t_conv_params params, t_num_params *num_params);
void	ft_base(t_conv_params params, t_num_params *num_params);
void	ft_put_widthspace_plus(t_conv_params params, t_num_params num_params);
void	ft_put_double_width_num(t_conv_params params, t_num_params num_params);
void	ft_put_single_width_num(t_conv_params params, t_num_params num_params);
int		ft_count_printed_len(t_conv_params params, t_num_params num_params);
void	ft_put_width_nbr(t_conv_params params, t_num_params num_params);
void	ft_put_plus_minus(t_conv_params params, t_num_params num_params);
void	ft_put_spminus(int count, int toprint, int isminus);

int		ft_count_zero(t_conv_params params, t_num_params num_params);
int		ft_count_nonzero(t_conv_params params, t_num_params num_params,
			int right, int left);
int		ft_count_right_dot(t_conv_params params, int len, int left, int right);
int		ft_count_left_greater(t_conv_params params,
			int len, int left, int right);
int		ft_count_right_greater(t_conv_params params,
			int len, int left, int right);
int		ft_count_nonwidth(t_conv_params params, int len, int right);

void	ft_atoi_fill(int *i, t_conv_params *params);
void	ft_fill_params(t_conv_params *params, const char *str);
void	ft_fill_conv_params(t_conv_params *params, int j);
void	ft_fetch_width(t_conv_params *params, int *j, int *i);

int		ft_strlen(char *str, char c);
int		ft_digits_base(t_num_params num_params, t_conv_params params);
void	ft_putnbr_base(unsigned long long int n,
			unsigned long long base_len, char *base);
void	ft_put_zero(t_conv_params params, t_num_params num_params);
int		ft_max(int a, int b);

#endif
