#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "SDL2/SDL.h"

#include "entity.hpp"
#include "vector2d.hpp"
#include "emitter_info.hpp"

class Particle : public Entity
{
private:
    Vector2D        acceleration;
    Vector2D        velocity;
    Emitter_Info*   emitter_info;
    /******************************
    * TODO:
    * consider having a pointer to
    * emitter_info.this may save on
    * space for things like end color,
    * life_span, vel_cap, and
    * initial_position
    *******************************/
    SDL_Color       color;

    unsigned int    spawn_time;
    float           life_span;  /// Milliseconds
    float           velocity_cap;

    float           particle_scale;

    bool            alive;

public:
    /*ctr*/         Particle(Emitter_Info&);


    /*dtr*/         ~Particle();

    /// probably unneeded
    void            kill_particle();

    void            update(); /// need to push delta time into.
    bool            is_alive();

    /// DEBUG
    static float    DEBUG_MOVEMENT;
};

#endif
