/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:46:46 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 15:25:23 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_params
{
	int				nb_philo;
	long int		die;
	long int		eat;
	long int		sleep;
	int				dead;
	int				nb_meal;
	pthread_mutex_t	writting;
	pthread_mutex_t	eating;

}				t_params;

typedef struct s_philo
{
	int				philo_id;
	pthread_t		thread_id;
	pthread_t		control;
	int				nb_meal;
	long int		last_meal;
	long int		time;
	t_params		*params;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
}				t_philo;

int			main(int argc, char **argv);
int			ft_parsing(char **argv);
void		philo_init(t_philo *philo, t_philo *philo_r,
				int i, t_params *params);
int			init_param(t_params *params, int argc, char **argv);
void		create_philo(t_params *params);
void		*rountine(void *philo_void);
int			ft_atoi(const char *str);
void		ft_printf(t_philo *philo, long int init, char *message);
void		my_usleep(int time_ms);
long int	get_time(void);
void		*check_philo(void *philo_void);

#endif
