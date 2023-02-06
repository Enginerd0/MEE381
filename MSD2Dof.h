//============================================================================
// MSD2Dof.h:  Defines a 2 degree of freedom mass spring damper system
//
// MEE 381: Alex Urbina
//============================================================================
#pragma once

#include <string>
#include "sim.h"

class MSD2Dof : public Sim
{
public:
	MSD2Dof();
	~MSD2Dof();

	void setMasses(double mm1, double mm2);
	void setSpringConstants(double kk1, double kk2, double kk3);
	void setDampingConstants(double cc1, double cc2);

	void setPosition(double x1, double x2) {  }
	void setVelocity(double v1, double v2) { /* write code here */ }
	double x1() { }
	double x2() { /* write code here */ }
	double v1() { /* write code here */ }
	double v2() { /* write code here */ }

	void setInputAmplitude(double a);
	void setInputOmega(double omega);

	void calcEnergy(double& kt, double& pe, double& te);
	std::string toString();

private:
	double m1;          // mass of block 1 (kg)
	double m2;          // mass of block 2
	double k1;          // spring constants (N/m)
	double k2;
	double k3;
	double c1;          // viscous damping constants  (N*s/m)
	double c2;

	double mMin;        // smallest allowable mass  (kg)

	double inpA;        // amplitude of input signal
	double inpOmega;    // circular frequency of sinusoidal input

	void rhs(double* ff, double* x, double tm);
	double calcU(double t);
};
