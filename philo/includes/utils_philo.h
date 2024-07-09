/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:25:12 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/09 20:04:26 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PHILO_H
# define UTILS_PHILO_H

# include "philo.h"

typedef enum e_time_code
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_time_code;

int		u_error(char *str, int is_exit);
long	get_time(t_time_code code);
long	u_usleep(long time);
void	u_precise_usleep(long usec, t_data *data);
long	u_atol(const char *str);
bool	is_in_strings(char c, char *str);

#endif