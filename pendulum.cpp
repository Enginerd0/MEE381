//============================================================================
// pendulum.cpp  Methods for the class
//
// MEE 381, Alexander Urbina
//============================================================================
#include <iostream>
#include <sstream>
#include "pendulum.h"

using namespace std;

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
Pendulum::Pendulum()
{
	cout << "Entering Pendulum::Pendulum" << endl;

	nStates = 2;
	g = 9.81;
	L = 0.75;
	gByL = g / L;

	allocateStates();

}

//---------------------------------------------------------------------------
// Destructor
//---------------------------------------------------------------------------
Pendulum::~Pendulum()
{
	//cout << "Pendulum::~Pendulum" << endl;
}

//----------------------------------------------------------------------------
// setTheta: set angle of pendulum
//----------------------------------------------------------------------------
void Pendulum::setTheta(double th) {
	x[0] = th;
}

//----------------------------------------------------------------------------
// setThetaDeg: set angle of pendulum in degrees
//----------------------------------------------------------------------------
void Pendulum::setThetaDeg(double th) {
	x[0] = th * deg2rad;
}

//----------------------------------------------------------------------------
// setOmega: set angular velocity of pendulum
//----------------------------------------------------------------------------
void Pendulum::setOmega(double om) {
	x[1] = om;
}

//----------------------------------------------------------------------------
// setOmegaDeg: set angular velocity of pendulum in degrees per second
//----------------------------------------------------------------------------
void Pendulum::setOmegaDeg(double om) {
	x[1] = om * deg2rad;
}

//----------------------------------------------------------------------------
// setLength: sets length of pendulum (in meters by default)
//----------------------------------------------------------------------------
void Pendulum::setLength(double ll)
{
	if (ll < 0.005) {
		cerr << "Pendulum::setLength: ERROR length too small" << endl;
		return;
	}
	L = ll;
	gByL = g / L;
}

//----------------------------------------------------------------------------
// setGravity: sets the gravitational accel (in m/s^2 by default)
//----------------------------------------------------------------------------
void Pendulum::setGravity(double gg)
{
	g = gg;
	gByL = g / L;
}

//----------------------------------------------------------------------------
// calcEnergy: Calculate kinetic, potential, and total energy for the 
//             pendulum
//----------------------------------------------------------------------------
void Pendulum::calcEnergy(double& ke, double& pe, double& te)
{
	ke = 0.5 * L * L * x[1] * x[1];
	pe = g * L * (1.0 - cos(x[0]));
	te = ke + pe;
}

//----------------------------------------------------------------------------
// toString:
//----------------------------------------------------------------------------
string Pendulum::toString()
{
	ostringstream oss;

	double ke, pe, te;
	calcEnergy(ke, pe, te);

	oss << time() << "," << theta() << "," << ke << "," << pe << "," << te;
	return(oss.str());
}

//----------------------------------------------------------------------------
// rhs:  Right hand sides of the pendulum equations
//----------------------------------------------------------------------------
void Pendulum::rhs(double* ff, double* xx, double tm)
{
	
	ff[0] = xx[1];
	ff[1] = -gByL * sin(xx[0]);


}