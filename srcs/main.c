#include "../includes/libs.h"
#include "../includes/structs.h"
#include "../includes/defines.h"

int main(void)
{
    t_context ping_obj;

    init_context(&ping_obj);

    parse_arguments(&ping_obj);

    setup_socket(&ping_obj);

    link_signal_handlers();

    while (condition)
    {
        /* code */
    }

    print_final_stats(&ping_obj.stats);
    
    close_socket(ping_obj.socket);

    return 0;
}