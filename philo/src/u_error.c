/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:32:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/05 15:19:25 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo.h"

int	u_error(char *str, t_data *data)
{
	printf(RED"Philosophers: Error: %s\n"RST, str);
	if (data)
		u_exit(data);
	return (1);
}
