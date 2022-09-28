/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:14:45 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 16:06:10 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_rout(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ft_printf(philo, philo->time, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	ft_printf(philo, philo->time, "has taken a fork");
	ft_printf(philo, philo->time, "is eating");
	philo->nb_meal = philo->nb_meal - 1;
	pthread_mutex_lock(&philo->params->eating);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->params->eating);
	my_usleep(philo->params->eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	ft_printf(philo, philo->time, "is sleeping");
	my_usleep(philo->params->sleep);
	ft_printf(philo, philo->time, "is thinking");
}

void	*rountine(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->philo_id % 2 == 0)
		usleep(1000);
	while (philo->params->dead == 0 && (philo->nb_meal != 0))
		philo_rout(philo);
	return (0);
}
