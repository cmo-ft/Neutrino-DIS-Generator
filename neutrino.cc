// main01.cc is a part of the PYTHIA event generator.
// Copyright (C) 2023 Torbjorn Sjostrand.
// PYTHIA is licenced under the GNU GPL v2 or later, see COPYING for details.
// Please respect the MCnet Guidelines, see GUIDELINES for details.

// Keywords: basic usage; charged multiplicity

// This is a simple test program. It fits on one slide in a talk.
// It studies the charged multiplicity distribution at the LHC.

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
    int    nEvent    = pythia.mode("Main:numberOfEvents");
    int    nAbort    = pythia.mode("Main:timesAllowErrors");

    // Initialize.
    pythia.init();

    Hist mult("lepton multiplicity", 100, -0.5, 799.5);
    // Begin event loop.
    int iAbort = 0;
    for (int iEvent = 0; iEvent < nEvent; ++iEvent) {
        cout << endl << "Event " << iEvent << endl;
        // Generate events. Quit if too many failures.
        if (!pythia.next()) {
            cout << "Pythia::DoInteraction: failed! \n" << endl;
            if (++iAbort < nAbort) continue;
            cout << " Event generation aborted prematurely, owing to error!\n";
            break;
        }
        // Find number of all final charged particles and fill histogram.
        int nLepton = 0;
        for (const auto & evt : pythia.event) {
            if (evt.isFinal() && evt.isLepton()) {
                ++nLepton;
                printf("Particle %d with energy: %f \n", evt.id(), evt.e());
            }
        }
        mult.fill( nLepton );
        // End of event loop. Statistics. Histogram. Done.
    }
    pythia.stat();
    // cout << mult;
    return 0;
}
