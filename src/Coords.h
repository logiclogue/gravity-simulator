#ifndef _COORDS_H_
#define _COORDS_H_

typedef struct CoordsTag {
    int x;
    int y;
} Coords;


Coords *Coords_new(int x, int y);
void Coords_destroy(Coords *self);

#endif
