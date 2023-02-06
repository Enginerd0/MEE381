//============================================================================
// main.cpp  Main program that serves as a "Sim player" for running a variety
//           of simulations.
//
//============================================================================
#include <ostream>
#include <iostream>
#include <fstream>
#include "pendulum.h"
#include "sim.h"
#include "MSD2Dof.h"

using namespace std;

enum SimType {
	PendulumSim,
	MSD2DofSim
	
};

Sim* initSim(SimType s);
ostream* initOutput(const char* fname);
int main()
{
	ostream* out = initOutput("");

	SimType simType = PendulumSim;
	Sim* sim = initSim(simType);

	double tEnd = 20.0;
	double dt = 0.01;

	/**/
	// Simulation loop
	*out << sim->toString() << endl;
	while (sim->time() < tEnd - 0.5 * dt) {
		sim->rk4Step(dt);
		*out << sim->toString() << endl;
	}
	// End of simulation loop
	/**/

	// clean up
	delete sim;
	if (out != &cout)
		delete out;

	return(0);
}

// initialize simulation
Sim* initSim(SimType s)
{
	if (s == PendulumSim) {
		Pendulum* pendPtr = new Pendulum;
		pendPtr->setTheta(1.0);
		pendPtr->setOmega(0.0);
		return(pendPtr);
	}
	if (s == MSD2DofSim) {
		MSD2Dof* msdPtr = new MSD2Dof;
		msdPtr->setPosition(0.5, 0.0);
		msdPtr->setVelocity(0.0, 0.0);
		msdPtr->setSpringConstants(10.0, 15.0, 15.0);
		msdPtr->setDampingConstants(0.0, 0.0);
		msdPtr->setInputAmplitude(0.0);
		msdPtr->setInputOmega(1.0);
		return(msdPtr);
	}

	return(nullptr);
}

// Initialize output pointer
ostream* initOutput(const char* fname)
{
	if (fname && !fname[0])
		return(&cout);

	return(new ofstream(fname));
}