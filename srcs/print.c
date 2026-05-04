#include "../includes/libs.h"
#include "../includes/structs.h"
#include "../includes/defines.h"


print_error(const char *type, const char *msg) {
	write(2, "ping: ", 6);
	write(2, type, strlen(type));
	write(2, " error: ", 7);
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
}