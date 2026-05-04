#include "../includes/libs.h"
#include "../includes/structs.h"
#include "../includes/defines.h"
#include <ctype.h>

int parse_arguments(t_context *ping_obj, char **arg_input, int cnt_input) {
    if (cnt_input <= 1) {
        write(2, "ping: usage error: Destination address required", 48);
        return 1;
    }

    for (int i = 1; i < cnt_input; i++) {
        int j = 1;
        if (arg_input[i][0] == '-' && parse_flag(ping_obj, arg_input, &i, &j, cnt_input)) {
            return 1;
        } else if (parse_host(ping_obj, arg_input[i])) {
            return 1;
        }
    }
    return 0;
}   

int parse_flag(t_context *ping_obj, char **arg_input, int *i, int *j, int cnt_input) {
    switch (arg_input[*i][*j]) {
        case 'v':
            ping_obj->flags[F_VERBOSE] = 1;
            break;
        case '?':
            ping_obj->flags[F_HELP] = 1;
            break;
        case 'n':
            ping_obj->flags[F_NODNS] = 1;
            break;
        case 'w':
            if (*i + 1 < cnt_input) {
                ping_obj->flags[F_TIMEOUT] = atoi(arg_input[++(*i)]);
            }
            break;
        case 'W':
            if (*i + 1 < cnt_input) {
                ping_obj->flags[F_WAIT] = atoi(arg_input[++(*i)]);
            }
            break;
        case 's':
            if (*i + 1 < cnt_input) {
                ping_obj->flags[F_SIZE] = atoi(arg_input[++(*i)]);
            }
            break;
        case 'c':
            if (*i + 1 < cnt_input) {
                ping_obj->flags[F_TOTAL] = atoi(arg_input[++(*i)]);
            }
            break;
        default:
            if (isspace(arg_input[*i][*j] && *j > 1)) {
                return 0;
            }
            write(2, "ping: invalid option -- ", 25);
            write(2, &arg_input[*i][*j], 1);
            write(2, "\n", 1);
            return 1;
    }

    (*j)++;

    parse_flag(ping_obj, arg_input, i, j, cnt_input);
    
    return 0;
}

int parse_host(t_context *ping_obj, char *host) {
    struct in_addr addr;

    if (inet_pton(AF_INET, host, &addr) == 1) {
        ping_obj->target.sin_addr = addr;
        inet_ntop(AF_INET, &addr, ping_obj->target_ip, INET_ADDRSTRLEN);
        ping_obj->target_host = strdup(host);
        if (!ping_obj->target_host) {
            write(2, "ping: memory allocation failed\n", 31);
            return 1;
        }
    } else {
        struct hostent *he = gethostbyname(host);
        if (he) {
            memcpy(&ping_obj->target.sin_addr, he->h_addr_list[0], he->h_length);
            inet_ntop(AF_INET, &ping_obj->target.sin_addr, ping_obj->target_ip, INET_ADDRSTRLEN);
            ping_obj->target_host = strdup(host);
            if (!ping_obj->target_host) {
                write(2, "ping: memory allocation failed\n", 31);
                return 1;
            }
        } else {
            write(2, "ping: unknown host ", 20);
            write(2, host, strlen(host));
            write(2, "\n", 1);
            return 1;
        }
    }
    return 0;
}