#include "guilefunc.h"
#include "canvas.h"
#include "pointlist.h"

void* register_functions(void* data)
{
  scm_c_define_gsubr("draw-point", 2, 0, 0, &canvas_draw_point);
  return NULL;
}

static SCM canvas_draw_point(SCM arg_x, SCM arg_y)
{
  points_add(&Canvas.points, scm_to_int(arg_x), scm_to_int(arg_y));
  canvas_redraw();
  return SCM_EOL;
}
