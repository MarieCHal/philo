/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:37:57 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/12 12:19:29 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    make_params(int i, char *str, t_params *params)
{
    if (i == 0)
        params->philo = atoi(str);
    if (i == 1)
        params->die = atoi(str);
    if (i == 2)
        params->eat = atoi(str);
    if (i == 3)
        params->sleep = atoi(str);
        
}
//funtion that checks the arguments
void    trans_param(t_params *params, char **argv)
{
    int     i;
    int     j;
    int     len;
    char    *str;
    
    str = 0;
    len = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            len++;
            j++;
        }
        str = malloc(len);
        j = 0;
        while (argv[i][j])
        {
            str[j] = argv[i][j];
            j++;
        }
        str[j] = 0;
        make_params(i, str, params);
        free(str);
        len = 0;
        i++;
    }
}
//funtion that initialize the values of the params
int    init_param(t_params *params, char **argv, int argc)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    str = 0;
    if (argc != 4)
        return(0);
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (argv[i][j] > 57 || argv[i][j] < 48)
                return(0);
            j++;
        }
        i++;
    }
    trans_param(params, argv);
    return(1);
}
//function that creats the philo

//function that beggins the process of one on two philo (id % 2)

//function to be ued by the philosopher (sleep, eat, think)

//function that checks that locks and unlock the mutexes (called by the previous one)


int main(int argc, char **argv)
{
    t_params    params;

    if (!init_param(&params, argv, argc))
        return (0);
    printf("%d\n", params.philo);
    printf("%d\n", params.die);
    printf("%d\n", params.eat);
    printf("%d\n", params.sleep);
    return(0);
}