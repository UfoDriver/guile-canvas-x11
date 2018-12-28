#include <X11/Xlib.h>
#include "pointlist.h"

#ifndef CANVAS_H
#define CANVAS_H

struct {
  Display* display;
  Window window;
  GC gc;
  PointList points;
  int points_num;
} Canvas;

void canvas_init();
void canvas_destroy();
void canvas_redraw();

#endif // CANVAS_H
