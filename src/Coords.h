#ifndef _COORDS_H_
#define _COORDS_H_

typedef struct CoordsTag {
    float x;
    float y;
} Coords;


Coords *Coords_new();
void Coords_destroy(Coords *self);

#endif
