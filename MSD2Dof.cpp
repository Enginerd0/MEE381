//============================================================================
// MSD2Dof.cpp:  Methods for the class
//
// MEE 381: Alexander Urbina
//============================================================================
#include <sstream>
#include <string>
#include "MSD2Dof.h"
#include <iostream>
#include <iomanip>

//---------------------------------------------------------------------------
// Constructor
//---------------------------------------------------------------------------
MSD2Dof::MSD2Dof()
{
	m1 = 1.0;
	m2 = 2.0;
	k1 = 0.0;
	k2 = 0.0;
	k3 = 0.0;
	c1 = 0.0;
	c2 = 0.0;

	mMin = 0.001;

	inpA = 0.0;
	inpOmega = 0.0;
}

//---------------------------------------------------------------------------
// Destructor
//---------------------------------------------------------------------------
MSD2Dof::~MSD2Dof()
{
 
}

//---------------------------------------------------------------------------
// setMasses: Sets the masses of the two blocks
//---------------------------------------------------------------------------
void MSD2Dof::setMasses(double mm1, double mm2)
{
	m1 = mm1 < mMin ? mMin : mm1;
	m2 = mm2 < mMin ? mMin : mm2;
	
	// This is equivalent to
	// if(mm1 < mMin)
	//     m1 = mMin;
	// else
	//     m1 = mm1;
}

//---------------------------------------------------------------------------
// setSpringConstants:
//---------------------------------------------------------------------------
void MSD2Dof::setSpringConstants(double kk1, double kk2, double kk3)
{
	k1 = kk1 < 0.0 ? 0.0 : kk1;
	k2 = kk2 < 0.0 ? 0.0 : kk2;
	k3 = kk3 < 0.0 ? 0.0 : kk3;
}

//---------------------------------------------------------------------------
// setDampingConstants:
//---------------------------------------------------------------------------
void MSD2Dof::setDampingConstants(double cc1, double cc2)
{
	c1 = cc1 < 0.0 ? 0.0 : cc1;
	c2 = cc2 < 0.0 ? 0.0 : cc2;
}

//---------------------------------------------------------------------------
// setInputAmplitude: 
//---------------------------------------------------------------------------
void MSD2Dof::setInputAmplitude(double a)
{
	inpA = a;
}

//---------------------------------------------------------------------------
// setInput
//---------------------------------------------------------------------------
void MSD2Dof::setInputOmega(double omega)
{
	inpOmega = omega;
}

//----------------------------------------------------------------------------
// rhs:  Right hand sides of the pendulum equations
//----------------------------------------------------------------------------
void MSD2Dof::rhs(double* ff, double* xx, double tm)
{
	/* write code here */
}

//----------------------------------------------------------------------------
// calcU: Calculate the forcing term
//----------------------------------------------------------------------------
double MSD2Dof::calcU(double tm)
{
	return(inpA * sin(inpOmega * tm));
}

//----------------------------------------------------------------------------
// calcEnergy: Calulates kinetic energy of two masses, potential of the
//             springs, and the sum of these two energies. Note that when
//             there is viscous damping, the system is conservative. 
//             Otherwise, it is not.
//----------------------------------------------------------------------------
void MSD2Dof::calcEnergy(double& ke, double& pe, double& te)
{
	/* write code here */
}

//----------------------------------------------------------------------------
// toString:
//----------------------------------------------------------------------------
std::string MSD2Dof::toString()
{
	std::ostringstream oss;
	/* write code here */
	oss.str("");  // get rid of this line when code is written above
	return(oss.str());
}