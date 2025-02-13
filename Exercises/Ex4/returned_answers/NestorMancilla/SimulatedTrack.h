#ifndef SIMULATEDTRACK_H
#define SIMULATEDTRACK_H

#include "Track.h"

class SimulatedTrack : public Track {
public:
    SimulatedTrack(double px, double py, double pz, double E, int pid, int parent);
    ~SimulatedTrack();

    int getParticleId() const;
    int getParentId() const;

    void print() const;

private:
    int particleId, parentId;
};

#endif // SIMULATEDTRACK_H

