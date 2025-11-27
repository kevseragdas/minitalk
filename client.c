#include "minitalk.h"

int answ_came = 0;

void    client_handler(int signal)
{
    (void)signal;
    answ_came = 1;
}
void    send_char(int pid, char c)
{
    int bit_index;

    bit_index = 7;
    while(bit_index >= 0)
    {
        answ_came = 0;
        if(((c >> bit_index) & 1) == 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        while(answ_came == 0)
            pause();
        bit_index--;
    }
}
int     main(int ac, char **arg)
{
    if(ac == 3)
    {
        int pid;
        int i;

        pid = atoi(arg[1]);
        if(pid <= 0)
        {
            write(2, "wrong pid!", 11);
            return (1);
        }
        signal(SIGUSR1, client_handler);
        i = 0;
        while(arg[2][i])
        {
            send_char(pid, arg[2][i]);
            i++;
        }
        send_char(pid, '\n');
    }
    else
    {
        write(2, "Eksik bilgi girdin!", 20);
        return (1);
    }
    return (0);
}
