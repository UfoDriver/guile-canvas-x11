#include <stdlib.h>

#include "pointlist.h"


void points_init(PointList point_list)
{
  point_list.allocated = 128;
  point_list.used = 0;
  point_list.points = calloc(point_list.allocated, sizeof(XPoint));
}

void points_destroy(PointList point_list)
{
  point_list.allocated = 0;
  point_list.used = 0;
  free(point_list.points);
  point_list.points = 0;
}

void points_add(PointList* point_list, int x, int y)
{
  if (point_list->used == point_list->allocated) {
    point_list->allocated *= 2;
    point_list->points = realloc(point_list->points, point_list->allocated * sizeof(XPoint));
  }
  XPoint new_point = {x, y};
  point_list->points[point_list->used++] = new_point;
}

void points_remove(PointList point_list, int x, int y)
{
  for (int i = 0; i < point_list.used; i++) {
    if (point_list.points[i].x == x && point_list.points[i].y == y) {
      /* point_list.points[i] = 0; */
    }
  }
}

void points_remove_all(PointList point_list)
{
  point_list.used = 0;
}
