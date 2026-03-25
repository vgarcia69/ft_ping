#include "../includes/libs.h"
#include "../includes/structs.h"
#include "../includes/defines.h"

int g_signal = 0;

void sig_handler(int _) {
    (int)_;
    g_signal = 1;
}

int main(int ac, char **av) {
    t_context ping_obj;

    init_context(&ping_obj);

    if (parse_arguments(&ping_obj, av)) {
        write(2, "ping: usage error: Destination address required", 48);
        exit(1);
    }
    
    setup_socket(&ping_obj);

    signal(SIGINT, sig_handler);

    link_signal_handlers();

    while (1)
    {
        /* code */
    }

    print_final_stats(&ping_obj.stats);
    
    close_socket(ping_obj.socket);

    return 0;
}