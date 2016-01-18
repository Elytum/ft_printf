#ifndef TIMER_H
# define TIMER_H

#include <sys/time.h>

typedef enum	s_flag
{
	NOTHING = 0,
	RESET
}				e_flag;

struct timeval		*get_timer(e_flag flag);
void				start_timer(void);
int					elapsed_time(void);
void				tell_timer(void);

#endif
