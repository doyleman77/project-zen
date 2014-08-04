#include "particle_emitter.hpp"

void Particle_Emitter::ctr_helper(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
{
    particle_texture = p_texture;

    max_particles = p_cap;

    position.set(pos_x, pos_y);

    alive_particles = 0;
    alive = false;
    particle_life_span = 0.0;

    velocity_cap = 0.0;
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture)
                 : Entity(NULL)
{
    ctr_helper(p_texture, 0, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap)
                 : Entity(NULL)
{
    ctr_helper(p_texture, p_cap, 0, 0);
};

Particle_Emitter::Particle_Emitter(SDL_Texture* p_texture, int p_cap, int pos_x, int pos_y)
                 : Entity(NULL)
{
    ctr_helper(p_texture, p_cap, pos_x, pos_y);
};

Particle_Emitter::~Particle_Emitter()
{
    for(int i = 0; i < particles.size(); i++)
      delete particles.at(i);

    particles.clear();
};

void Particle_Emitter::create_particle()
{
    particles.push_back(new Particle(
        particle_texture, alive, particle_life_span,
        acceleration.get_x(), acceleration.get_y(),
        velocity.get_x(), velocity.get_y(),
        velocity_cap));
};

void Particle_Emitter::attach_to_entity(Entity* n_entity)
{
    if(n_entity)
        attached_entity = &(*n_entity); /// need to check validity every tick
};

void Particle_Emitter::update()
{
    std::vector<Particle*>::iterator iter;
    for(iter = particles.begin(); iter != particles.end(); iter++)
    {
        (*iter)->update();
    }
}
