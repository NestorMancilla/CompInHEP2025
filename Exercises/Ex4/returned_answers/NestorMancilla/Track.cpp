#include "Track.h"

Track::Track(double px, double py, double pz, double E) : px(px), py(py), pz(pz), E(E) {}

Track::~Track() {}

double Track::getPx() const { return px; }
double Track::getPy() const { return py; }
double Track::getPz() const { return pz; }
double Track::getE() const { return E; }

double Track::getPT() const {
    return std::sqrt(px * px + py * py);
}

double Track::getEta() const {
    double theta = std::atan2(getPT(), pz);
    return -std::log(std::tan(theta / 2.0));
}

void Track::print() const {
    std::cout << "Track: pT = " << getPT() << ", eta = " << getEta() << std::endl;
}

