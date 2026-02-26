#ifndef STRUCTS_H
    #define STRUCTS_H

    #include "libs.h"
    #include "defines.h"

    typedef struct s_context {
        int socket;
        struct sockaddr_in target;
        int flags[FLAG_SIZE];
    } t_context;

    typedef struct s_stats {
        int packets_sent;
        int packets_received;
        int min;
        int max;
        int avg;
        int stddev;
    } t_stats;

#endif