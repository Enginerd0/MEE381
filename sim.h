//============================================================================
// sim.h   Header file for Sim class. Sim is a base class that can be used
//         to derive simulations for a variety of dynamic simulations.
//
// MEE 381, Alexander Urbina
//============================================================================
#pragma once

#include <string>

class Sim
{
public:
	Sim();
	virtual ~Sim();

	double time() { return(t); }
	void eulerStep(double dt);
	void rk4Step(double dt);
	void incrementTime(double dt) { t += dt; }

	virtual void calcEnergy(double& ke, double& pe, double& te);
	virtual std::string toString();

protected:
	int nStates;       // number of states
	double* x;         // array of states
	double* xI;        // array of intermediate states
	double* xI2;       // array of intermediate states      
	double* xI3;       // array of intermediate states
	double** f;        // array of slopes

	double rad2deg;    // converts radian to degree
	double deg2rad;    // converts degree to radian

	double oneBySix;   // 1.0/6.0

	void allocateStates();
private:
	double t;  // time

	virtual void rhs(double* ff, double* xx, double tm) = 0;
};