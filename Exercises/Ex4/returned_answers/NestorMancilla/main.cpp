#include "Track.h"
#include "SimulatedTrack.h"

int main() {
    Track t(1.0, 2.0, 3.0, 4.0);
    t.print();

    SimulatedTrack st(1.0, 2.0, 3.0, 4.0, 11, 22);
    st.print();

    return 0;
}

