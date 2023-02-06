//=========================================================================== =
// sim.cpp  Methods for the base class
//
// MEE 381, Your Name Here
//============================================================================
#include <iostream>
#include "sim.h"

using namespace std;

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
Sim::Sim()
{
	//cout << "Entering Sim::Sim" << endl;

	nStates = 0;
	x = nullptr;
	xI = nullptr;
	f = nullptr;

	t = 0.0;

	rad2deg = 180.0 / 3.14159265358979323;
	deg2rad = 1.0 / rad2deg;

	oneBySix = 1.0 / 6.0;
}

//---------------------------------------------------------------------------
// Destructor
//---------------------------------------------------------------------------
Sim::~Sim()
{
	// de-allocate states
	if (x != nullptr) {
		delete[] x;
		delete[] xI;

		for (int i = 0; i < 4; ++i)
			delete[] f[i];
		delete[] f;
	}
}

//----------------------------------------------------------------------------
// allocateState:  Allocate memory for the state
//----------------------------------------------------------------------------
void Sim::allocateStates()
{
	//cout << "inside allocateStates with nStates = " << nStates << endl;

	if (nStates == 0) {
		cerr << "Sim::allocateStates: cannot allocate with nStates == 0"
			<< endl;
		return;
	}

	if (x != nullptr) {
		cerr << "Sim::allocateStates: can only allocate once." << endl;
		return;
	}

	int i, j;
	x = new double[nStates];
	xI = new double[nStates];

	f = new double* [4];
	for (i = 0; i < 4; ++i)
		f[i] = new double[nStates];

	// initialize with zeros
	for (i = 0; i < nStates; ++i) {
		x[i] = 0.0;
		xI[i] = 0.0;
		for (j = 0; j < 4; ++j)
			f[j][i] = 0.0;
	}
}

//----------------------------------------------------------------------------
// eulerStep: perform one Euler step of the pendulum equations for specified
//            time step
//----------------------------------------------------------------------------
void Sim::eulerStep(double dt)
{
	// write your own code here
}

//----------------------------------------------------------------------------
// rk4Step: perform one fourth order Runge-Kutta step of the pendulum 
//          equations for specified time step
//----------------------------------------------------------------------------
void Sim::rk4Step(double dt)
{
	int i;
	//predictor step
	rhs(f[0], x, t);
	for (i = 0; i < nStates; ++i) {
		xI[i] = x[i] + f[0][i] * dt * 0.5;
	}
	rhs(f[1], xI, t + dt * 0.5);
	for (i = 0; i < nStates; ++i) {

		xI2[i] = x[i] + f[1][i] * dt * 0.5;
	}
	rhs(f[2], xI2, t + dt);
	for (i = 0; i < nStates; ++i)
	{
		xI3[i] = x[i] + f[2][i] * dt;

	}
	//corrector step 
	rhs(f[3], xI3, t + dt);
	for (i = 0; i < nStates; ++i) {
		x[i] += 0.1667 * (f[0][i] + 2 * f[1][i] + 2 * f[2][i] + f[3][i]) * dt;
	}
}
//----------------------------------------------------------------------------
// calcEnergy: A place holder for derived classes that do not have a 
//             calcEnergy class
//----------------------------------------------------------------------------
void Sim::calcEnergy(double& ke, double& pe, double& te)
{
//	ke = 0.0;
//	pe = 0.0;
//	te = 0.0;
}

//----------------------------------------------------------------------------
// toString: A place holder for derived classes that to not have a string
//           conversion
//----------------------------------------------------------------------------
string Sim::toString()
{
	string s = "";
	return(s);
}