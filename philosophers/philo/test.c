#include <stdio.h> // printf
#include <sys/time.h> // time
#include <unistd.h> // usleep

// struct timeval {
//     time_t      tv_sec;     // seconds
//     suseconds_t tv_usec;    // microseconds
// };

size_t	r_get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	r_usleep(size_t sleeptime)
{
	size_t starting_time;
	int	i = 0;
	starting_time = r_get_time();
	while((r_get_time() - starting_time) < sleeptime)
		i++;
	return (0);
}
void    example()
{
    struct timeval  start_time;
    struct timeval  end_time;
    long requested_sleep_time;
    long actual_sleep_time;

    requested_sleep_time = 200 * 1000;  // 200 milliseconds
    gettimeofday(&start_time, NULL);
    r_usleep(requested_sleep_time);
    gettimeofday(&end_time, NULL);
    actual_sleep_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

    printf("Requested Sleep Time: %ld microseconds\n", requested_sleep_time);
    printf("Actual Sleep Time: %ld microseconds\n", actual_sleep_time);
}

int main()
{
    example();

    return (0);
}
