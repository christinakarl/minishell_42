/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:13:00 by ckarl             #+#    #+#             */
/*   Updated: 2023/09/14 14:56:53 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

//philo msg
# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIE "died"
# define FINISH "All philosphers finished their meals"
# define FINISH_ZERO "The philosophers did not eat since \
the max amount of meals is 0"
# define ONLY_ONE "The lonely philospher died a tragic death \
because there was only one fork"
//alloc error
# define ALLOC_ERR "Allocation error"
//input error
# define INPUT_ERR "Please enter between 4 and 5 valid input \
parameters: ./philo [nr of philosophers] \
[time to die] [time to eat] [time to sleep] \
[*optional: nr of times a philospher must eat]"
# define INPUT_FORMAT "Please enter positive integers (without\
 any signs) as input parameters"
# define INPUT_PHILO "Please enter between 1 and 200 as a first\
 parameter"
//thread error
# define CREATE_ERR "Pthread_create() error"
# define JOIN_ERR "Pthread_join() error"
//time error
# define TIME_ERR "Could not retrieve time of day"

struct s_struct;

typedef struct s_philo
{
	struct s_struct	*data;
	pthread_t		observer;
	int				id;
	int				meals_nbr;
	int				last_meal;
	int				dead;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_struct
{
	pthread_t		*threads;
	t_philo			*philo;
	int				total_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				total_meals;
	int				finished;
	int				stop;
	int				start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	meals_lock;
	pthread_mutex_t	write_lock;
}	t_struct;

/*	utils_1.c	*/
void	print_msg(char *str, t_philo *philo);
int		error_msg(char *str, t_struct *data);
void	clear_all(t_struct *data);
int		get_current_time(t_struct *data);
int		ft_usleep(int milli_sleep, t_struct *data);

/*	utils_2.c	*/
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *str, int fd);
int		ft_strcmp(char *str, char *comp);

/*	checks.c	*/
int		check_input(char **argv);
int		check_if_dead(t_philo *philo);
int		check_if_all_finished(t_philo *philo);

/*	init.c	*/
int		init_data(t_struct *data, int argc, char **argv);
int		allocate_memory(t_struct *data);
void	init_philos(t_struct *data);
int		run_threads(t_struct *data);
int		run_one_thread(t_struct *data);

/*	routine.c	*/
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	*routine(void *p);
void	*one_routine(void *p);
void	*obs_routine(void *p);

#endif