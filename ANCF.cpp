#include "include.h"

double ANCFSystem::getCurrentTime()
{
	return time;
}
double ANCFSystem::getSimulationTime()
{
	return simTime;
}
double ANCFSystem::getTimeStep()
{
	return h;
}
double ANCFSystem::getTolerance()
{
	return tol;
}
int ANCFSystem::setSimulationTime(double simTime)
{
	this->simTime = simTime;
	return 0;
}
int ANCFSystem::setTimeStep(double h)
{
	this->h = h;
	return 0;
}
int ANCFSystem::setTolerance(double tolerance)
{
	this->tol = tolerance;
	return 0;
}
int ANCFSystem::getTimeIndex()
{
	return this->timeIndex;
}

mat addMassMatrix(mat& currentMass, double rho, double a, double b, double th)
{
	int currentMassSize = currentMass.n_cols;
	currentMass = join_rows(currentMass,zeros<mat>(currentMassSize,36));

	mat massNew = zeros<mat>(36,36);
	massNew(0,0) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(0,1) = 0;
	massNew(0,2) = 0;
	massNew(0,3) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(0,4) = 0;
	massNew(0,5) = 0;
	massNew(0,6) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(0,7) = 0;
	massNew(0,8) = 0;
	massNew(0,9) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(0,10) = 0;
	massNew(0,11) = 0;
	massNew(0,12) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(0,13) = 0;
	massNew(0,14) = 0;
	massNew(0,15) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(0,16) = 0;
	massNew(0,17) = 0;
	massNew(0,18) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(0,19) = 0;
	massNew(0,20) = 0;
	massNew(0,21) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(0,22) = 0;
	massNew(0,23) = 0;
	massNew(0,24) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(0,25) = 0;
	massNew(0,26) = 0;
	massNew(0,27) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(0,28) = 0;
	massNew(0,29) = 0;
	massNew(0,30) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(0,31) = 0;
	massNew(0,32) = 0;
	massNew(0,33) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(0,34) = 0;
	massNew(0,35) = 0;
	massNew(1,0) = 0;
	massNew(1,1) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(1,2) = 0;
	massNew(1,3) = 0;
	massNew(1,4) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(1,5) = 0;
	massNew(1,6) = 0;
	massNew(1,7) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(1,8) = 0;
	massNew(1,9) = 0;
	massNew(1,10) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(1,11) = 0;
	massNew(1,12) = 0;
	massNew(1,13) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(1,14) = 0;
	massNew(1,15) = 0;
	massNew(1,16) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(1,17) = 0;
	massNew(1,18) = 0;
	massNew(1,19) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(1,20) = 0;
	massNew(1,21) = 0;
	massNew(1,22) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(1,23) = 0;
	massNew(1,24) = 0;
	massNew(1,25) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(1,26) = 0;
	massNew(1,27) = 0;
	massNew(1,28) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(1,29) = 0;
	massNew(1,30) = 0;
	massNew(1,31) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(1,32) = 0;
	massNew(1,33) = 0;
	massNew(1,34) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(1,35) = 0;
	massNew(2,0) = 0;
	massNew(2,1) = 0;
	massNew(2,2) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(2,3) = 0;
	massNew(2,4) = 0;
	massNew(2,5) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(2,6) = 0;
	massNew(2,7) = 0;
	massNew(2,8) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(2,9) = 0;
	massNew(2,10) = 0;
	massNew(2,11) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(2,12) = 0;
	massNew(2,13) = 0;
	massNew(2,14) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(2,15) = 0;
	massNew(2,16) = 0;
	massNew(2,17) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(2,18) = 0;
	massNew(2,19) = 0;
	massNew(2,20) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(2,21) = 0;
	massNew(2,22) = 0;
	massNew(2,23) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(2,24) = 0;
	massNew(2,25) = 0;
	massNew(2,26) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(2,27) = 0;
	massNew(2,28) = 0;
	massNew(2,29) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(2,30) = 0;
	massNew(2,31) = 0;
	massNew(2,32) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(2,33) = 0;
	massNew(2,34) = 0;
	massNew(2,35) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(3,0) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(3,1) = 0;
	massNew(3,2) = 0;
	massNew(3,3) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(3,4) = 0;
	massNew(3,5) = 0;
	massNew(3,6) = th * rho * b * b * a * a / 0.400e3;
	massNew(3,7) = 0;
	massNew(3,8) = 0;
	massNew(3,9) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(3,10) = 0;
	massNew(3,11) = 0;
	massNew(3,12) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(3,13) = 0;
	massNew(3,14) = 0;
	massNew(3,15) = th * rho * b * b * a * a / 0.600e3;
	massNew(3,16) = 0;
	massNew(3,17) = 0;
	massNew(3,18) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(3,19) = 0;
	massNew(3,20) = 0;
	massNew(3,21) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(3,22) = 0;
	massNew(3,23) = 0;
	massNew(3,24) = -th * rho * b * b * a * a / 0.900e3;
	massNew(3,25) = 0;
	massNew(3,26) = 0;
	massNew(3,27) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(3,28) = 0;
	massNew(3,29) = 0;
	massNew(3,30) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(3,31) = 0;
	massNew(3,32) = 0;
	massNew(3,33) = -th * rho * b * b * a * a / 0.600e3;
	massNew(3,34) = 0;
	massNew(3,35) = 0;
	massNew(4,0) = 0;
	massNew(4,1) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(4,2) = 0;
	massNew(4,3) = 0;
	massNew(4,4) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(4,5) = 0;
	massNew(4,6) = 0;
	massNew(4,7) = th * rho * b * b * a * a / 0.400e3;
	massNew(4,8) = 0;
	massNew(4,9) = 0;
	massNew(4,10) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(4,11) = 0;
	massNew(4,12) = 0;
	massNew(4,13) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(4,14) = 0;
	massNew(4,15) = 0;
	massNew(4,16) = th * rho * b * b * a * a / 0.600e3;
	massNew(4,17) = 0;
	massNew(4,18) = 0;
	massNew(4,19) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(4,20) = 0;
	massNew(4,21) = 0;
	massNew(4,22) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(4,23) = 0;
	massNew(4,24) = 0;
	massNew(4,25) = -th * rho * b * b * a * a / 0.900e3;
	massNew(4,26) = 0;
	massNew(4,27) = 0;
	massNew(4,28) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(4,29) = 0;
	massNew(4,30) = 0;
	massNew(4,31) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(4,32) = 0;
	massNew(4,33) = 0;
	massNew(4,34) = -th * rho * b * b * a * a / 0.600e3;
	massNew(4,35) = 0;
	massNew(5,0) = 0;
	massNew(5,1) = 0;
	massNew(5,2) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(5,3) = 0;
	massNew(5,4) = 0;
	massNew(5,5) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(5,6) = 0;
	massNew(5,7) = 0;
	massNew(5,8) = th * rho * b * b * a * a / 0.400e3;
	massNew(5,9) = 0;
	massNew(5,10) = 0;
	massNew(5,11) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(5,12) = 0;
	massNew(5,13) = 0;
	massNew(5,14) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(5,15) = 0;
	massNew(5,16) = 0;
	massNew(5,17) = th * rho * b * b * a * a / 0.600e3;
	massNew(5,18) = 0;
	massNew(5,19) = 0;
	massNew(5,20) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(5,21) = 0;
	massNew(5,22) = 0;
	massNew(5,23) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(5,24) = 0;
	massNew(5,25) = 0;
	massNew(5,26) = -th * rho * b * b * a * a / 0.900e3;
	massNew(5,27) = 0;
	massNew(5,28) = 0;
	massNew(5,29) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(5,30) = 0;
	massNew(5,31) = 0;
	massNew(5,32) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(5,33) = 0;
	massNew(5,34) = 0;
	massNew(5,35) = -th * rho * b * b * a * a / 0.600e3;
	massNew(6,0) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(6,1) = 0;
	massNew(6,2) = 0;
	massNew(6,3) = th * rho * b * b * a * a / 0.400e3;
	massNew(6,4) = 0;
	massNew(6,5) = 0;
	massNew(6,6) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(6,7) = 0;
	massNew(6,8) = 0;
	massNew(6,9) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(6,10) = 0;
	massNew(6,11) = 0;
	massNew(6,12) = -th * rho * b * b * a * a / 0.600e3;
	massNew(6,13) = 0;
	massNew(6,14) = 0;
	massNew(6,15) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(6,16) = 0;
	massNew(6,17) = 0;
	massNew(6,18) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(6,19) = 0;
	massNew(6,20) = 0;
	massNew(6,21) = -th * rho * b * b * a * a / 0.900e3;
	massNew(6,22) = 0;
	massNew(6,23) = 0;
	massNew(6,24) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(6,25) = 0;
	massNew(6,26) = 0;
	massNew(6,27) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(6,28) = 0;
	massNew(6,29) = 0;
	massNew(6,30) = th * rho * b * b * a * a / 0.600e3;
	massNew(6,31) = 0;
	massNew(6,32) = 0;
	massNew(6,33) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(6,34) = 0;
	massNew(6,35) = 0;
	massNew(7,0) = 0;
	massNew(7,1) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(7,2) = 0;
	massNew(7,3) = 0;
	massNew(7,4) = th * rho * b * b * a * a / 0.400e3;
	massNew(7,5) = 0;
	massNew(7,6) = 0;
	massNew(7,7) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(7,8) = 0;
	massNew(7,9) = 0;
	massNew(7,10) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(7,11) = 0;
	massNew(7,12) = 0;
	massNew(7,13) = -th * rho * b * b * a * a / 0.600e3;
	massNew(7,14) = 0;
	massNew(7,15) = 0;
	massNew(7,16) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(7,17) = 0;
	massNew(7,18) = 0;
	massNew(7,19) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(7,20) = 0;
	massNew(7,21) = 0;
	massNew(7,22) = -th * rho * b * b * a * a / 0.900e3;
	massNew(7,23) = 0;
	massNew(7,24) = 0;
	massNew(7,25) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(7,26) = 0;
	massNew(7,27) = 0;
	massNew(7,28) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(7,29) = 0;
	massNew(7,30) = 0;
	massNew(7,31) = th * rho * b * b * a * a / 0.600e3;
	massNew(7,32) = 0;
	massNew(7,33) = 0;
	massNew(7,34) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(7,35) = 0;
	massNew(8,0) = 0;
	massNew(8,1) = 0;
	massNew(8,2) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(8,3) = 0;
	massNew(8,4) = 0;
	massNew(8,5) = th * rho * b * b * a * a / 0.400e3;
	massNew(8,6) = 0;
	massNew(8,7) = 0;
	massNew(8,8) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(8,9) = 0;
	massNew(8,10) = 0;
	massNew(8,11) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(8,12) = 0;
	massNew(8,13) = 0;
	massNew(8,14) = -th * rho * b * b * a * a / 0.600e3;
	massNew(8,15) = 0;
	massNew(8,16) = 0;
	massNew(8,17) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(8,18) = 0;
	massNew(8,19) = 0;
	massNew(8,20) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(8,21) = 0;
	massNew(8,22) = 0;
	massNew(8,23) = -th * rho * b * b * a * a / 0.900e3;
	massNew(8,24) = 0;
	massNew(8,25) = 0;
	massNew(8,26) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(8,27) = 0;
	massNew(8,28) = 0;
	massNew(8,29) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(8,30) = 0;
	massNew(8,31) = 0;
	massNew(8,32) = th * rho * b * b * a * a / 0.600e3;
	massNew(8,33) = 0;
	massNew(8,34) = 0;
	massNew(8,35) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(9,0) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(9,1) = 0;
	massNew(9,2) = 0;
	massNew(9,3) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(9,4) = 0;
	massNew(9,5) = 0;
	massNew(9,6) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(9,7) = 0;
	massNew(9,8) = 0;
	massNew(9,9) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(9,10) = 0;
	massNew(9,11) = 0;
	massNew(9,12) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(9,13) = 0;
	massNew(9,14) = 0;
	massNew(9,15) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(9,16) = 0;
	massNew(9,17) = 0;
	massNew(9,18) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(9,19) = 0;
	massNew(9,20) = 0;
	massNew(9,21) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(9,22) = 0;
	massNew(9,23) = 0;
	massNew(9,24) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(9,25) = 0;
	massNew(9,26) = 0;
	massNew(9,27) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(9,28) = 0;
	massNew(9,29) = 0;
	massNew(9,30) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(9,31) = 0;
	massNew(9,32) = 0;
	massNew(9,33) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(9,34) = 0;
	massNew(9,35) = 0;
	massNew(10,0) = 0;
	massNew(10,1) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(10,2) = 0;
	massNew(10,3) = 0;
	massNew(10,4) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(10,5) = 0;
	massNew(10,6) = 0;
	massNew(10,7) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(10,8) = 0;
	massNew(10,9) = 0;
	massNew(10,10) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(10,11) = 0;
	massNew(10,12) = 0;
	massNew(10,13) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(10,14) = 0;
	massNew(10,15) = 0;
	massNew(10,16) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(10,17) = 0;
	massNew(10,18) = 0;
	massNew(10,19) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(10,20) = 0;
	massNew(10,21) = 0;
	massNew(10,22) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(10,23) = 0;
	massNew(10,24) = 0;
	massNew(10,25) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(10,26) = 0;
	massNew(10,27) = 0;
	massNew(10,28) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(10,29) = 0;
	massNew(10,30) = 0;
	massNew(10,31) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(10,32) = 0;
	massNew(10,33) = 0;
	massNew(10,34) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(10,35) = 0;
	massNew(11,0) = 0;
	massNew(11,1) = 0;
	massNew(11,2) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(11,3) = 0;
	massNew(11,4) = 0;
	massNew(11,5) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(11,6) = 0;
	massNew(11,7) = 0;
	massNew(11,8) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(11,9) = 0;
	massNew(11,10) = 0;
	massNew(11,11) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(11,12) = 0;
	massNew(11,13) = 0;
	massNew(11,14) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(11,15) = 0;
	massNew(11,16) = 0;
	massNew(11,17) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(11,18) = 0;
	massNew(11,19) = 0;
	massNew(11,20) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(11,21) = 0;
	massNew(11,22) = 0;
	massNew(11,23) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(11,24) = 0;
	massNew(11,25) = 0;
	massNew(11,26) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(11,27) = 0;
	massNew(11,28) = 0;
	massNew(11,29) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(11,30) = 0;
	massNew(11,31) = 0;
	massNew(11,32) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(11,33) = 0;
	massNew(11,34) = 0;
	massNew(11,35) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(12,0) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(12,1) = 0;
	massNew(12,2) = 0;
	massNew(12,3) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(12,4) = 0;
	massNew(12,5) = 0;
	massNew(12,6) = -th * rho * b * b * a * a / 0.600e3;
	massNew(12,7) = 0;
	massNew(12,8) = 0;
	massNew(12,9) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(12,10) = 0;
	massNew(12,11) = 0;
	massNew(12,12) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(12,13) = 0;
	massNew(12,14) = 0;
	massNew(12,15) = -th * rho * b * b * a * a / 0.400e3;
	massNew(12,16) = 0;
	massNew(12,17) = 0;
	massNew(12,18) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(12,19) = 0;
	massNew(12,20) = 0;
	massNew(12,21) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(12,22) = 0;
	massNew(12,23) = 0;
	massNew(12,24) = th * rho * b * b * a * a / 0.600e3;
	massNew(12,25) = 0;
	massNew(12,26) = 0;
	massNew(12,27) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(12,28) = 0;
	massNew(12,29) = 0;
	massNew(12,30) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(12,31) = 0;
	massNew(12,32) = 0;
	massNew(12,33) = th * rho * b * b * a * a / 0.900e3;
	massNew(12,34) = 0;
	massNew(12,35) = 0;
	massNew(13,0) = 0;
	massNew(13,1) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(13,2) = 0;
	massNew(13,3) = 0;
	massNew(13,4) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(13,5) = 0;
	massNew(13,6) = 0;
	massNew(13,7) = -th * rho * b * b * a * a / 0.600e3;
	massNew(13,8) = 0;
	massNew(13,9) = 0;
	massNew(13,10) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(13,11) = 0;
	massNew(13,12) = 0;
	massNew(13,13) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(13,14) = 0;
	massNew(13,15) = 0;
	massNew(13,16) = -th * rho * b * b * a * a / 0.400e3;
	massNew(13,17) = 0;
	massNew(13,18) = 0;
	massNew(13,19) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(13,20) = 0;
	massNew(13,21) = 0;
	massNew(13,22) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(13,23) = 0;
	massNew(13,24) = 0;
	massNew(13,25) = th * rho * b * b * a * a / 0.600e3;
	massNew(13,26) = 0;
	massNew(13,27) = 0;
	massNew(13,28) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(13,29) = 0;
	massNew(13,30) = 0;
	massNew(13,31) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(13,32) = 0;
	massNew(13,33) = 0;
	massNew(13,34) = th * rho * b * b * a * a / 0.900e3;
	massNew(13,35) = 0;
	massNew(14,0) = 0;
	massNew(14,1) = 0;
	massNew(14,2) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(14,3) = 0;
	massNew(14,4) = 0;
	massNew(14,5) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(14,6) = 0;
	massNew(14,7) = 0;
	massNew(14,8) = -th * rho * b * b * a * a / 0.600e3;
	massNew(14,9) = 0;
	massNew(14,10) = 0;
	massNew(14,11) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(14,12) = 0;
	massNew(14,13) = 0;
	massNew(14,14) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(14,15) = 0;
	massNew(14,16) = 0;
	massNew(14,17) = -th * rho * b * b * a * a / 0.400e3;
	massNew(14,18) = 0;
	massNew(14,19) = 0;
	massNew(14,20) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(14,21) = 0;
	massNew(14,22) = 0;
	massNew(14,23) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(14,24) = 0;
	massNew(14,25) = 0;
	massNew(14,26) = th * rho * b * b * a * a / 0.600e3;
	massNew(14,27) = 0;
	massNew(14,28) = 0;
	massNew(14,29) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(14,30) = 0;
	massNew(14,31) = 0;
	massNew(14,32) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(14,33) = 0;
	massNew(14,34) = 0;
	massNew(14,35) = th * rho * b * b * a * a / 0.900e3;
	massNew(15,0) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(15,1) = 0;
	massNew(15,2) = 0;
	massNew(15,3) = th * rho * b * b * a * a / 0.600e3;
	massNew(15,4) = 0;
	massNew(15,5) = 0;
	massNew(15,6) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(15,7) = 0;
	massNew(15,8) = 0;
	massNew(15,9) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(15,10) = 0;
	massNew(15,11) = 0;
	massNew(15,12) = -th * rho * b * b * a * a / 0.400e3;
	massNew(15,13) = 0;
	massNew(15,14) = 0;
	massNew(15,15) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(15,16) = 0;
	massNew(15,17) = 0;
	massNew(15,18) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(15,19) = 0;
	massNew(15,20) = 0;
	massNew(15,21) = -th * rho * b * b * a * a / 0.600e3;
	massNew(15,22) = 0;
	massNew(15,23) = 0;
	massNew(15,24) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(15,25) = 0;
	massNew(15,26) = 0;
	massNew(15,27) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(15,28) = 0;
	massNew(15,29) = 0;
	massNew(15,30) = th * rho * b * b * a * a / 0.900e3;
	massNew(15,31) = 0;
	massNew(15,32) = 0;
	massNew(15,33) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(15,34) = 0;
	massNew(15,35) = 0;
	massNew(16,0) = 0;
	massNew(16,1) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(16,2) = 0;
	massNew(16,3) = 0;
	massNew(16,4) = th * rho * b * b * a * a / 0.600e3;
	massNew(16,5) = 0;
	massNew(16,6) = 0;
	massNew(16,7) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(16,8) = 0;
	massNew(16,9) = 0;
	massNew(16,10) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(16,11) = 0;
	massNew(16,12) = 0;
	massNew(16,13) = -th * rho * b * b * a * a / 0.400e3;
	massNew(16,14) = 0;
	massNew(16,15) = 0;
	massNew(16,16) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(16,17) = 0;
	massNew(16,18) = 0;
	massNew(16,19) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(16,20) = 0;
	massNew(16,21) = 0;
	massNew(16,22) = -th * rho * b * b * a * a / 0.600e3;
	massNew(16,23) = 0;
	massNew(16,24) = 0;
	massNew(16,25) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(16,26) = 0;
	massNew(16,27) = 0;
	massNew(16,28) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(16,29) = 0;
	massNew(16,30) = 0;
	massNew(16,31) = th * rho * b * b * a * a / 0.900e3;
	massNew(16,32) = 0;
	massNew(16,33) = 0;
	massNew(16,34) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(16,35) = 0;
	massNew(17,0) = 0;
	massNew(17,1) = 0;
	massNew(17,2) = 0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(17,3) = 0;
	massNew(17,4) = 0;
	massNew(17,5) = th * rho * b * b * a * a / 0.600e3;
	massNew(17,6) = 0;
	massNew(17,7) = 0;
	massNew(17,8) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(17,9) = 0;
	massNew(17,10) = 0;
	massNew(17,11) = 0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(17,12) = 0;
	massNew(17,13) = 0;
	massNew(17,14) = -th * rho * b * b * a * a / 0.400e3;
	massNew(17,15) = 0;
	massNew(17,16) = 0;
	massNew(17,17) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(17,18) = 0;
	massNew(17,19) = 0;
	massNew(17,20) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(17,21) = 0;
	massNew(17,22) = 0;
	massNew(17,23) = -th * rho * b * b * a * a / 0.600e3;
	massNew(17,24) = 0;
	massNew(17,25) = 0;
	massNew(17,26) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(17,27) = 0;
	massNew(17,28) = 0;
	massNew(17,29) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(17,30) = 0;
	massNew(17,31) = 0;
	massNew(17,32) = th * rho * b * b * a * a / 0.900e3;
	massNew(17,33) = 0;
	massNew(17,34) = 0;
	massNew(17,35) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(18,0) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(18,1) = 0;
	massNew(18,2) = 0;
	massNew(18,3) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(18,4) = 0;
	massNew(18,5) = 0;
	massNew(18,6) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(18,7) = 0;
	massNew(18,8) = 0;
	massNew(18,9) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(18,10) = 0;
	massNew(18,11) = 0;
	massNew(18,12) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(18,13) = 0;
	massNew(18,14) = 0;
	massNew(18,15) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(18,16) = 0;
	massNew(18,17) = 0;
	massNew(18,18) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(18,19) = 0;
	massNew(18,20) = 0;
	massNew(18,21) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(18,22) = 0;
	massNew(18,23) = 0;
	massNew(18,24) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(18,25) = 0;
	massNew(18,26) = 0;
	massNew(18,27) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(18,28) = 0;
	massNew(18,29) = 0;
	massNew(18,30) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(18,31) = 0;
	massNew(18,32) = 0;
	massNew(18,33) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(18,34) = 0;
	massNew(18,35) = 0;
	massNew(19,0) = 0;
	massNew(19,1) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(19,2) = 0;
	massNew(19,3) = 0;
	massNew(19,4) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(19,5) = 0;
	massNew(19,6) = 0;
	massNew(19,7) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(19,8) = 0;
	massNew(19,9) = 0;
	massNew(19,10) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(19,11) = 0;
	massNew(19,12) = 0;
	massNew(19,13) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(19,14) = 0;
	massNew(19,15) = 0;
	massNew(19,16) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(19,17) = 0;
	massNew(19,18) = 0;
	massNew(19,19) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(19,20) = 0;
	massNew(19,21) = 0;
	massNew(19,22) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(19,23) = 0;
	massNew(19,24) = 0;
	massNew(19,25) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(19,26) = 0;
	massNew(19,27) = 0;
	massNew(19,28) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(19,29) = 0;
	massNew(19,30) = 0;
	massNew(19,31) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(19,32) = 0;
	massNew(19,33) = 0;
	massNew(19,34) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(19,35) = 0;
	massNew(20,0) = 0;
	massNew(20,1) = 0;
	massNew(20,2) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(20,3) = 0;
	massNew(20,4) = 0;
	massNew(20,5) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(20,6) = 0;
	massNew(20,7) = 0;
	massNew(20,8) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(20,9) = 0;
	massNew(20,10) = 0;
	massNew(20,11) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(20,12) = 0;
	massNew(20,13) = 0;
	massNew(20,14) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(20,15) = 0;
	massNew(20,16) = 0;
	massNew(20,17) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(20,18) = 0;
	massNew(20,19) = 0;
	massNew(20,20) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(20,21) = 0;
	massNew(20,22) = 0;
	massNew(20,23) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(20,24) = 0;
	massNew(20,25) = 0;
	massNew(20,26) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(20,27) = 0;
	massNew(20,28) = 0;
	massNew(20,29) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(20,30) = 0;
	massNew(20,31) = 0;
	massNew(20,32) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(20,33) = 0;
	massNew(20,34) = 0;
	massNew(20,35) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(21,0) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(21,1) = 0;
	massNew(21,2) = 0;
	massNew(21,3) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(21,4) = 0;
	massNew(21,5) = 0;
	massNew(21,6) = -th * rho * b * b * a * a / 0.900e3;
	massNew(21,7) = 0;
	massNew(21,8) = 0;
	massNew(21,9) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(21,10) = 0;
	massNew(21,11) = 0;
	massNew(21,12) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(21,13) = 0;
	massNew(21,14) = 0;
	massNew(21,15) = -th * rho * b * b * a * a / 0.600e3;
	massNew(21,16) = 0;
	massNew(21,17) = 0;
	massNew(21,18) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(21,19) = 0;
	massNew(21,20) = 0;
	massNew(21,21) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(21,22) = 0;
	massNew(21,23) = 0;
	massNew(21,24) = th * rho * b * b * a * a / 0.400e3;
	massNew(21,25) = 0;
	massNew(21,26) = 0;
	massNew(21,27) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(21,28) = 0;
	massNew(21,29) = 0;
	massNew(21,30) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(21,31) = 0;
	massNew(21,32) = 0;
	massNew(21,33) = th * rho * b * b * a * a / 0.600e3;
	massNew(21,34) = 0;
	massNew(21,35) = 0;
	massNew(22,0) = 0;
	massNew(22,1) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(22,2) = 0;
	massNew(22,3) = 0;
	massNew(22,4) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(22,5) = 0;
	massNew(22,6) = 0;
	massNew(22,7) = -th * rho * b * b * a * a / 0.900e3;
	massNew(22,8) = 0;
	massNew(22,9) = 0;
	massNew(22,10) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(22,11) = 0;
	massNew(22,12) = 0;
	massNew(22,13) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(22,14) = 0;
	massNew(22,15) = 0;
	massNew(22,16) = -th * rho * b * b * a * a / 0.600e3;
	massNew(22,17) = 0;
	massNew(22,18) = 0;
	massNew(22,19) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(22,20) = 0;
	massNew(22,21) = 0;
	massNew(22,22) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(22,23) = 0;
	massNew(22,24) = 0;
	massNew(22,25) = th * rho * b * b * a * a / 0.400e3;
	massNew(22,26) = 0;
	massNew(22,27) = 0;
	massNew(22,28) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(22,29) = 0;
	massNew(22,30) = 0;
	massNew(22,31) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(22,32) = 0;
	massNew(22,33) = 0;
	massNew(22,34) = th * rho * b * b * a * a / 0.600e3;
	massNew(22,35) = 0;
	massNew(23,0) = 0;
	massNew(23,1) = 0;
	massNew(23,2) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(23,3) = 0;
	massNew(23,4) = 0;
	massNew(23,5) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(23,6) = 0;
	massNew(23,7) = 0;
	massNew(23,8) = -th * rho * b * b * a * a / 0.900e3;
	massNew(23,9) = 0;
	massNew(23,10) = 0;
	massNew(23,11) = -0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(23,12) = 0;
	massNew(23,13) = 0;
	massNew(23,14) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(23,15) = 0;
	massNew(23,16) = 0;
	massNew(23,17) = -th * rho * b * b * a * a / 0.600e3;
	massNew(23,18) = 0;
	massNew(23,19) = 0;
	massNew(23,20) = -0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(23,21) = 0;
	massNew(23,22) = 0;
	massNew(23,23) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(23,24) = 0;
	massNew(23,25) = 0;
	massNew(23,26) = th * rho * b * b * a * a / 0.400e3;
	massNew(23,27) = 0;
	massNew(23,28) = 0;
	massNew(23,29) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(23,30) = 0;
	massNew(23,31) = 0;
	massNew(23,32) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(23,33) = 0;
	massNew(23,34) = 0;
	massNew(23,35) = th * rho * b * b * a * a / 0.600e3;
	massNew(24,0) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(24,1) = 0;
	massNew(24,2) = 0;
	massNew(24,3) = -th * rho * b * b * a * a / 0.900e3;
	massNew(24,4) = 0;
	massNew(24,5) = 0;
	massNew(24,6) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(24,7) = 0;
	massNew(24,8) = 0;
	massNew(24,9) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(24,10) = 0;
	massNew(24,11) = 0;
	massNew(24,12) = th * rho * b * b * a * a / 0.600e3;
	massNew(24,13) = 0;
	massNew(24,14) = 0;
	massNew(24,15) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(24,16) = 0;
	massNew(24,17) = 0;
	massNew(24,18) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(24,19) = 0;
	massNew(24,20) = 0;
	massNew(24,21) = th * rho * b * b * a * a / 0.400e3;
	massNew(24,22) = 0;
	massNew(24,23) = 0;
	massNew(24,24) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(24,25) = 0;
	massNew(24,26) = 0;
	massNew(24,27) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(24,28) = 0;
	massNew(24,29) = 0;
	massNew(24,30) = -th * rho * b * b * a * a / 0.600e3;
	massNew(24,31) = 0;
	massNew(24,32) = 0;
	massNew(24,33) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(24,34) = 0;
	massNew(24,35) = 0;
	massNew(25,0) = 0;
	massNew(25,1) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(25,2) = 0;
	massNew(25,3) = 0;
	massNew(25,4) = -th * rho * b * b * a * a / 0.900e3;
	massNew(25,5) = 0;
	massNew(25,6) = 0;
	massNew(25,7) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(25,8) = 0;
	massNew(25,9) = 0;
	massNew(25,10) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(25,11) = 0;
	massNew(25,12) = 0;
	massNew(25,13) = th * rho * b * b * a * a / 0.600e3;
	massNew(25,14) = 0;
	massNew(25,15) = 0;
	massNew(25,16) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(25,17) = 0;
	massNew(25,18) = 0;
	massNew(25,19) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(25,20) = 0;
	massNew(25,21) = 0;
	massNew(25,22) = th * rho * b * b * a * a / 0.400e3;
	massNew(25,23) = 0;
	massNew(25,24) = 0;
	massNew(25,25) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(25,26) = 0;
	massNew(25,27) = 0;
	massNew(25,28) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(25,29) = 0;
	massNew(25,30) = 0;
	massNew(25,31) = -th * rho * b * b * a * a / 0.600e3;
	massNew(25,32) = 0;
	massNew(25,33) = 0;
	massNew(25,34) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(25,35) = 0;
	massNew(26,0) = 0;
	massNew(26,1) = 0;
	massNew(26,2) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(26,3) = 0;
	massNew(26,4) = 0;
	massNew(26,5) = -th * rho * b * b * a * a / 0.900e3;
	massNew(26,6) = 0;
	massNew(26,7) = 0;
	massNew(26,8) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(26,9) = 0;
	massNew(26,10) = 0;
	massNew(26,11) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(26,12) = 0;
	massNew(26,13) = 0;
	massNew(26,14) = th * rho * b * b * a * a / 0.600e3;
	massNew(26,15) = 0;
	massNew(26,16) = 0;
	massNew(26,17) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(26,18) = 0;
	massNew(26,19) = 0;
	massNew(26,20) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(26,21) = 0;
	massNew(26,22) = 0;
	massNew(26,23) = th * rho * b * b * a * a / 0.400e3;
	massNew(26,24) = 0;
	massNew(26,25) = 0;
	massNew(26,26) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(26,27) = 0;
	massNew(26,28) = 0;
	massNew(26,29) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(26,30) = 0;
	massNew(26,31) = 0;
	massNew(26,32) = -th * rho * b * b * a * a / 0.600e3;
	massNew(26,33) = 0;
	massNew(26,34) = 0;
	massNew(26,35) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(27,0) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(27,1) = 0;
	massNew(27,2) = 0;
	massNew(27,3) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(27,4) = 0;
	massNew(27,5) = 0;
	massNew(27,6) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(27,7) = 0;
	massNew(27,8) = 0;
	massNew(27,9) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(27,10) = 0;
	massNew(27,11) = 0;
	massNew(27,12) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(27,13) = 0;
	massNew(27,14) = 0;
	massNew(27,15) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(27,16) = 0;
	massNew(27,17) = 0;
	massNew(27,18) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(27,19) = 0;
	massNew(27,20) = 0;
	massNew(27,21) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(27,22) = 0;
	massNew(27,23) = 0;
	massNew(27,24) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(27,25) = 0;
	massNew(27,26) = 0;
	massNew(27,27) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(27,28) = 0;
	massNew(27,29) = 0;
	massNew(27,30) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(27,31) = 0;
	massNew(27,32) = 0;
	massNew(27,33) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(27,34) = 0;
	massNew(27,35) = 0;
	massNew(28,0) = 0;
	massNew(28,1) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(28,2) = 0;
	massNew(28,3) = 0;
	massNew(28,4) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(28,5) = 0;
	massNew(28,6) = 0;
	massNew(28,7) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(28,8) = 0;
	massNew(28,9) = 0;
	massNew(28,10) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(28,11) = 0;
	massNew(28,12) = 0;
	massNew(28,13) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(28,14) = 0;
	massNew(28,15) = 0;
	massNew(28,16) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(28,17) = 0;
	massNew(28,18) = 0;
	massNew(28,19) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(28,20) = 0;
	massNew(28,21) = 0;
	massNew(28,22) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(28,23) = 0;
	massNew(28,24) = 0;
	massNew(28,25) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(28,26) = 0;
	massNew(28,27) = 0;
	massNew(28,28) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(28,29) = 0;
	massNew(28,30) = 0;
	massNew(28,31) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(28,32) = 0;
	massNew(28,33) = 0;
	massNew(28,34) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(28,35) = 0;
	massNew(29,0) = 0;
	massNew(29,1) = 0;
	massNew(29,2) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(29,3) = 0;
	massNew(29,4) = 0;
	massNew(29,5) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(29,6) = 0;
	massNew(29,7) = 0;
	massNew(29,8) = 0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(29,9) = 0;
	massNew(29,10) = 0;
	massNew(29,11) = 0.197e3 / 0.12600e5 * th * rho * b * a;
	massNew(29,12) = 0;
	massNew(29,13) = 0;
	massNew(29,14) = -0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(29,15) = 0;
	massNew(29,16) = 0;
	massNew(29,17) = 0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(29,18) = 0;
	massNew(29,19) = 0;
	massNew(29,20) = 0.613e3 / 0.12600e5 * th * rho * b * a;
	massNew(29,21) = 0;
	massNew(29,22) = 0;
	massNew(29,23) = -0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(29,24) = 0;
	massNew(29,25) = 0;
	massNew(29,26) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(29,27) = 0;
	massNew(29,28) = 0;
	massNew(29,29) = 0.1727e4 / 0.12600e5 * th * rho * b * a;
	massNew(29,30) = 0;
	massNew(29,31) = 0;
	massNew(29,32) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(29,33) = 0;
	massNew(29,34) = 0;
	massNew(29,35) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(30,0) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(30,1) = 0;
	massNew(30,2) = 0;
	massNew(30,3) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(30,4) = 0;
	massNew(30,5) = 0;
	massNew(30,6) = th * rho * b * b * a * a / 0.600e3;
	massNew(30,7) = 0;
	massNew(30,8) = 0;
	massNew(30,9) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(30,10) = 0;
	massNew(30,11) = 0;
	massNew(30,12) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(30,13) = 0;
	massNew(30,14) = 0;
	massNew(30,15) = th * rho * b * b * a * a / 0.900e3;
	massNew(30,16) = 0;
	massNew(30,17) = 0;
	massNew(30,18) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(30,19) = 0;
	massNew(30,20) = 0;
	massNew(30,21) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(30,22) = 0;
	massNew(30,23) = 0;
	massNew(30,24) = -th * rho * b * b * a * a / 0.600e3;
	massNew(30,25) = 0;
	massNew(30,26) = 0;
	massNew(30,27) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(30,28) = 0;
	massNew(30,29) = 0;
	massNew(30,30) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(30,31) = 0;
	massNew(30,32) = 0;
	massNew(30,33) = -th * rho * b * b * a * a / 0.400e3;
	massNew(30,34) = 0;
	massNew(30,35) = 0;
	massNew(31,0) = 0;
	massNew(31,1) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(31,2) = 0;
	massNew(31,3) = 0;
	massNew(31,4) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(31,5) = 0;
	massNew(31,6) = 0;
	massNew(31,7) = th * rho * b * b * a * a / 0.600e3;
	massNew(31,8) = 0;
	massNew(31,9) = 0;
	massNew(31,10) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(31,11) = 0;
	massNew(31,12) = 0;
	massNew(31,13) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(31,14) = 0;
	massNew(31,15) = 0;
	massNew(31,16) = th * rho * b * b * a * a / 0.900e3;
	massNew(31,17) = 0;
	massNew(31,18) = 0;
	massNew(31,19) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(31,20) = 0;
	massNew(31,21) = 0;
	massNew(31,22) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(31,23) = 0;
	massNew(31,24) = 0;
	massNew(31,25) = -th * rho * b * b * a * a / 0.600e3;
	massNew(31,26) = 0;
	massNew(31,27) = 0;
	massNew(31,28) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(31,29) = 0;
	massNew(31,30) = 0;
	massNew(31,31) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(31,32) = 0;
	massNew(31,33) = 0;
	massNew(31,34) = -th * rho * b * b * a * a / 0.400e3;
	massNew(31,35) = 0;
	massNew(32,0) = 0;
	massNew(32,1) = 0;
	massNew(32,2) = 0.199e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(32,3) = 0;
	massNew(32,4) = 0;
	massNew(32,5) = th * rho * b * pow(a, 0.3e1) / 0.630e3;
	massNew(32,6) = 0;
	massNew(32,7) = 0;
	massNew(32,8) = th * rho * b * b * a * a / 0.600e3;
	massNew(32,9) = 0;
	massNew(32,10) = 0;
	massNew(32,11) = 0.29e2 / 0.6300e4 * th * rho * b * a * a;
	massNew(32,12) = 0;
	massNew(32,13) = 0;
	massNew(32,14) = -th * rho * b * pow(a, 0.3e1) / 0.840e3;
	massNew(32,15) = 0;
	massNew(32,16) = 0;
	massNew(32,17) = th * rho * b * b * a * a / 0.900e3;
	massNew(32,18) = 0;
	massNew(32,19) = 0;
	massNew(32,20) = 0.137e3 / 0.12600e5 * th * rho * b * a * a;
	massNew(32,21) = 0;
	massNew(32,22) = 0;
	massNew(32,23) = -th * rho * b * pow(a, 0.3e1) / 0.420e3;
	massNew(32,24) = 0;
	massNew(32,25) = 0;
	massNew(32,26) = -th * rho * b * b * a * a / 0.600e3;
	massNew(32,27) = 0;
	massNew(32,28) = 0;
	massNew(32,29) = 0.461e3 / 0.25200e5 * th * rho * b * a * a;
	massNew(32,30) = 0;
	massNew(32,31) = 0;
	massNew(32,32) = th * rho * b * pow(a, 0.3e1) / 0.315e3;
	massNew(32,33) = 0;
	massNew(32,34) = 0;
	massNew(32,35) = -th * rho * b * b * a * a / 0.400e3;
	massNew(33,0) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(33,1) = 0;
	massNew(33,2) = 0;
	massNew(33,3) = -th * rho * b * b * a * a / 0.600e3;
	massNew(33,4) = 0;
	massNew(33,5) = 0;
	massNew(33,6) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(33,7) = 0;
	massNew(33,8) = 0;
	massNew(33,9) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(33,10) = 0;
	massNew(33,11) = 0;
	massNew(33,12) = th * rho * b * b * a * a / 0.900e3;
	massNew(33,13) = 0;
	massNew(33,14) = 0;
	massNew(33,15) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(33,16) = 0;
	massNew(33,17) = 0;
	massNew(33,18) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(33,19) = 0;
	massNew(33,20) = 0;
	massNew(33,21) = th * rho * b * b * a * a / 0.600e3;
	massNew(33,22) = 0;
	massNew(33,23) = 0;
	massNew(33,24) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(33,25) = 0;
	massNew(33,26) = 0;
	massNew(33,27) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(33,28) = 0;
	massNew(33,29) = 0;
	massNew(33,30) = -th * rho * b * b * a * a / 0.400e3;
	massNew(33,31) = 0;
	massNew(33,32) = 0;
	massNew(33,33) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(33,34) = 0;
	massNew(33,35) = 0;
	massNew(34,0) = 0;
	massNew(34,1) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(34,2) = 0;
	massNew(34,3) = 0;
	massNew(34,4) = -th * rho * b * b * a * a / 0.600e3;
	massNew(34,5) = 0;
	massNew(34,6) = 0;
	massNew(34,7) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(34,8) = 0;
	massNew(34,9) = 0;
	massNew(34,10) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(34,11) = 0;
	massNew(34,12) = 0;
	massNew(34,13) = th * rho * b * b * a * a / 0.900e3;
	massNew(34,14) = 0;
	massNew(34,15) = 0;
	massNew(34,16) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(34,17) = 0;
	massNew(34,18) = 0;
	massNew(34,19) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(34,20) = 0;
	massNew(34,21) = 0;
	massNew(34,22) = th * rho * b * b * a * a / 0.600e3;
	massNew(34,23) = 0;
	massNew(34,24) = 0;
	massNew(34,25) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(34,26) = 0;
	massNew(34,27) = 0;
	massNew(34,28) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(34,29) = 0;
	massNew(34,30) = 0;
	massNew(34,31) = -th * rho * b * b * a * a / 0.400e3;
	massNew(34,32) = 0;
	massNew(34,33) = 0;
	massNew(34,34) = th * rho * pow(b, 0.3e1) * a / 0.315e3;
	massNew(34,35) = 0;
	massNew(35,0) = 0;
	massNew(35,1) = 0;
	massNew(35,2) = -0.137e3 / 0.12600e5 * th * rho * b * b * a;
	massNew(35,3) = 0;
	massNew(35,4) = 0;
	massNew(35,5) = -th * rho * b * b * a * a / 0.600e3;
	massNew(35,6) = 0;
	massNew(35,7) = 0;
	massNew(35,8) = -th * rho * pow(b, 0.3e1) * a / 0.420e3;
	massNew(35,9) = 0;
	massNew(35,10) = 0;
	massNew(35,11) = -0.29e2 / 0.6300e4 * th * rho * b * b * a;
	massNew(35,12) = 0;
	massNew(35,13) = 0;
	massNew(35,14) = th * rho * b * b * a * a / 0.900e3;
	massNew(35,15) = 0;
	massNew(35,16) = 0;
	massNew(35,17) = -th * rho * pow(b, 0.3e1) * a / 0.840e3;
	massNew(35,18) = 0;
	massNew(35,19) = 0;
	massNew(35,20) = -0.199e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(35,21) = 0;
	massNew(35,22) = 0;
	massNew(35,23) = th * rho * b * b * a * a / 0.600e3;
	massNew(35,24) = 0;
	massNew(35,25) = 0;
	massNew(35,26) = th * rho * pow(b, 0.3e1) * a / 0.630e3;
	massNew(35,27) = 0;
	massNew(35,28) = 0;
	massNew(35,29) = -0.461e3 / 0.25200e5 * th * rho * b * b * a;
	massNew(35,30) = 0;
	massNew(35,31) = 0;
	massNew(35,32) = -th * rho * b * b * a * a / 0.400e3;
	massNew(35,33) = 0;
	massNew(35,34) = 0;
	massNew(35,35) = th * rho * pow(b, 0.3e1) * a / 0.315e3;

	massNew = join_rows(zeros<mat>(36,currentMassSize),massNew);
	massNew = join_cols(currentMass,massNew);

	return massNew;
}
int ANCFSystem::addElement(Element& element)
{
	//add the element
	element.setElementIndex(elements.size());
	this->elements.push_back(element);

	Material material;
	material.E = element.getElasticModulus();
	material.b = element.getLength_b();
	material.l = element.getLength_l();
	material.nu = element.getNu();
	material.rho = element.getDensity();
	material.th = element.getThickness();
	this->materials.push_back(material);

	mat Pnew = zeros(36,1);
	Node node = element.getNode0();
	Pnew(0,0) = node.x;
	Pnew(1,0) = node.y;
	Pnew(2,0) = node.z;
	Pnew(3,0) = node.dx1;
	Pnew(4,0) = node.dy1;
	Pnew(5,0) = node.dz1;
	Pnew(6,0) = node.dx2;
	Pnew(7,0) = node.dy2;
	Pnew(8,0) = node.dz2;
	node = element.getNode1();
	Pnew(9,0) = node.x;
	Pnew(10,0) = node.y;
	Pnew(11,0) = node.z;
	Pnew(12,0) = node.dx1;
	Pnew(13,0) = node.dy1;
	Pnew(14,0) = node.dz1;
	Pnew(15,0) = node.dx2;
	Pnew(16,0) = node.dy2;
	Pnew(17,0) = node.dz2;
	node = element.getNode2();
	Pnew(18,0) = node.x;
	Pnew(19,0) = node.y;
	Pnew(20,0) = node.z;
	Pnew(21,0) = node.dx1;
	Pnew(22,0) = node.dy1;
	Pnew(23,0) = node.dz1;
	Pnew(24,0) = node.dx2;
	Pnew(25,0) = node.dy2;
	Pnew(26,0) = node.dz2;
	node = element.getNode3();
	Pnew(27,0) = node.x;
	Pnew(28,0) = node.y;
	Pnew(29,0) = node.z;
	Pnew(30,0) = node.dx1;
	Pnew(31,0) = node.dy1;
	Pnew(32,0) = node.dz1;
	Pnew(33,0) = node.dx2;
	Pnew(34,0) = node.dy2;
	Pnew(35,0) = node.dz2;

	this->p = join_cols(this->p,Pnew);
	this->v = join_cols(this->v,zeros<mat>(36,1));
	this->a = join_cols(this->a,zeros<mat>(36,1));
	this->fint = join_cols(this->fint,zeros<mat>(36,1));
	this->fcon = join_cols(this->fcon,zeros<mat>(36,1));
	this->fapp = join_cols(this->fapp,zeros<mat>(36,1));
	this->curvat0 = join_rows(this->curvat0,zeros<mat>(3,25));
	this->strain0 = join_rows(this->strain0,zeros<mat>(3,36));
	for(int i=0;i<36;i++)
	{
		strainDerivative.push_back(make_double3(0,0,0));
		curvatureDerivative.push_back(make_double3(0,0,0));
	}

	//update other vectors (no initial velocity or acceleration)
	double th = element.getThickness();
	double a = element.getLength_l();
	double b = element.getLength_b();
	double rho = element.getDensity();
		
	//update external force vector (gravity)
	mat fextNew = zeros(36,1);
	fextNew(0,0) = th * rho * b * a * GRAVITYx / 0.4e1;
	fextNew(1,0) = th * rho * b * a * GRAVITYy / 0.4e1;
	fextNew(2,0) = th * rho * b * a * GRAVITYz / 0.4e1;
	fextNew(3,0) = th * rho * b * a * a * GRAVITYx / 0.24e2;
	fextNew(4,0) = th * rho * b * a * a * GRAVITYy / 0.24e2;
	fextNew(5,0) = th * rho * b * a * a * GRAVITYz / 0.24e2;
	fextNew(6,0) = th * rho * b * b * a * GRAVITYx / 0.24e2;
	fextNew(7,0) = th * rho * b * b * a * GRAVITYy / 0.24e2;
	fextNew(8,0) = th * rho * b * b * a * GRAVITYz / 0.24e2;
	fextNew(9,0) = th * rho * b * a * GRAVITYx / 0.4e1;
	fextNew(10,0) = th * rho * b * a * GRAVITYy / 0.4e1;
	fextNew(11,0) = th * rho * b * a * GRAVITYz / 0.4e1;
	fextNew(12,0) = -th * rho * b * a * a * GRAVITYx / 0.24e2;
	fextNew(13,0) = -th * rho * b * a * a * GRAVITYy / 0.24e2;
	fextNew(14,0) = -th * rho * b * a * a * GRAVITYz / 0.24e2;
	fextNew(15,0) = th * rho * b * b * a * GRAVITYx / 0.24e2;
	fextNew(16,0) = th * rho * b * b * a * GRAVITYy / 0.24e2;
	fextNew(17,0) = th * rho * b * b * a * GRAVITYz / 0.24e2;
	fextNew(18,0) = th * rho * b * a * GRAVITYx / 0.4e1;
	fextNew(19,0) = th * rho * b * a * GRAVITYy / 0.4e1;
	fextNew(20,0) = th * rho * b * a * GRAVITYz / 0.4e1;
	fextNew(21,0) = -th * rho * b * a * a * GRAVITYx / 0.24e2;
	fextNew(22,0) = -th * rho * b * a * a * GRAVITYy / 0.24e2;
	fextNew(23,0) = -th * rho * b * a * a * GRAVITYz / 0.24e2;
	fextNew(24,0) = -th * rho * b * b * a * GRAVITYx / 0.24e2;
	fextNew(25,0) = -th * rho * b * b * a * GRAVITYy / 0.24e2;
	fextNew(26,0) = -th * rho * b * b * a * GRAVITYz / 0.24e2;
	fextNew(27,0) = th * rho * b * a * GRAVITYx / 0.4e1;
	fextNew(28,0) = th * rho * b * a * GRAVITYy / 0.4e1;
	fextNew(29,0) = th * rho * b * a * GRAVITYz / 0.4e1;
	fextNew(30,0) = th * rho * b * a * a * GRAVITYx / 0.24e2;
	fextNew(31,0) = th * rho * b * a * a * GRAVITYy / 0.24e2;
	fextNew(32,0) = th * rho * b * a * a * GRAVITYz / 0.24e2;
	fextNew(33,0) = -th * rho * b * b * a * GRAVITYx / 0.24e2;
	fextNew(34,0) = -th * rho * b * b * a * GRAVITYy / 0.24e2;
	fextNew(35,0) = -th * rho * b * b * a * GRAVITYz / 0.24e2;
	this->fext = join_cols(this->fext,fextNew);
	
	//add mass matrix
	this->mass = addMassMatrix(this->mass,rho,a,b,th);
	
	return elements.size();
}

int ANCFSystem::addConstraint_AbsoluteX(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEX);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteY(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEY);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteZ(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEZ);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDX1(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEDX1);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDX2(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEDX2);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDY1(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEDY1);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDY2(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEDY2);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDZ1(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEDZ1);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDZ2(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEDZ2);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeX(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEX);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeY(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEY);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeZ(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEZ);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeDX1(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDX1);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeDX2(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDX2);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeDY1(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDY1);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeDY2(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDY2);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeDZ1(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDZ1);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_RelativeDZ2(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDZ2);
	ANCFSystem::constraints.push_back(constraint);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteFixed(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEX);
	ANCFSystem::constraints.push_back(constraint);
	Constraint constraint2(nodeNum,CONSTRAINTABSOLUTEY);
	ANCFSystem::constraints.push_back(constraint2);
	Constraint constraint3(nodeNum,CONSTRAINTABSOLUTEZ);
	ANCFSystem::constraints.push_back(constraint3);

	Constraint constraint4(nodeNum,CONSTRAINTABSOLUTEDX1);
	ANCFSystem::constraints.push_back(constraint4);
	Constraint constraint5(nodeNum,CONSTRAINTABSOLUTEDY1);
	ANCFSystem::constraints.push_back(constraint5);
	Constraint constraint6(nodeNum,CONSTRAINTABSOLUTEDZ1);
	ANCFSystem::constraints.push_back(constraint6);

	Constraint constraint7(nodeNum,CONSTRAINTABSOLUTEDX2);
	ANCFSystem::constraints.push_back(constraint7);
	Constraint constraint8(nodeNum,CONSTRAINTABSOLUTEDY2);
	ANCFSystem::constraints.push_back(constraint8);
	Constraint constraint9(nodeNum,CONSTRAINTABSOLUTEDZ2);
	ANCFSystem::constraints.push_back(constraint9);

	return 0;
}

int ANCFSystem::addConstraint_RelativeFixed(int nodeNum1,int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEX);
	ANCFSystem::constraints.push_back(constraint);
	Constraint constraint2(nodeNum1,nodeNum2,CONSTRAINTRELATIVEY);
	ANCFSystem::constraints.push_back(constraint2);
	Constraint constraint3(nodeNum1,nodeNum2,CONSTRAINTRELATIVEZ);
	ANCFSystem::constraints.push_back(constraint3);

	Constraint constraint4(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDX1);
	ANCFSystem::constraints.push_back(constraint4);
	Constraint constraint5(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDY1);
	ANCFSystem::constraints.push_back(constraint5);
	Constraint constraint6(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDZ1);
	ANCFSystem::constraints.push_back(constraint6);

	Constraint constraint7(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDX2);
	ANCFSystem::constraints.push_back(constraint7);
	Constraint constraint8(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDY2);
	ANCFSystem::constraints.push_back(constraint8);
	Constraint constraint9(nodeNum1,nodeNum2,CONSTRAINTRELATIVEDZ2);
	ANCFSystem::constraints.push_back(constraint9);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteSpherical(int nodeNum)
{
	Constraint constraint(nodeNum,CONSTRAINTABSOLUTEX);
	ANCFSystem::constraints.push_back(constraint);
	Constraint constraint2(nodeNum,CONSTRAINTABSOLUTEY);
	ANCFSystem::constraints.push_back(constraint2);
	Constraint constraint3(nodeNum,CONSTRAINTABSOLUTEZ);
	ANCFSystem::constraints.push_back(constraint3);

	return 0;
}
	
int ANCFSystem::addConstraint_RelativeSpherical(int nodeNum1, int nodeNum2)
{
	Constraint constraint(nodeNum1,nodeNum2,CONSTRAINTRELATIVEX);
	ANCFSystem::constraints.push_back(constraint);
	Constraint constraint2(nodeNum1,nodeNum2,CONSTRAINTRELATIVEY);
	ANCFSystem::constraints.push_back(constraint2);
	Constraint constraint3(nodeNum1,nodeNum2,CONSTRAINTRELATIVEZ);
	ANCFSystem::constraints.push_back(constraint3);

	return 0;
}

int ANCFSystem::addConstraint_AbsoluteX(Element& element, int node_local)
{
	addConstraint_AbsoluteX(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteY(Element& element, int node_local)
{
	addConstraint_AbsoluteY(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteZ(Element& element, int node_local)
{
	addConstraint_AbsoluteZ(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDX1(Element& element, int node_local)
{
	addConstraint_AbsoluteDX1(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDX2(Element& element, int node_local)
{
	addConstraint_AbsoluteDX2(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDY1(Element& element, int node_local)
{
	addConstraint_AbsoluteDY1(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDY2(Element& element, int node_local)
{
	addConstraint_AbsoluteDY2(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDZ1(Element& element, int node_local)
{
	addConstraint_AbsoluteDZ1(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteDZ2(Element& element, int node_local)
{
	addConstraint_AbsoluteDZ2(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteFixed(Element& element, int node_local)
{
	addConstraint_AbsoluteFixed(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_AbsoluteSpherical(Element& element, int node_local)
{
	addConstraint_AbsoluteSpherical(element.getElementIndex()*2+node_local);
	return 0;
}

int ANCFSystem::addConstraint_RelativeX(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeX(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeY(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeY(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeZ(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeZ(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeDX1(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeDX1(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeDX2(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeDX2(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeDY1(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeDY1(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeDY2(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeDY2(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeDZ1(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeDZ1(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeDZ2(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeDZ2(element1.getElementIndex()*2+node_local1,element2.getElementIndex()*2+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeFixed(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeFixed(element1.getElementIndex()*4+node_local1,element2.getElementIndex()*4+node_local2);
	return 0;
}

int ANCFSystem::addConstraint_RelativeSpherical(Element& element1, int node_local1, Element& element2, int node_local2)
{
	addConstraint_RelativeSpherical(element1.getElementIndex()*4+node_local1,element2.getElementIndex()*4+node_local2);
	return 0;
}

int ANCFSystem::updatePhiq()
{
	ANCFSystem::phi_q = zeros(constraints.size(),elements.size()*36);
	for(int i=0;i<constraints.size();i++)
	{
		Constraint constraint = constraints[i];
		phi_q(i,constraint.dofLoc.x) = 1.0;
		if(constraint.nodeNum2!=-1) phi_q(i,constraint.dofLoc.y) = -1.0;
	}

	return 0;
}

int ANCFSystem::updateAppliedForces()
{
	ANCFSystem::fapp = zeros(36*elements.size(),1);

	for(int i=0;i<appliedForces.size();i++)
	{
		Force force = appliedForces[i];

		float3 normal = normalize(force.direction);

		double n1 = normal.x*force.magnitude;
		double n2 = normal.y*force.magnitude;
		double n3 = normal.z*force.magnitude;

		double a = elements[force.element].getLength_l();
		double b = elements[force.element].getLength_b();
		double xi = force.position.x;
		double eta = force.position.y;

		double* f = ANCFSystem::fapp.memptr();
		f = &f[36*force.element];

		f[0] += -(xi - 1) * (eta - 1) * (2 * eta * eta - eta + 2 * xi * xi - xi - 1) * n1;
		f[1] += -(xi - 1) * (eta - 1) * (2 * eta * eta - eta + 2 * xi * xi - xi - 1) * n2;
		f[2] += -(xi - 1) * (eta - 1) * (2 * eta * eta - eta + 2 * xi * xi - xi - 1) * n3;
		f[3] += -a * xi *  pow( (xi - 1),  2) * (eta - 1) * n1;
		f[4] += -a * xi *  pow( (xi - 1),  2) * (eta - 1) * n2;
		f[5] += -a * xi *  pow( (xi - 1),  2) * (eta - 1) * n3;
		f[6] += -b * eta *  pow( (eta - 1),  2) * (xi - 1) * n1;
		f[7] += -b * eta *  pow( (eta - 1),  2) * (xi - 1) * n2;
		f[8] += -b * eta *  pow( (eta - 1),  2) * (xi - 1) * n3;
		f[9] += xi * (2 * eta * eta - eta - 3 * xi + 2 * xi * xi) * (eta - 1) * n1;
		f[10] += xi * (2 * eta * eta - eta - 3 * xi + 2 * xi * xi) * (eta - 1) * n2;
		f[11] += xi * (2 * eta * eta - eta - 3 * xi + 2 * xi * xi) * (eta - 1) * n3;
		f[12] += -a * xi * xi * (xi - 1) * (eta - 1) * n1;
		f[13] += -a * xi * xi * (xi - 1) * (eta - 1) * n2;
		f[14] += -a * xi * xi * (xi - 1) * (eta - 1) * n3;
		f[15] += b * xi * eta *  pow( (eta - 1),  2) * n1;
		f[16] += b * xi * eta *  pow( (eta - 1),  2) * n2;
		f[17] += b * xi * eta *  pow( (eta - 1),  2) * n3;
		f[18] += -xi * eta * (1 - 3 * xi - 3 * eta + 2 * eta * eta + 2 * xi * xi) * n1;
		f[19] += -xi * eta * (1 - 3 * xi - 3 * eta + 2 * eta * eta + 2 * xi * xi) * n2;
		f[20] += -xi * eta * (1 - 3 * xi - 3 * eta + 2 * eta * eta + 2 * xi * xi) * n3;
		f[21] += a * xi * xi * eta * (xi - 1) * n1;
		f[22] += a * xi * xi * eta * (xi - 1) * n2;
		f[23] += a * xi * xi * eta * (xi - 1) * n3;
		f[24] += b * xi * eta * eta * (eta - 1) * n1;
		f[25] += b * xi * eta * eta * (eta - 1) * n2;
		f[26] += b * xi * eta * eta * (eta - 1) * n3;
		f[27] += eta * (xi - 1) * (2 * xi * xi - xi - 3 * eta + 2 * eta * eta) * n1;
		f[28] += eta * (xi - 1) * (2 * xi * xi - xi - 3 * eta + 2 * eta * eta) * n2;
		f[29] += eta * (xi - 1) * (2 * xi * xi - xi - 3 * eta + 2 * eta * eta) * n3;
		f[30] += a * xi * eta *  pow( (xi - 1),  2) * n1;
		f[31] += a * xi * eta *  pow( (xi - 1),  2) * n2;
		f[32] += a * xi * eta *  pow( (xi - 1),  2) * n3;
		f[33] += -b * eta * eta * (xi - 1) * (eta - 1) * n1;
		f[34] += -b * eta * eta * (xi - 1) * (eta - 1) * n2;
		f[35] += -b * eta * eta * (xi - 1) * (eta - 1) * n3;
	}

	return 0;
}

int ANCFSystem::updatePhi()
{
	phi = zeros(constraints.size(),1);
	for(int i=0;i<constraints.size();i++)
	{
		Constraint constraint = constraints[i];
		if(constraint.nodeNum2 == -1)
		{
			phi(i,0) = pnew(constraint.dofLoc.x,0)-phi_o(i,0);
		}
		else
		{
			phi(i,0) = pnew(constraint.dofLoc.x,0)-pnew(constraint.dofLoc.y,0)-phi_o(i,0);
		}
	}
}


int ANCFSystem::calculateInitialPhi()
{
	phi_o = zeros(constraints.size(),1);
	for(int i=0;i<constraints.size();i++)
	{
		Constraint constraint = constraints[i];

		if(constraint.nodeNum2 == -1)
		{
			phi_o(i,0) = p(constraint.dofLoc.x,0);
		}
		else
		{
			phi_o(i,0) = p(constraint.dofLoc.x,0)-p(constraint.dofLoc.y,0);
		}
	}

	return 0;
}

double4 getSphereLoc(double* p, double xi, double eta, double a, double b)
{
	return make_double4(
			b * pow(eta, 0.3e1) * p[33] + 0.2e1 * pow(eta, 0.3e1) * p[27] * xi - 0.3e1 * eta * eta * p[27] * xi + a * pow(xi, 0.3e1) * p[3] + eta * p[27] * xi - 0.2e1 * pow(xi, 0.3e1) * eta * p[18] - 0.3e1 * eta * p[27] * xi * xi + 0.2e1 * eta * p[27] * pow(xi, 0.3e1) + 0.3e1 * xi * xi * eta * p[18] + 0.2e1 * pow(xi, 0.3e1) * p[9] * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[18] + 0.3e1 * xi * eta * eta * p[18] - 0.3e1 * xi * p[9] * eta * eta + 0.2e1 * xi * p[9] * pow(eta, 0.3e1) - 0.3e1 * xi * xi * p[9] * eta + xi * p[9] * eta + 0.3e1 * p[0] * xi * xi * eta - 0.2e1 * p[0] * pow(xi, 0.3e1) * eta - p[0] * xi * eta + 0.3e1 * p[0] * xi * eta * eta - 0.2e1 * p[0] * xi * pow(eta, 0.3e1) + b * pow(eta, 0.3e1) * p[6] - 0.2e1 * a * xi * xi * p[3] + a * pow(xi, 0.3e1) * p[12] - 0.2e1 * b * eta * eta * p[6] + p[0] + a * xi * p[3] + b * eta * p[6] - a * xi * xi * p[12] + b * xi * eta * p[15] - a * xi * xi * eta * p[21] - b * xi * eta * eta * p[24] + a * xi * eta * p[30] - b * eta * eta * p[33] + 0.2e1 * p[0] * pow(xi, 0.3e1) - 0.3e1 * p[0] * xi * xi + 0.2e1 * p[0] * pow(eta, 0.3e1) - 0.3e1 * p[0] * eta * eta + 0.3e1 * xi * xi * p[9] - 0.2e1 * pow(xi, 0.3e1) * p[9] + 0.3e1 * eta * eta * p[27] - 0.2e1 * pow(eta, 0.3e1) * p[27] - xi * eta * p[18] - a * pow(xi, 0.3e1) * p[3] * eta + 0.2e1 * a * xi * xi * p[3] * eta - a * xi * p[3] * eta - b * pow(eta, 0.3e1) * p[6] * xi + 0.2e1 * b * eta * eta * p[6] * xi - b * eta * p[6] * xi - a * pow(xi, 0.3e1) * p[12] * eta + a * xi * xi * p[12] * eta + b * xi * pow(eta, 0.3e1) * p[15] - 0.2e1 * b * xi * eta * eta * p[15] + a * pow(xi, 0.3e1) * eta * p[21] + b * xi * pow(eta, 0.3e1) * p[24] + a * pow(xi, 0.3e1) * eta * p[30] - 0.2e1 * a * xi * xi * eta * p[30] - b * pow(eta, 0.3e1) * p[33] * xi + b * eta * eta * p[33] * xi,
			a * pow(xi, 0.3e1) * eta * p[31] - 0.2e1 * b * xi * eta * eta * p[16] + a * pow(xi, 0.3e1) * eta * p[22] + b * xi * pow(eta, 0.3e1) * p[25] + 0.3e1 * xi * xi * eta * p[19] + p[1] - xi * eta * p[19] - a * pow(xi, 0.3e1) * p[4] * eta + 0.2e1 * a * xi * xi * p[4] * eta - a * xi * p[4] * eta - b * pow(eta, 0.3e1) * p[7] * xi + 0.2e1 * b * eta * eta * p[7] * xi - b * eta * p[7] * xi - a * pow(xi, 0.3e1) * p[13] * eta + a * xi * xi * p[13] * eta + b * xi * pow(eta, 0.3e1) * p[16] + 0.2e1 * xi * p[10] * pow(eta, 0.3e1) + xi * p[10] * eta - 0.3e1 * xi * p[10] * eta * eta - 0.2e1 * p[1] * pow(xi, 0.3e1) * eta + 0.3e1 * p[1] * xi * eta * eta - p[1] * xi * eta + 0.3e1 * p[1] * xi * xi * eta - 0.2e1 * p[1] * xi * pow(eta, 0.3e1) + b * pow(eta, 0.3e1) * p[34] + a * pow(xi, 0.3e1) * p[13] - 0.2e1 * a * xi * xi * p[4] - 0.2e1 * b * eta * eta * p[7] + b * pow(eta, 0.3e1) * p[7] + eta * p[28] * xi + 0.2e1 * pow(eta, 0.3e1) * p[28] * xi + a * pow(xi, 0.3e1) * p[4] + 0.2e1 * eta * p[28] * pow(xi, 0.3e1) - 0.2e1 * pow(xi, 0.3e1) * eta * p[19] - 0.3e1 * eta * eta * p[28] * xi - 0.3e1 * eta * p[28] * xi * xi + 0.2e1 * pow(xi, 0.3e1) * p[10] * eta - 0.3e1 * xi * xi * p[10] * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[19] + 0.3e1 * xi * eta * eta * p[19] + a * xi * p[4] + b * eta * p[7] - a * xi * xi * p[13] + b * xi * eta * p[16] - a * xi * xi * eta * p[22] - b * xi * eta * eta * p[25] + a * xi * eta * p[31] - b * eta * eta * p[34] + 0.2e1 * p[1] * pow(xi, 0.3e1) - 0.3e1 * p[1] * xi * xi + 0.2e1 * p[1] * pow(eta, 0.3e1) - 0.3e1 * p[1] * eta * eta + 0.3e1 * xi * xi * p[10] - 0.2e1 * pow(xi, 0.3e1) * p[10] + 0.3e1 * eta * eta * p[28] - 0.2e1 * pow(eta, 0.3e1) * p[28] - 0.2e1 * a * xi * xi * eta * p[31] - b * pow(eta, 0.3e1) * p[34] * xi + b * eta * eta * p[34] * xi,
			p[2] - xi * eta * p[20] - a * pow(xi, 0.3e1) * p[5] * eta + 0.2e1 * a * xi * xi * p[5] * eta - a * xi * p[5] * eta - b * pow(eta, 0.3e1) * p[8] * xi + 0.2e1 * b * eta * eta * p[8] * xi - b * eta * p[8] * xi - a * pow(xi, 0.3e1) * p[14] * eta + a * xi * xi * p[14] * eta + b * xi * pow(eta, 0.3e1) * p[17] - 0.2e1 * b * xi * eta * eta * p[17] + a * pow(xi, 0.3e1) * eta * p[23] + b * xi * pow(eta, 0.3e1) * p[26] + a * pow(xi, 0.3e1) * eta * p[32] - 0.2e1 * a * xi * xi * eta * p[32] - b * pow(eta, 0.3e1) * p[35] * xi + b * eta * eta * p[35] * xi + b * pow(eta, 0.3e1) * p[35] + 0.3e1 * p[2] * xi * eta * eta - p[2] * xi * eta + 0.3e1 * xi * eta * eta * p[20] - 0.3e1 * xi * xi * p[11] * eta + 0.2e1 * pow(xi, 0.3e1) * p[11] * eta + 0.3e1 * xi * xi * eta * p[20] - 0.3e1 * eta * p[29] * xi * xi + 0.2e1 * xi * p[11] * pow(eta, 0.3e1) - 0.2e1 * b * eta * eta * p[8] + b * pow(eta, 0.3e1) * p[8] + a * pow(xi, 0.3e1) * p[14] + a * pow(xi, 0.3e1) * p[5] - 0.2e1 * a * xi * xi * p[5] - 0.3e1 * eta * eta * p[29] * xi + eta * p[29] * xi + 0.2e1 * pow(eta, 0.3e1) * p[29] * xi + 0.3e1 * p[2] * xi * xi * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[20] + xi * p[11] * eta - 0.2e1 * p[2] * pow(xi, 0.3e1) * eta - 0.2e1 * p[2] * xi * pow(eta, 0.3e1) - 0.2e1 * pow(xi, 0.3e1) * eta * p[20] - 0.3e1 * xi * p[11] * eta * eta + 0.2e1 * eta * p[29] * pow(xi, 0.3e1) + a * xi * p[5] + b * eta * p[8] - a * xi * xi * p[14] + b * xi * eta * p[17] - a * xi * xi * eta * p[23] - b * xi * eta * eta * p[26] + a * xi * eta * p[32] - b * eta * eta * p[35] + 0.2e1 * p[2] * pow(xi, 0.3e1) - 0.3e1 * p[2] * xi * xi + 0.2e1 * p[2] * pow(eta, 0.3e1) - 0.3e1 * p[2] * eta * eta + 0.3e1 * xi * xi * p[11] - 0.2e1 * pow(xi, 0.3e1) * p[11] + 0.3e1 * eta * eta * p[29] - 0.2e1 * pow(eta, 0.3e1) * p[29],
		0);
}

double4 checkCollision_Sphere(double4 sphereLoc1, double4 sphereLoc2, double r1, double r2)
{
	double distance = sqrt((sphereLoc1.x-sphereLoc2.x)*(sphereLoc1.x-sphereLoc2.x)+(sphereLoc1.y-sphereLoc2.y)*(sphereLoc1.y-sphereLoc2.y)+(sphereLoc1.z-sphereLoc2.z)*(sphereLoc1.z-sphereLoc2.z));//sqrt(dot(sphereLoc1-sphereLoc2,sphereLoc1-sphereLoc2));
	double4 collision;
	collision.x = (sphereLoc1.x-sphereLoc2.x)/distance;
	collision.y = (sphereLoc1.y-sphereLoc2.y)/distance;
	collision.z = (sphereLoc1.z-sphereLoc2.z)/distance;
	if(distance<(r1+r2))
	{

		collision.w = r1+r2-distance;
		//if(r1+r2-distance>r1) collision.w = r1;
		return collision;
	}
	else
	{
		collision.w = 0;
		return collision;
	}
}

double4 getVelocity(double* p, double xi, double eta, double a, double b)
{
	double4 relVel = make_double4(
			b * pow(eta, 0.3e1) * p[33] + 0.2e1 * pow(eta, 0.3e1) * p[27] * xi - 0.3e1 * eta * eta * p[27] * xi + a * pow(xi, 0.3e1) * p[3] + eta * p[27] * xi - 0.2e1 * pow(xi, 0.3e1) * eta * p[18] - 0.3e1 * eta * p[27] * xi * xi + 0.2e1 * eta * p[27] * pow(xi, 0.3e1) + 0.3e1 * xi * xi * eta * p[18] + 0.2e1 * pow(xi, 0.3e1) * p[9] * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[18] + 0.3e1 * xi * eta * eta * p[18] - 0.3e1 * xi * p[9] * eta * eta + 0.2e1 * xi * p[9] * pow(eta, 0.3e1) - 0.3e1 * xi * xi * p[9] * eta + xi * p[9] * eta + 0.3e1 * p[0] * xi * xi * eta - 0.2e1 * p[0] * pow(xi, 0.3e1) * eta - p[0] * xi * eta + 0.3e1 * p[0] * xi * eta * eta - 0.2e1 * p[0] * xi * pow(eta, 0.3e1) + b * pow(eta, 0.3e1) * p[6] - 0.2e1 * a * xi * xi * p[3] + a * pow(xi, 0.3e1) * p[12] - 0.2e1 * b * eta * eta * p[6] + p[0] + a * xi * p[3] + b * eta * p[6] - a * xi * xi * p[12] + b * xi * eta * p[15] - a * xi * xi * eta * p[21] - b * xi * eta * eta * p[24] + a * xi * eta * p[30] - b * eta * eta * p[33] + 0.2e1 * p[0] * pow(xi, 0.3e1) - 0.3e1 * p[0] * xi * xi + 0.2e1 * p[0] * pow(eta, 0.3e1) - 0.3e1 * p[0] * eta * eta + 0.3e1 * xi * xi * p[9] - 0.2e1 * pow(xi, 0.3e1) * p[9] + 0.3e1 * eta * eta * p[27] - 0.2e1 * pow(eta, 0.3e1) * p[27] - xi * eta * p[18] - a * pow(xi, 0.3e1) * p[3] * eta + 0.2e1 * a * xi * xi * p[3] * eta - a * xi * p[3] * eta - b * pow(eta, 0.3e1) * p[6] * xi + 0.2e1 * b * eta * eta * p[6] * xi - b * eta * p[6] * xi - a * pow(xi, 0.3e1) * p[12] * eta + a * xi * xi * p[12] * eta + b * xi * pow(eta, 0.3e1) * p[15] - 0.2e1 * b * xi * eta * eta * p[15] + a * pow(xi, 0.3e1) * eta * p[21] + b * xi * pow(eta, 0.3e1) * p[24] + a * pow(xi, 0.3e1) * eta * p[30] - 0.2e1 * a * xi * xi * eta * p[30] - b * pow(eta, 0.3e1) * p[33] * xi + b * eta * eta * p[33] * xi,
			a * pow(xi, 0.3e1) * eta * p[31] - 0.2e1 * b * xi * eta * eta * p[16] + a * pow(xi, 0.3e1) * eta * p[22] + b * xi * pow(eta, 0.3e1) * p[25] + 0.3e1 * xi * xi * eta * p[19] + p[1] - xi * eta * p[19] - a * pow(xi, 0.3e1) * p[4] * eta + 0.2e1 * a * xi * xi * p[4] * eta - a * xi * p[4] * eta - b * pow(eta, 0.3e1) * p[7] * xi + 0.2e1 * b * eta * eta * p[7] * xi - b * eta * p[7] * xi - a * pow(xi, 0.3e1) * p[13] * eta + a * xi * xi * p[13] * eta + b * xi * pow(eta, 0.3e1) * p[16] + 0.2e1 * xi * p[10] * pow(eta, 0.3e1) + xi * p[10] * eta - 0.3e1 * xi * p[10] * eta * eta - 0.2e1 * p[1] * pow(xi, 0.3e1) * eta + 0.3e1 * p[1] * xi * eta * eta - p[1] * xi * eta + 0.3e1 * p[1] * xi * xi * eta - 0.2e1 * p[1] * xi * pow(eta, 0.3e1) + b * pow(eta, 0.3e1) * p[34] + a * pow(xi, 0.3e1) * p[13] - 0.2e1 * a * xi * xi * p[4] - 0.2e1 * b * eta * eta * p[7] + b * pow(eta, 0.3e1) * p[7] + eta * p[28] * xi + 0.2e1 * pow(eta, 0.3e1) * p[28] * xi + a * pow(xi, 0.3e1) * p[4] + 0.2e1 * eta * p[28] * pow(xi, 0.3e1) - 0.2e1 * pow(xi, 0.3e1) * eta * p[19] - 0.3e1 * eta * eta * p[28] * xi - 0.3e1 * eta * p[28] * xi * xi + 0.2e1 * pow(xi, 0.3e1) * p[10] * eta - 0.3e1 * xi * xi * p[10] * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[19] + 0.3e1 * xi * eta * eta * p[19] + a * xi * p[4] + b * eta * p[7] - a * xi * xi * p[13] + b * xi * eta * p[16] - a * xi * xi * eta * p[22] - b * xi * eta * eta * p[25] + a * xi * eta * p[31] - b * eta * eta * p[34] + 0.2e1 * p[1] * pow(xi, 0.3e1) - 0.3e1 * p[1] * xi * xi + 0.2e1 * p[1] * pow(eta, 0.3e1) - 0.3e1 * p[1] * eta * eta + 0.3e1 * xi * xi * p[10] - 0.2e1 * pow(xi, 0.3e1) * p[10] + 0.3e1 * eta * eta * p[28] - 0.2e1 * pow(eta, 0.3e1) * p[28] - 0.2e1 * a * xi * xi * eta * p[31] - b * pow(eta, 0.3e1) * p[34] * xi + b * eta * eta * p[34] * xi,
			p[2] - xi * eta * p[20] - a * pow(xi, 0.3e1) * p[5] * eta + 0.2e1 * a * xi * xi * p[5] * eta - a * xi * p[5] * eta - b * pow(eta, 0.3e1) * p[8] * xi + 0.2e1 * b * eta * eta * p[8] * xi - b * eta * p[8] * xi - a * pow(xi, 0.3e1) * p[14] * eta + a * xi * xi * p[14] * eta + b * xi * pow(eta, 0.3e1) * p[17] - 0.2e1 * b * xi * eta * eta * p[17] + a * pow(xi, 0.3e1) * eta * p[23] + b * xi * pow(eta, 0.3e1) * p[26] + a * pow(xi, 0.3e1) * eta * p[32] - 0.2e1 * a * xi * xi * eta * p[32] - b * pow(eta, 0.3e1) * p[35] * xi + b * eta * eta * p[35] * xi + b * pow(eta, 0.3e1) * p[35] + 0.3e1 * p[2] * xi * eta * eta - p[2] * xi * eta + 0.3e1 * xi * eta * eta * p[20] - 0.3e1 * xi * xi * p[11] * eta + 0.2e1 * pow(xi, 0.3e1) * p[11] * eta + 0.3e1 * xi * xi * eta * p[20] - 0.3e1 * eta * p[29] * xi * xi + 0.2e1 * xi * p[11] * pow(eta, 0.3e1) - 0.2e1 * b * eta * eta * p[8] + b * pow(eta, 0.3e1) * p[8] + a * pow(xi, 0.3e1) * p[14] + a * pow(xi, 0.3e1) * p[5] - 0.2e1 * a * xi * xi * p[5] - 0.3e1 * eta * eta * p[29] * xi + eta * p[29] * xi + 0.2e1 * pow(eta, 0.3e1) * p[29] * xi + 0.3e1 * p[2] * xi * xi * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[20] + xi * p[11] * eta - 0.2e1 * p[2] * pow(xi, 0.3e1) * eta - 0.2e1 * p[2] * xi * pow(eta, 0.3e1) - 0.2e1 * pow(xi, 0.3e1) * eta * p[20] - 0.3e1 * xi * p[11] * eta * eta + 0.2e1 * eta * p[29] * pow(xi, 0.3e1) + a * xi * p[5] + b * eta * p[8] - a * xi * xi * p[14] + b * xi * eta * p[17] - a * xi * xi * eta * p[23] - b * xi * eta * eta * p[26] + a * xi * eta * p[32] - b * eta * eta * p[35] + 0.2e1 * p[2] * pow(xi, 0.3e1) - 0.3e1 * p[2] * xi * xi + 0.2e1 * p[2] * pow(eta, 0.3e1) - 0.3e1 * p[2] * eta * eta + 0.3e1 * xi * xi * p[11] - 0.2e1 * pow(xi, 0.3e1) * p[11] + 0.3e1 * eta * eta * p[29] - 0.2e1 * pow(eta, 0.3e1) * p[29],
		0);

	relVel.w = sqrt(relVel.x*relVel.x+relVel.y*relVel.y+relVel.z*relVel.z);//-sqrt(pow(vSphere[0],2)+pow(vSphere[1],2)+pow(vSphere[2],2));

	return relVel;
}

int ANCFSystem::applyContactForce(int elementNum, double xi, double eta, double a, double b, double4 collision)
{
	double* f = fcon.memptr();
	f = &f[36*elementNum];
	double* vel = v.memptr();
	vel = &vel[36*elementNum];
	double nu = elements[elementNum].getNu();
	double nuSphere = .3;
	double ESphere = 2e7;
	double r = elements[elementNum].getThickness();
	double rSphere = sphere.w;
	double sigma = (1-nu*nu)/elements[elementNum].getElasticModulus()+(1-nuSphere*nuSphere)/ESphere;
	double kappa = 4.0/(3.0*sigma)*sqrt(r*rSphere/(r+rSphere));
	kappa = kappa*pow(collision.w,(double)1.5);

	double4 v = getVelocity(vel,xi,eta,a,b);
	double deltaDot = v.x*collision.x+v.y*collision.y+v.z*collision.z;
	double4 vct = make_double4(v.x-deltaDot*collision.x,v.y-deltaDot*collision.y,v.z-deltaDot*collision.z,0);
	double norm_vct = sqrt(vct.x*vct.x+vct.y*vct.y+vct.z*vct.z);
	vct = make_double4(vct.x/norm_vct,vct.y/norm_vct,vct.z/norm_vct,0);
	kappa = kappa*(1.0-.75*(1-coefRestitution*coefRestitution)*deltaDot/v.w); //might need a negative sign here!

	double n1 = kappa*(collision.x)-frictionCoef*kappa*vct.x;
	double n2 = kappa*(collision.y)-frictionCoef*kappa*vct.y;
	double n3 = kappa*(collision.z)-frictionCoef*kappa*vct.z;

	// General shape function (tilts)
	f[0] += -(xi - 1) * (eta - 1) * (2 * eta * eta - eta + 2 * xi * xi - xi - 1) * n1;
	f[1] += -(xi - 1) * (eta - 1) * (2 * eta * eta - eta + 2 * xi * xi - xi - 1) * n2;
	f[2] += -(xi - 1) * (eta - 1) * (2 * eta * eta - eta + 2 * xi * xi - xi - 1) * n3;
	f[3] += -a * xi *  pow( (xi - 1),  2) * (eta - 1) * n1;
	f[4] += -a * xi *  pow( (xi - 1),  2) * (eta - 1) * n2;
	f[5] += -a * xi *  pow( (xi - 1),  2) * (eta - 1) * n3;
	f[6] += -b * eta *  pow( (eta - 1),  2) * (xi - 1) * n1;
	f[7] += -b * eta *  pow( (eta - 1),  2) * (xi - 1) * n2;
	f[8] += -b * eta *  pow( (eta - 1),  2) * (xi - 1) * n3;
	f[9] += xi * (2 * eta * eta - eta - 3 * xi + 2 * xi * xi) * (eta - 1) * n1;
	f[10] += xi * (2 * eta * eta - eta - 3 * xi + 2 * xi * xi) * (eta - 1) * n2;
	f[11] += xi * (2 * eta * eta - eta - 3 * xi + 2 * xi * xi) * (eta - 1) * n3;
	f[12] += -a * xi * xi * (xi - 1) * (eta - 1) * n1;
	f[13] += -a * xi * xi * (xi - 1) * (eta - 1) * n2;
	f[14] += -a * xi * xi * (xi - 1) * (eta - 1) * n3;
	f[15] += b * xi * eta *  pow( (eta - 1),  2) * n1;
	f[16] += b * xi * eta *  pow( (eta - 1),  2) * n2;
	f[17] += b * xi * eta *  pow( (eta - 1),  2) * n3;
	f[18] += -xi * eta * (1 - 3 * xi - 3 * eta + 2 * eta * eta + 2 * xi * xi) * n1;
	f[19] += -xi * eta * (1 - 3 * xi - 3 * eta + 2 * eta * eta + 2 * xi * xi) * n2;
	f[20] += -xi * eta * (1 - 3 * xi - 3 * eta + 2 * eta * eta + 2 * xi * xi) * n3;
	f[21] += a * xi * xi * eta * (xi - 1) * n1;
	f[22] += a * xi * xi * eta * (xi - 1) * n2;
	f[23] += a * xi * xi * eta * (xi - 1) * n3;
	f[24] += b * xi * eta * eta * (eta - 1) * n1;
	f[25] += b * xi * eta * eta * (eta - 1) * n2;
	f[26] += b * xi * eta * eta * (eta - 1) * n3;
	f[27] += eta * (xi - 1) * (2 * xi * xi - xi - 3 * eta + 2 * eta * eta) * n1;
	f[28] += eta * (xi - 1) * (2 * xi * xi - xi - 3 * eta + 2 * eta * eta) * n2;
	f[29] += eta * (xi - 1) * (2 * xi * xi - xi - 3 * eta + 2 * eta * eta) * n3;
	f[30] += a * xi * eta *  pow( (xi - 1),  2) * n1;
	f[31] += a * xi * eta *  pow( (xi - 1),  2) * n2;
	f[32] += a * xi * eta *  pow( (xi - 1),  2) * n3;
	f[33] += -b * eta * eta * (xi - 1) * (eta - 1) * n1;
	f[34] += -b * eta * eta * (xi - 1) * (eta - 1) * n2;
	f[35] += -b * eta * eta * (xi - 1) * (eta - 1) * n3;

	return 0;
}

int ANCFSystem::detectCollisions()
{
	fcon = zeros(elements.size()*36,1);
	numCollisions = 0;
#pragma omp parallel for
	for(int i=0;i<elements.size();i++)
	{
		Element element = elements[i];
		double* pos = p.memptr();
		pos = &pos[36*i];
		double a = element.getLength_l();
		double b = element.getLength_b();
		double th = element.getThickness();
		double2 sInc = make_double2(1.0/((double)(numContactPoints.x-1)),1.0/((double)(numContactPoints.y-1)));
		for(int j=0;j<numContactPoints.x-1;j++)
		{
			for(int k=0;k<numContactPoints.y;k++)
			{
				double4 position = getSphereLoc(pos,sInc.x*j,sInc.y*k,a,b);//checkCollision_Sphere(getSphereLoc(pos,sInc*j,sInc*k,a,b),sphere,th,sphere.w);
				double penetration = groundHeight-(position.y-element.getThickness()*.5);
				if(penetration>0)
				{
					numCollisions++;
					applyContactForce(i,sInc.x*j,sInc.y*k,a,b,make_double4(0,1,0,penetration));
				}
			}
		}
	}
	return 0;
}

int ANCFSystem::initializeSystem()
{
	stiffness = zeros(36*elements.size(),36*elements.size());
	getInitialCurvature();
#pragma omp parallel for
	for(int i=0;i<elements.size();i++) ANCFSystem::updateInternalForces(p.memptr(),i);

	//ANCFSystem::updateAppliedForces();
	ANCFSystem::updatePhiq();
	ANCFSystem::calculateInitialPhi();

	mat massNew = join_rows(join_cols(mass,phi_q),join_cols(trans(phi_q),zeros(constraints.size(),constraints.size())));
	mat forceNew = join_cols(fext/*+fcon+fapp*/-fint,zeros(constraints.size(),1));
	//lhsInv = inv(massNew);

	a = solve(massNew,forceNew);

	//a = lhsInv*forceNew;
	lambda = a.rows(elements.size()*36,a.size()-1);

	a = a.rows(0,elements.size()*36-1);

	anew = a;
	pnew = p;
	vnew = v;

	return 0;
}

int ANCFSystem::DoTimeStep()
{
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start, 0);

	double norm_e=1;
	double norm_d=1;

	// update q and q_dot for initial guess
	pnew = p+h*v+.5*h*h*a;
	vnew = v+h*a;
	int it = 0;
	ANCFSystem::detectCollisions();

	ANCFSystem::detectCollisions();

	while(norm_e>tol&&norm_d>tol)
	{
		it++;
#pragma omp parallel for
		for(int i=0;i<elements.size();i++) ANCFSystem::updateInternalForces(pnew.memptr(),i);

		//ANCFSystem::updateAppliedForces();
		ANCFSystem::updatePhi();

		mat phiqlam = trans(phi_q)*lambda;
		mat phiqTrans = trans(phi_q);
		mat e = join_cols(mass*anew-fext-fcon/*-fapp*/+fint+phiqlam,1/(betaHHT*h*h)*phi);

		mat lhs = join_rows(join_cols(mass+betaHHT*h*h*stiffness,phi_q),join_cols(trans(phi_q),zeros(constraints.size(),constraints.size())));

		mat delta = solve(lhs,e);

		//mat delta = lhsInv*e;

		anew = anew - delta.rows(0,elements.size()*36-1);

		lambda = lambda - delta.rows(elements.size()*36,delta.size()-1);

		pnew = p+h*v+.5*h*h*((1-2*betaHHT)*a+2*betaHHT*anew);

		vnew = v+h*((1-gammaHHT)*a+gammaHHT*anew);

		norm_e = norm(e,2)/pow((double)elements.size(),2);
		norm_d = norm(delta,2)/pow((double)elements.size(),2);
//		printf("Iteration %d: norm_e = %f, norm_d = %f\n", it, norm_e, norm_d);
	}
	a = anew;
	v = vnew;
	p = pnew;
#pragma omp parallel for
	for(int i=0;i<elements.size();i++) ANCFSystem::updateInternalForces(pnew.memptr(),i);

	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	float elapsedTime;
	cudaEventElapsedTime(&elapsedTime , start, stop);
	printf("Time is %f ms\n", elapsedTime);

	timeToSimulate+=elapsedTime/1000.0;

	printf("Time: %f (it = %d, PTA pos = (%f, %.13f, %f)\n",this->getCurrentTime(),it,getXYZPosition(elements.size()-1,1,1).x,getXYZPosition(elements.size()-1,1,1).y,getXYZPosition(elements.size()-1,1,1).z);
	//printf("Weight = %f (should be %f)\n",lambda[0]*2,GRAVITYx*.15*.5*.001*7810.0);

	time+=h; 
	timeIndex++;

	return 0;
}

int ANCFSystem::writeToFile()
{
	char filename[100];
	sprintf(filename, "./posData/pos%d.dat", fileIndex);
	posFile.open(filename);
	double* posAll = p.memptr();
	double* pos;
	Material material;
	posFile << elements.size() << ", " << groundHeight << "," << endl;
	for(int i=0;i<elements.size();i++)
	{
		pos = &posAll[36*i];
		material = materials[i];
		posFile << material.l << ", " << material.b << ", " << material.th;
		for(int i=0;i<36;i++) posFile << ", " << pos[i];
		posFile << ","<< endl;
	}
//	for(int i=0;i<spheres.size();i++)
//	{
//		p = &pSpheres_h[3*i];
//		material = materialSpheres_h[i];
//		posFile << "sphere " << material.x << " " << p[0] << " " << p[1] << " " << p[2] << endl;
//	}
	posFile.close();
	fileIndex++;

	return 0;
}

float3 ANCFSystem::getXYZPosition(int elementIndex, double xi, double eta)
{
	double a = elements[elementIndex].getLength_l();
	double b = elements[elementIndex].getLength_b();
	double* p = this->p.memptr();
	p = &p[36*elementIndex];
	float3 pos;

	pos.x = b * pow(eta, 0.3e1) * p[33] + 0.2e1 * pow(eta, 0.3e1) * p[27] * xi - 0.3e1 * eta * eta * p[27] * xi + a * pow(xi, 0.3e1) * p[3] + eta * p[27] * xi - 0.2e1 * pow(xi, 0.3e1) * eta * p[18] - 0.3e1 * eta * p[27] * xi * xi + 0.2e1 * eta * p[27] * pow(xi, 0.3e1) + 0.3e1 * xi * xi * eta * p[18] + 0.2e1 * pow(xi, 0.3e1) * p[9] * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[18] + 0.3e1 * xi * eta * eta * p[18] - 0.3e1 * xi * p[9] * eta * eta + 0.2e1 * xi * p[9] * pow(eta, 0.3e1) - 0.3e1 * xi * xi * p[9] * eta + xi * p[9] * eta + 0.3e1 * p[0] * xi * xi * eta - 0.2e1 * p[0] * pow(xi, 0.3e1) * eta - p[0] * xi * eta + 0.3e1 * p[0] * xi * eta * eta - 0.2e1 * p[0] * xi * pow(eta, 0.3e1) + b * pow(eta, 0.3e1) * p[6] - 0.2e1 * a * xi * xi * p[3] + a * pow(xi, 0.3e1) * p[12] - 0.2e1 * b * eta * eta * p[6] + p[0] + a * xi * p[3] + b * eta * p[6] - a * xi * xi * p[12] + b * xi * eta * p[15] - a * xi * xi * eta * p[21] - b * xi * eta * eta * p[24] + a * xi * eta * p[30] - b * eta * eta * p[33] + 0.2e1 * p[0] * pow(xi, 0.3e1) - 0.3e1 * p[0] * xi * xi + 0.2e1 * p[0] * pow(eta, 0.3e1) - 0.3e1 * p[0] * eta * eta + 0.3e1 * xi * xi * p[9] - 0.2e1 * pow(xi, 0.3e1) * p[9] + 0.3e1 * eta * eta * p[27] - 0.2e1 * pow(eta, 0.3e1) * p[27] - xi * eta * p[18] - a * pow(xi, 0.3e1) * p[3] * eta + 0.2e1 * a * xi * xi * p[3] * eta - a * xi * p[3] * eta - b * pow(eta, 0.3e1) * p[6] * xi + 0.2e1 * b * eta * eta * p[6] * xi - b * eta * p[6] * xi - a * pow(xi, 0.3e1) * p[12] * eta + a * xi * xi * p[12] * eta + b * xi * pow(eta, 0.3e1) * p[15] - 0.2e1 * b * xi * eta * eta * p[15] + a * pow(xi, 0.3e1) * eta * p[21] + b * xi * pow(eta, 0.3e1) * p[24] + a * pow(xi, 0.3e1) * eta * p[30] - 0.2e1 * a * xi * xi * eta * p[30] - b * pow(eta, 0.3e1) * p[33] * xi + b * eta * eta * p[33] * xi;
	pos.y = a * pow(xi, 0.3e1) * eta * p[31] - 0.2e1 * b * xi * eta * eta * p[16] + a * pow(xi, 0.3e1) * eta * p[22] + b * xi * pow(eta, 0.3e1) * p[25] + 0.3e1 * xi * xi * eta * p[19] + p[1] - xi * eta * p[19] - a * pow(xi, 0.3e1) * p[4] * eta + 0.2e1 * a * xi * xi * p[4] * eta - a * xi * p[4] * eta - b * pow(eta, 0.3e1) * p[7] * xi + 0.2e1 * b * eta * eta * p[7] * xi - b * eta * p[7] * xi - a * pow(xi, 0.3e1) * p[13] * eta + a * xi * xi * p[13] * eta + b * xi * pow(eta, 0.3e1) * p[16] + 0.2e1 * xi * p[10] * pow(eta, 0.3e1) + xi * p[10] * eta - 0.3e1 * xi * p[10] * eta * eta - 0.2e1 * p[1] * pow(xi, 0.3e1) * eta + 0.3e1 * p[1] * xi * eta * eta - p[1] * xi * eta + 0.3e1 * p[1] * xi * xi * eta - 0.2e1 * p[1] * xi * pow(eta, 0.3e1) + b * pow(eta, 0.3e1) * p[34] + a * pow(xi, 0.3e1) * p[13] - 0.2e1 * a * xi * xi * p[4] - 0.2e1 * b * eta * eta * p[7] + b * pow(eta, 0.3e1) * p[7] + eta * p[28] * xi + 0.2e1 * pow(eta, 0.3e1) * p[28] * xi + a * pow(xi, 0.3e1) * p[4] + 0.2e1 * eta * p[28] * pow(xi, 0.3e1) - 0.2e1 * pow(xi, 0.3e1) * eta * p[19] - 0.3e1 * eta * eta * p[28] * xi - 0.3e1 * eta * p[28] * xi * xi + 0.2e1 * pow(xi, 0.3e1) * p[10] * eta - 0.3e1 * xi * xi * p[10] * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[19] + 0.3e1 * xi * eta * eta * p[19] + a * xi * p[4] + b * eta * p[7] - a * xi * xi * p[13] + b * xi * eta * p[16] - a * xi * xi * eta * p[22] - b * xi * eta * eta * p[25] + a * xi * eta * p[31] - b * eta * eta * p[34] + 0.2e1 * p[1] * pow(xi, 0.3e1) - 0.3e1 * p[1] * xi * xi + 0.2e1 * p[1] * pow(eta, 0.3e1) - 0.3e1 * p[1] * eta * eta + 0.3e1 * xi * xi * p[10] - 0.2e1 * pow(xi, 0.3e1) * p[10] + 0.3e1 * eta * eta * p[28] - 0.2e1 * pow(eta, 0.3e1) * p[28] - 0.2e1 * a * xi * xi * eta * p[31] - b * pow(eta, 0.3e1) * p[34] * xi + b * eta * eta * p[34] * xi;
	pos.z = p[2] - xi * eta * p[20] - a * pow(xi, 0.3e1) * p[5] * eta + 0.2e1 * a * xi * xi * p[5] * eta - a * xi * p[5] * eta - b * pow(eta, 0.3e1) * p[8] * xi + 0.2e1 * b * eta * eta * p[8] * xi - b * eta * p[8] * xi - a * pow(xi, 0.3e1) * p[14] * eta + a * xi * xi * p[14] * eta + b * xi * pow(eta, 0.3e1) * p[17] - 0.2e1 * b * xi * eta * eta * p[17] + a * pow(xi, 0.3e1) * eta * p[23] + b * xi * pow(eta, 0.3e1) * p[26] + a * pow(xi, 0.3e1) * eta * p[32] - 0.2e1 * a * xi * xi * eta * p[32] - b * pow(eta, 0.3e1) * p[35] * xi + b * eta * eta * p[35] * xi + b * pow(eta, 0.3e1) * p[35] + 0.3e1 * p[2] * xi * eta * eta - p[2] * xi * eta + 0.3e1 * xi * eta * eta * p[20] - 0.3e1 * xi * xi * p[11] * eta + 0.2e1 * pow(xi, 0.3e1) * p[11] * eta + 0.3e1 * xi * xi * eta * p[20] - 0.3e1 * eta * p[29] * xi * xi + 0.2e1 * xi * p[11] * pow(eta, 0.3e1) - 0.2e1 * b * eta * eta * p[8] + b * pow(eta, 0.3e1) * p[8] + a * pow(xi, 0.3e1) * p[14] + a * pow(xi, 0.3e1) * p[5] - 0.2e1 * a * xi * xi * p[5] - 0.3e1 * eta * eta * p[29] * xi + eta * p[29] * xi + 0.2e1 * pow(eta, 0.3e1) * p[29] * xi + 0.3e1 * p[2] * xi * xi * eta - 0.2e1 * xi * pow(eta, 0.3e1) * p[20] + xi * p[11] * eta - 0.2e1 * p[2] * pow(xi, 0.3e1) * eta - 0.2e1 * p[2] * xi * pow(eta, 0.3e1) - 0.2e1 * pow(xi, 0.3e1) * eta * p[20] - 0.3e1 * xi * p[11] * eta * eta + 0.2e1 * eta * p[29] * pow(xi, 0.3e1) + a * xi * p[5] + b * eta * p[8] - a * xi * xi * p[14] + b * xi * eta * p[17] - a * xi * xi * eta * p[23] - b * xi * eta * eta * p[26] + a * xi * eta * p[32] - b * eta * eta * p[35] + 0.2e1 * p[2] * pow(xi, 0.3e1) - 0.3e1 * p[2] * xi * xi + 0.2e1 * p[2] * pow(eta, 0.3e1) - 0.3e1 * p[2] * eta * eta + 0.3e1 * xi * xi * p[11] - 0.2e1 * pow(xi, 0.3e1) * p[11] + 0.3e1 * eta * eta * p[29] - 0.2e1 * pow(eta, 0.3e1) * p[29];

	return pos;
}
