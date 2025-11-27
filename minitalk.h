#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h> // silmeyi unutma
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_server
{
    int     bit_counter;
    unsigned char chr;
}   t_server;

#endif