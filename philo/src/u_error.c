/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:32:04 by cnatanae          #+#    #+#             */
/*   Updated: 2024/07/09 14:27:34 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_philo.h"

int	u_error(char *str, int is_exit)
{
	printf(RED"Philosophers: Error: %s\n"RST, str);
	if (is_exit)
		quit(1);
	return (1);
}
