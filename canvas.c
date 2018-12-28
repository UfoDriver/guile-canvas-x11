#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "canvas.h"

void canvas_init()
{
  Canvas.display = XOpenDisplay(NULL);
  XSizeHints hints = {.x = 400,
                      .y = 200,
                      .width = 800,
                      .height = 800};
  int screen_number = DefaultScreen(Canvas.display);
  Canvas.window = XCreateSimpleWindow(Canvas.display, DefaultRootWindow(Canvas.display),
                                      hints.x, hints.y,
                                      hints.width, hints.height, 0,
                                      BlackPixel(Canvas.display, screen_number),
                                      WhitePixel(Canvas.display, screen_number));
  XSetStandardProperties(Canvas.display, Canvas.window ,"Guile canvas", "Guile canvas",
                         None, NULL, 0, NULL);
  XSelectInput(Canvas.display, Canvas.window, ExposureMask);
  Canvas.gc = XCreateGC(Canvas.display, Canvas.window, 0, 0);
  XMapRaised(Canvas.display, Canvas.window);

  points_init(Canvas.points);
}

void canvas_destroy()
{
  XFreeGC(Canvas.display, Canvas.gc);
  XDestroyWindow(Canvas.display, Canvas.window);
  XCloseDisplay(Canvas.display);
}

void canvas_redraw()
{
  XClearWindow(Canvas.display, Canvas.window);
  for (int i = 0; i < Canvas.points.used; i++) {
    XPoint point = Canvas.points.points[i];
    printf("Draw point at %d/%d\n", point.x, point.y);
    XDrawPoint(Canvas.display, Canvas.window, Canvas.gc, point.x, point.y);
  }
  XFlush(Canvas.display);
}
