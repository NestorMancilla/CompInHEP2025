#include <cmath>

class MET {
private:
    double met_x, met_y;

public:
    MET(double x, double y) : met_x(x), met_y(y) {}
    
    double getMET() const { return std::sqrt(met_x * met_x + met_y * met_y); }
    double getMETX() const { return met_x; }
    double getMETY() const { return met_y; }
    double getPhi() const { return std::atan2(met_y, met_x); }
};


