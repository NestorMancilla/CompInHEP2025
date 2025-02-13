#ifndef TRACK_H
#define TRACK_H

#include <cmath>
#include <iostream>

class Track {
public:
    Track(double px, double py, double pz, double E);
    ~Track();

    double getPx() const;
    double getPy() const;
    double getPz() const;
    double getE() const;
    
    double getPT() const;
    double getEta() const;

    void print() const;

private:
    double px, py, pz, E;
};

#endif // TRACK_H
