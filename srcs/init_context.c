#include "../includes/libs.h"
#include "../includes/structs.h"
#include "../includes/defines.h"
#include <limits.h>

void     init_context(t_context *ping_obj) {

    memset(ping_obj, 0, sizeof(*ping_obj));
    ping_obj->socket = -1;
    ping_obj->target.sin_family = AF_INET;
    ping_obj->stats.min = INT_MAX;

    for (int i = 0; i < FLAG_SIZE; i++) {
        ping_obj->flags[i] = 0;
    }
}