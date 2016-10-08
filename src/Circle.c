#include "Circle.h"
#include "Triangle.h"


static void create_triangles(Circle *self);


Circle *Circle_main(Drawer *drawer)
{
    Circle *self = malloc(sizeof(Circle));

    self->drawer = drawer;
    self->x = 0;
    self->y = 0;
    self->radius = 1;
    self->triangle_count = 10;

    create_triangles(self);

    return self;
}


static void create_triangles(Circle *self)
{
    int i;
    int count = self->triangle_count;
    self->triangles = malloc(count);

    for (i = 0; i < count; i++) {
        self->triangles[i] = Triangle_main(self->drawer);
    }
}
