/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:46:01 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 15:12:17 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

int	ft_parsing(char **argv)
{
	int	j;
	int	i;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < 48 || argv[j][i] > 57)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_printf(t_philo *philo, long int init, char *message)
{
	static int	count = 0;

	pthread_mutex_lock(&philo->params->writting);
	if (philo->params->dead == 0 && (philo->nb_meal != 0))
		printf("%ld philo %d: %s\n",
			(get_time() - init), philo->philo_id, message);
	else if (philo->params->dead == 1 && count == 0 && (philo->nb_meal != 0))
	{
		printf("%ld philo %d: %s\n",
			(get_time() - init), philo->philo_id, message);
		count = 1;
	}
	pthread_mutex_unlock(&philo->params->writting);
}
