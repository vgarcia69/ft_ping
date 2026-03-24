#ifndef STRUCTS_H
    #define STRUCTS_H

    #include "libs.h"
    #include "defines.h"

    typedef struct s_context {
        struct sockaddr_in target;
        uint16_t seq;
        char target_ip[INET_ADDRSTRLEN];
        char *target_host;
        int socket;
        int flags[FLAG_SIZE];
        t_stats stats;
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