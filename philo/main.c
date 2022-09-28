/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:48:13 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/27 16:01:54 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
	{
		printf("Error malloc params\n");
		return (0);
	}
	if (!ft_parsing(argv))
	{
		printf("Invalid argument\n");
		free(params);
		return (0);
	}
	if (!init_param(params, argc, argv))
	{
		printf("Error while initializing params\n");
		free(params);
		return (0);
	}
	create_philo(params);
	free(params);
	return (0);
}
