#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main(int argc, char* argv[]) {
    // Generator. Process selection. LHC initialization. Histogram.
    Pythia pythia;
    Event& event = pythia.event;

    // Read in commands from external file.
    if (argc != 2)
        pythia.readFile("../config/neutrino.cmnd");
    else {
        // Check that the provided input name corresponds to an existing file.
        ifstream is(argv[1]);
        if (!is) {
            cerr << " Command-line file " << argv[1] << " was not found. \n"
                 << " Program stopped! " << endl;
            return 1;
        }
        pythia.readFile(argv[1]);
    }

    // Extract settings to be used in the main program.
    int nEvent = pythia.mode("Main:numberOfEvents");

    // Initialize.
    pythia.init();

    // Begin event loop.
    for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
        cout << endl << "Event " << iEvent << endl;
        // Generate events.
        if (!pythia.next()) {
            cout << " Warning! Pythia::DoInteraction: failed! \n" << endl;
        }

        event.list();
        cout << "Final stable particles: " << endl;
        for (const auto & evt : event) {
            if (evt.isFinal()) {
                printf("Particle %d with P = (%f, %f, %f, %f) [GeV] \n", evt.id(), evt.px(), evt.py(), evt.pz(), evt.e());
            }
        }
        // End of event loop. Statistics. Done.
    }
    pythia.stat();
    return 0;
}
