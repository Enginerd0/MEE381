//============================================================================
// pendulum.h   Pendulum is a class derived from Sim, specifically for 
//              simulating a pendulum.
//
// MEE 381, Alexande Urbina
//============================================================================
#pragma once

#include <string>
#include "sim.h"

class Pendulum : public Sim
{
public:
	Pendulum();
	~Pendulum();

	void setLength(double ll);
	void setGravity(double gg);

	void setTheta(double th);
	void setOmega(double om);
	void setThetaDeg(double th);
	void setOmegaDeg(double om);
	double theta() { return(x[0]); }
	double omega() { return(x[1]); }
	double thetaDeg() { return(x[0] * rad2deg); }
	double omegaDeg() { return(x[1] * rad2deg); }

	void calcEnergy(double& ke, double& pe, double& te);
	std::string toString();

private:
	double g;    // gravity constant
	double L;    // length of pendulum
	double gByL; // g/L

	void rhs(double* ff, double* x, double tm);
};
