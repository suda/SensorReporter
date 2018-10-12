#include "reporter_particle.h"

void ReporterParticle::report(Sample _sample)
{
    String name = this->prefix;
    name.concat(_sample.name);
    Particle.publish(name, _sample.value);
}
void ReporterParticle::setPrefix(String _prefix)
{
    this->prefix = _prefix;
};