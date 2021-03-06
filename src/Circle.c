#include <math.h>
#include <stdio.h>
#include "Circle.h"
#include "Triangle.h"
#include "Coords.h"

#define MATH_TAU 2 * 3.14159


static void create_triangles(Circle *self);
static void set_triangle(Circle *self, Triangle *triangle, int i);
static float translate_coords(float angle, float radius);


Circle *Circle_new(Drawer *drawer)
{
    Circle *self = malloc(sizeof(Circle));

    self->coords = Coords_new();
    self->drawer = drawer;
    self->radius = 1;
    self->triangle_count = 100;

    create_triangles(self);

    return self;
}


void Circle_destroy(Circle *self)
{
    int i = 0;

    for (i = 0; i < self->triangle_count; i++) {
        Triangle_destroy(self->triangles[i]);
    }

    free(self);
}

void Circle_set_x(Circle *self, float x)
{
    self->coords->x = x;

    Circle_update_triangles(self);
}

void Circle_set_y(Circle *self, float y)
{
    self->coords->y = y;

    Circle_update_triangles(self);
}

void Circle_set_radius(Circle *self, float radius)
{
    self->radius = radius;

    Circle_update_triangles(self);
}

void Circle_draw(Circle *self)
{
    int i;

    for (i = 0; i < self->triangle_count; i++) {
        Triangle_draw(self->triangles[i]);
    }
}

void Circle_update_triangles(Circle *self)
{
    int i;
    float count = self->triangle_count;
    Triangle **triangles = self->triangles;

    for (i = 0; i < count; i++) {
        set_triangle(self, triangles[i], i);
    }
}


static void create_triangles(Circle *self)
{
    int i;
    int count = self->triangle_count;
    self->triangles = malloc(count * sizeof(Triangle));
    Triangle *triangle;

    for (i = 0; i < count; i++) {
        triangle = Triangle_new(self->drawer);

        set_triangle(self, triangle, i);

        self->triangles[i] = triangle;
    }
}

static void set_triangle(Circle *self, Triangle *triangle, int i)
{
    int count = self->triangle_count;
    float x = self->coords->x;
    float y = self->coords->y;
    float radius = self->radius;

    float rad_b = (i / (float)count) * MATH_TAU;
    float rad_c = ((i + 1) / (float)count) * MATH_TAU;
    
    triangle->x = x;
    triangle->y = y;
    triangle->ax = 0;
    triangle->ay = 0;
    triangle->bx = translate_coords(cos(rad_b), radius);
    triangle->by = translate_coords(sin(rad_b), radius);
    triangle->cx = translate_coords(cos(rad_c), radius);
    triangle->cy = translate_coords(sin(rad_c), radius);
}

static float translate_coords(float angle, float radius)
{
    return angle * radius;
}
