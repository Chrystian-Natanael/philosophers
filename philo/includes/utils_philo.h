/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:25:12 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/01 09:13:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PHILO_H
# define UTILS_PHILO_H

# include "philo.h"

int		u_error(char *str, t_data *data);
void	u_exit(t_data *data);
long	get_time(void);
long	u_usleep(long time);
long	u_atol(const char *str);
bool	is_in_strings(char c, char *str);

#endif