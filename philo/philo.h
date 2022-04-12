/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:46:46 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/12 12:17:54 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
#include <pthread.h>

typedef struct  s_params
{
    int philo;
    int die;
    int eat;
    int sleep;
    
}               t_params;

typedef struct  s_philo
{
    t_params    parmas;
    int         id;
    pthread_mutex_t   mut;     
}               t_philo;

int main(int argc, char **argv);
int	ft_atoi(const char *str);

#endif