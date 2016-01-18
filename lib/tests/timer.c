#include <timer.h>
#include <libft.h>

#include <stdio.h>

struct timeval		*get_timer(e_flag flag)
{
	static struct	timeval save;
	static char		first = 1;

	if (first)
	{
		gettimeofday(&save, 0);
		first = 0;
	}
	else if (flag == RESET)
		gettimeofday(&save, 0);
	return (&save);
}

void				start_timer(void)
{
	get_timer(RESET);
}

int					elapsed_time(void)
{
	struct timeval		*before;
	struct timeval		after;

	before = get_timer(NOTHING);
	gettimeofday(&after, 0);
	return (after.tv_sec * 1000LL + after.tv_usec / 1000 - before->tv_sec * 1000LL + before->tv_usec / 1000);
}

void				tell_timer(void)
{
	dprintf(2, "%i", elapsed_time()); // ft_putnbr_fd(elapsed_time(), 2);
}
