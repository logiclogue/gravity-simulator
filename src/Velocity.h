#ifndef _VELOCITY_H_
#define _VELOCITY_H_

typedef struct VelocityTag {
    float x;
    float y;
} Velocity;


Velocity *Velocity_new(void);
void Velocity_append(float *velocity_component, float change_velocity);
float Velocity_get_resultant(Velocity *self);

#endif
