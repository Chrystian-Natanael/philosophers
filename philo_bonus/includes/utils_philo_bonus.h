/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:33:59 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 15:41:17 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PHILO_BONUS_H
# define UTILS_PHILO_BONUS_H

# include "philo_bonus.h"

typedef enum e_time_code
{
	SECONDS,
	MILLISECONDS,
	MICROSECONDS
}	t_time_code;

int		u_error(char *str, int is_exit);
long	get_time(t_time_code code);
long	u_atol(const char *str);
bool	is_in_strings(char c, char *str);

#endif