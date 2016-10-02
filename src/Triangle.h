#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

typedef struct TriangleTag {
    float ax;
    float ay;
    float bx;
    float by;
    float cx;
    float cy;
} Triangle;


Triangle *Triangle_main(void);
void Triangle_draw(Triangle *);

#endif
