#include <libguile.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "canvas.h"
#include "guilefunc.h"
#include "pointlist.h"


int main(int argc, char* argv[])
{
  canvas_init();
  Atom delWindow = XInternAtom(Canvas.display, "WM_DELETE_WINDOW", 0);
  XSetWMProtocols(Canvas.display, Canvas.window, &delWindow, 1);

  scm_with_guile(&register_functions, NULL);
  /* scm_shell(argc, argv); */
  scm_c_eval_string("(use-modules (system repl server))");
  scm_c_eval_string("(spawn-server)");

  points_add(&Canvas.points, 50, 50);
  points_add(&Canvas.points, 100, 100);

  XEvent event;
  for (;;) {
    XNextEvent(Canvas.display, &event);
    switch (event.type) {
    case MapNotify:
      break;
    case Expose:
      // if (event.xexpose.count == 0) { */
      canvas_redraw();
      break;
    case ClientMessage:
      canvas_destroy();
      return EXIT_SUCCESS;
    }
  }

  canvas_destroy();
  return EXIT_SUCCESS;
}
