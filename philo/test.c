/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:04:58 by mchalard          #+#    #+#             */
/*   Updated: 2022/04/06 13:13:24 by mchalard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct      s_mut
{
        pthread_mutex_t mutex;
}                   t_mut;


void    message(int i)
{
    char    *str;
    int     j;

    str = "message\n";
    j = 0;
    while (str[j])
    {
        write(1, &str[j], 1);
        j++;
    }
    write(1, &i, 1);
}

void    *printnumb(void *mut)
{
    static int i = 0;
    t_mut       *mut2;
    
    mut2 = (t_mut *)mut;
    pthread_mutex_lock(&mut2->mutex);
    message (i);
    pthread_mutex_unlock(&mut2->mutex);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t   test1;
    pthread_t   test2;
    int         i;
    t_mut  mut;

    i = 1;
    pthread_mutex_init(&mut.mutex, NULL);    
    pthread_create(&test1, NULL, printnumb, &mut);
    pthread_create(&test2, NULL, printnumb, &mut);
    pthread_join(test1, NULL);
    pthread_join(test2, NULL);
    return(0);
}
