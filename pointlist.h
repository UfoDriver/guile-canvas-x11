#include <X11/Xlib.h>

#ifndef POINTLIST_H
#define POINTLIST_H

typedef struct {
  XPoint* points;
  int allocated;
  int used;
} PointList;

void points_init(PointList point_list);
void points_add(PointList* point_list, int x, int y);
void points_remove(PointList point_list, int x, int y);
void points_remove_all(PointList point_list);

#endif // POINTLIST_H
