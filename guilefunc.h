#include <libguile.h>

#ifndef GUILEFUNC_H
#define GUILEFUNC_H

static SCM canvas_draw_point(SCM arg_x, SCM arg_y);
static SCM canvas_draw_line(SCM arg_start_x, SCM arg_start_y, SCM arg_end_x, SCM arg_end_y);
void* register_functions(void* data);

#endif // GUILEFUNC_H
