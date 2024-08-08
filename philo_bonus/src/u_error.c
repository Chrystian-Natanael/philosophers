/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:38:20 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/16 15:38:41 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo_bonus.h"

int	u_error(char *str, int is_exit)
{
	printf(RED"Philosophers: Error: %s\n"RST, str);
	if (is_exit)
		quit(1);
	return (1);
}
