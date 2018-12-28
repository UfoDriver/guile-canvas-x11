#include <X11/Xlib.h>

#ifndef LINELIST_H
#define LINELIST_H

typedef struct {
  XPoint* points;
  int allocated;
  int used;
} LineList;

/* void points_init(LineList point_list); */
/* void points_add(LineList* point_list, int x, int y); */
/* void points_remove(LineList point_list, int x, int y); */
/* void points_remove_all(LineList point_list); */

#endif // LINELIST_H
