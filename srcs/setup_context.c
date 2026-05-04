#include "../includes/libs.h"
#include "../includes/structs.h"
#include "../includes/defines.h"
#include <limits.h>

void init_context(t_context *ping_obj) {

    memset(ping_obj, 0, sizeof(*ping_obj));
    ping_obj->socket = -1;
    ping_obj->target.sin_family = AF_INET;
    ping_obj->stats.min = INT_MAX;

    for (int i = 0; i < F_TOTAL; i++) {
        ping_obj->flags[i] = 0;
    }
}

void open_socket(int* socket_fd) {
    *socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (*socket_fd < 0) {
        perror("socket");
        exit(1);
    }
}

void link_signal_handlers() {
    // signal(SIGALRM, handle_alarm);
    // signal(SIGINT, handle_interrupt);
}

void close_socket(int socket_fd) {
    if (socket_fd >= 0) {
        close(socket_fd);
    }
}