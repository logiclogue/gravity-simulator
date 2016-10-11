#include <stdlib.h>
#include "Universe.h"
#include "Particle.h"


Universe *Universe_main(int particle_count)
{
    Universe *self = malloc(sizeof(Universe));

    self->particle_count = particle_count;
    self->particles = malloc(sizeof(Particle) * particle_count);

    return self;
}
