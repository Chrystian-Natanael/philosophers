/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:25:12 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/09 14:27:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PHILO_H
# define UTILS_PHILO_H

# include "philo.h"

int		u_error(char *str, int is_exit);
long	get_time(void);
long	u_usleep(long time);
long	u_atol(const char *str);
bool	is_in_strings(char c, char *str);

#endif