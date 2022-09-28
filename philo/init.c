/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:15:38 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 16:05:30 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_philo *philo_r, int i, t_params *params)
{
	philo->philo_id = i + 1;
	philo->nb_meal = params->nb_meal;
	philo->r_fork = &philo_r->l_fork;
	philo->params = params;
	philo->last_meal = get_time();
	philo->time = get_time();
	pthread_mutex_init(&philo->l_fork, NULL);
}

int	init_param(t_params *params, int argc, char **argv)
{
	if (argc == 5)
	{
		params->nb_philo = atoi(argv[1]);
		params->die = atoi(argv[2]);
		params->eat = atoi(argv[3]);
		params->sleep = atoi(argv[4]);
		params->nb_meal = -1;
		params->dead = 0;
		pthread_mutex_init(&params->writting, NULL);
		pthread_mutex_init(&params->eating, NULL);
	}
	else if (argc == 6)
	{
		params->nb_philo = atoi(argv[1]);
		params->die = (long)atoi(argv[2]);
		params->eat = (long)atoi(argv[3]);
		params->sleep = (long)atoi(argv[4]);
		params->nb_meal = atoi(argv[5]);
		params->dead = 0;
		pthread_mutex_init(&params->writting, NULL);
		pthread_mutex_init(&params->eating, NULL);
	}
	else
		return (0);
	return (1);
}
