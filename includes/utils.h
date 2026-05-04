#ifndef UTILS_H
	#define UTILS_H

	#include "libs.h"
	#include "structs.h"
	#include "defines.h"

	int parse_flag(t_context *ping_obj, char **arg_input, int *i, int *j, int cnt_input);
	void open_socket(int* socket_fd);
	void close_socket(int socket_fd);
	void sig_handler(int signum);
	void print_error(const char *msg);
#endif