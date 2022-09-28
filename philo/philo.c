/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:20:08 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 15:30:30 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < philo->params->nb_philo)
		{
			if (get_time() - philo[i].last_meal >= philo[i].params->die)
			{
				philo[i].params->dead = 1;
				ft_printf(&philo[i], philo[i].time, "died");
			}
			i++;
		}
		if (philo->params->dead == 1)
			break ;
	}
}

void	thread_join(int nb_philo, t_philo *philo)
{
	int	i;

	i = 0;
	if (nb_philo > 1)
	{
		while (i < nb_philo)
		{
			pthread_join(philo[i].thread_id, NULL);
			i++;
		}
	}
}

void	create_philo(t_params *params)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * params->nb_philo);
	if (!philo)
		printf("Error malloc philo\n");
	while (i < params->nb_philo)
	{
		if (i == (params->nb_philo - 1))
			philo_init(&philo[i], &philo[0], i, params);
		else
			philo_init(&philo[i], &philo[i + 1], i, params);
		pthread_create(&(philo[i].thread_id), NULL, rountine, &philo[i]);
		i++;
	}
	check_die(philo);
	thread_join(params->nb_philo, philo);
	free(philo);
}
