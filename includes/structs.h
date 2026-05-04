#ifndef STRUCTS_H
    #define STRUCTS_H

    #include "libs.h"
    #include "defines.h"

    typedef enum e_flag {
        F_VERBOSE,   
        F_HELP,      
        F_NODNS,     
        F_TIMEOUT,   
        F_WAIT,      
        F_SIZE,      
        F_COUNT,     
        F_TOTAL      
    } t_flag;

    typedef struct s_context {
        struct sockaddr_in target;
        uint16_t seq;
        char target_ip[INET_ADDRSTRLEN];
        char *target_host;
        int socket;
        t_flag flags[F_TOTAL];
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