#include "SimulatedTrack.h"
#include <iostream>

SimulatedTrack::SimulatedTrack(double px, double py, double pz, double E, int pid, int parent)
    : Track(px, py, pz, E), particleId(pid), parentId(parent) {}

SimulatedTrack::~SimulatedTrack() {}

int SimulatedTrack::getParticleId() const { return particleId; }
int SimulatedTrack::getParentId() const { return parentId; }

void SimulatedTrack::print() const {
    Track::print();
    std::cout << "Simulated: Particle ID = " << particleId << ", Parent ID = " << parentId << std::endl;
}

