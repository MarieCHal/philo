/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:34:58 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 15:16:33 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;
	long int		result;

	gettimeofday(&time, NULL);
	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (result);
}

void	my_usleep(int ms)
{
	long	start;
	long	curr;

	start = get_time();
	curr = start;
	while (curr < start + ms)
	{
		curr = get_time();
		usleep(200);
	}
}
