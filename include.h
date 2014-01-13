#ifndef INCLUDE_H
#define INCLUDE_H

#include <cuda.h>
#include <cutil.h>
#include <cutil_math.h>
#include <cutil_inline.h>
#include <stdlib.h>
#include <armadillo>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <GL/glut.h>
#include "omp.h"

using namespace std;
using namespace arma;

#define PI 3.141592653589793238462643383279
#define GRAVITYx 0
#define GRAVITYy -9.81
#define GRAVITYz 0
#define OGL 1
#define SCALE 1

// constraint identifiers
#define CONSTRAINTABSOLUTEX 0
#define CONSTRAINTABSOLUTEY 1
#define CONSTRAINTABSOLUTEZ 2

#define CONSTRAINTABSOLUTEDX1 3
#define CONSTRAINTABSOLUTEDY1 4
#define CONSTRAINTABSOLUTEDZ1 5

#define CONSTRAINTABSOLUTEDX2 6
#define CONSTRAINTABSOLUTEDY2 7
#define CONSTRAINTABSOLUTEDZ2 8

#define CONSTRAINTRELATIVEX 9
#define CONSTRAINTRELATIVEY 10
#define CONSTRAINTRELATIVEZ 11

#define CONSTRAINTRELATIVEDX1 12
#define CONSTRAINTRELATIVEDY1 13
#define CONSTRAINTRELATIVEDZ1 14

#define CONSTRAINTRELATIVEDX2 15
#define CONSTRAINTRELATIVEDY2 16
#define CONSTRAINTRELATIVEDZ2 17

struct Material{
	double th;
	double nu;
	double E;
	double rho;
	double l;
	double b;
};

#define CASTD3(x) (double3*)thrust::raw_pointer_cast(&x[0])

class WaveFrontReader{
private:
	bool isUnique(int2 edge);
public:
	vector<float3> vertices;
	vector<int3> faces;
	vector<int2> edges;
	int readOBJ(string fileName);
};

class Node{
public:
	double x;
	double y;
	double z;
	double dx1;
	double dy1;
	double dz1;
	double dx2;
	double dy2;
	double dz2;

	Node()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->dx1 = 1;
		this->dy1 = 0;
		this->dz1 = 0;
		this->dx1 = 0;
		this->dy1 = 1;
		this->dz1 = 0;
	}
	/*
	Node(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		double mag = sqrt(x*x+y*y+z*z);
		this->dx = x/mag;
		this->dy = y/mag;
		this->dz = z/mag;
	}
	Node(float3 node)
	{
		double x = (double) node.x;
		double y = (double) node.y;
		double z = (double) node.z;
		this->x = x;
		this->y = y;
		this->z = z;
		double mag = sqrt(x*x+y*y+z*z);
		this->dx = x/mag;
		this->dy = y/mag;
		this->dz = z/mag;
	}
	*/
	Node(double x, double y, double z, double dx1, double dy1, double dz1, double dx2, double dy2, double dz2)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->dx1 = dx1;
		this->dy1 = dy1;
		this->dz1 = dz1;
		this->dx2 = dx2;
		this->dy2 = dy2;
		this->dz2 = dz2;
	}

	double getLength(Node node1, Node node2)
	{
		return sqrt(pow(node1.x-node2.x,2)+pow(node1.y-node2.y,2)+pow(node1.z-node2.z,2));
	}
};

class Element{
private:
	int index;
	Node node0;
	Node node1;
	Node node2;
	Node node3;
	double th;
	double nu;
	double E;
	double rho;
	double l;
	double b;

public:
	Element()
	{
		// create test element!
		this->node0=Node(0,0,0,1,0,0,0,0,1);
		this->node1=Node(0.6,0,0,1,0,0,0,0,1);
		this->node2=Node(0.6,0,0.6,1,0,0,0,0,1);
		this->node3=Node(0,0,0.6,1,0,0,0,0,1);
//		this->node0 = Node(0, 0, 0, 1, 0, 0, 0, 1, 0);
//		this->node1 = Node(0.6, 0, 0, 1, 0, 0, 0, 1, 0);
//		this->node2 = Node(0.6, 0.6, 0, 1, 0, 0, 0, 1, 0);
//		this->node3 = Node(0, 0.6, 0, 1, 0, 0, 0, 1, 0);
		this->th=.01;
		this->nu=.3;
		this->E=2.e7;
		this->rho=7810.0;
		this->l=0.6;
		this->b=0.6;
	}
	Element(Node node0, Node node1, Node node2, Node node3)
	{
		this->node0=node0;
		this->node1=node1;
		this->node2=node2;
		this->node3=node3;
		this->th=.01;
		this->l = getLength(node0,node1);//.5*.6*PI;//
		this->b = getLength(node1,node2);//.5*.3*PI;//.5*getLength(node1,node2)*PI;
//		this->b = this->l;
		this->nu=.3;
		this->E=1.0e5;
		this->rho=7200.0;
	}
	/*
	Element(Node firstNode, Node lastNode, int linear)
	{
		this->firstNode=firstNode;
		this->lastNode=lastNode;
		if(linear)
		{
			double mag = sqrt(pow(firstNode.x-lastNode.x,2)+pow(firstNode.y-lastNode.y,2)+pow(firstNode.z-lastNode.z,2));
			this->firstNode.dx = (lastNode.x-firstNode.x)/mag;
			this->firstNode.dy = (lastNode.y-firstNode.y)/mag;
			this->firstNode.dz = (lastNode.z-firstNode.z)/mag;
			this->lastNode.dx = (lastNode.x-firstNode.x)/mag;
			this->lastNode.dy = (lastNode.y-firstNode.y)/mag;
			this->lastNode.dz = (lastNode.z-firstNode.z)/mag;
		}
		this->r=.01;
		this->nu=.3;
		this->E=2.0e7;
		this->rho=7200.0;
		this->I=PI*r*r*r*r*.25;
		this->l=getLength(firstNode,lastNode);
	}
	Element(Node firstNode, Node lastNode, double r, double E, double rho, double nu)
	{
		this->firstNode=firstNode;
		this->lastNode=lastNode;
		this->r=r;
		this->nu=nu;
		this->E=E;
		this->rho=rho;
		this->I=PI*r*r*r*r*.25;
		this->l=getLength(firstNode,lastNode);
	}
	*/
	Node getNode0()
	{
		return this->node0;
	}
	Node getNode1()
	{
		return this->node1;
	}
	Node getNode2()
	{
		return this->node2;
	}
	Node getNode3()
	{
		return this->node3;
	}
	double getThickness()
	{
		return this->th;
	}
	double getNu()
	{
		return this->nu;
	}
	double getDensity()
	{
		return this->rho;
	}
	double getLength_l()
	{
		return this->l;
	}
	double getLength_b()
	{
		return this->b;
	}
	double getLength(Node node1, Node node2)
	{
		return sqrt(pow(node1.x-node2.x,2)+pow(node1.y-node2.y,2)+pow(node1.z-node2.z,2));
	}
	double getElasticModulus()
	{
		return this->E;
	}
	int getElementIndex()
	{
		return this->index;
	}
	int setLength_l(double l)
	{
		this->l = l;
		return 0;
	}
	int setLength_b(double b)
	{
		this->b = b;
		return 0;
	}
	int setThickness(double th)
	{
		this->th = th;
		return 0;
	}
	int setNu(double nu)
	{
		this->nu = nu;
		return 0;
	}
	int setDensity(double rho)
	{
		this->rho = rho;
		return 0;
	}
	int setElasticModulus(double E)
	{
		this->E = E;
		return 0;
	}
	int setElementIndex(int index)
	{
		this->index = index;
		return 0;
	}
};

//class Constraint{
//public:
//	int nodeNum;
//	int nodeNum2;
//	int constraintType;
//
//	Constraint(int nodeNum, int constraintType)
//	{
//		this->nodeNum = nodeNum;
//		this->constraintType = constraintType;
//	}
//	Constraint(int nodeNum1, int nodeNum2, int constraintType)
//	{
//		this->nodeNum = nodeNum1;
//		this->nodeNum2 = nodeNum2;
//		this->constraintType = constraintType;
//	}
//};

class Constraint{
public:
	int nodeNum;
	int nodeNum2;
	int constraintType;
	int2 dofLoc;

	Constraint(int nodeNum, int constraintType)
	{
		this->nodeNum = nodeNum;
		this->nodeNum2 = -1;
		this->constraintType = constraintType;

		switch (constraintType)
		{
		case CONSTRAINTABSOLUTEX:
			dofLoc.x = 9*nodeNum;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEY:
			dofLoc.x = 9*nodeNum+1;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEZ:
			dofLoc.x = 9*nodeNum+2;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDX1:
			dofLoc.x = 9*nodeNum+3;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDY1:
			dofLoc.x = 9*nodeNum+4;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDZ1:
			dofLoc.x = 9*nodeNum+5;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDX2:
			dofLoc.x = 9*nodeNum+6;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDY2:
			dofLoc.x = 9*nodeNum+7;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDZ2:
			dofLoc.x = 9*nodeNum+8;
			dofLoc.y = -1;
			break;
		}
	}
	Constraint(int nodeNum1, int nodeNum2, int constraintType)
	{
		this->nodeNum = nodeNum1;
		this->nodeNum2 = nodeNum2;
		this->constraintType = constraintType;

		switch (constraintType)
		{
		case CONSTRAINTABSOLUTEX:
			dofLoc.x = 9*nodeNum;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEY:
			dofLoc.x = 9*nodeNum+1;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEZ:
			dofLoc.x = 9*nodeNum+2;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDX1:
			dofLoc.x = 9*nodeNum+3;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDY1:
			dofLoc.x = 9*nodeNum+4;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDZ1:
			dofLoc.x = 9*nodeNum+5;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDX2:
			dofLoc.x = 9*nodeNum+6;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDY2:
			dofLoc.x = 9*nodeNum+7;
			dofLoc.y = -1;
			break;
		case CONSTRAINTABSOLUTEDZ2:
			dofLoc.x = 9*nodeNum+8;
			dofLoc.y = -1;
			break;
		case CONSTRAINTRELATIVEX:
			dofLoc.x = 9*nodeNum;
			dofLoc.y = 9*nodeNum2;
			break;
		case CONSTRAINTRELATIVEY:
			dofLoc.x = 9*nodeNum+1;
			dofLoc.y = 9*nodeNum2+1;
			break;
		case CONSTRAINTRELATIVEZ:
			dofLoc.x = 9*nodeNum+2;
			dofLoc.y = 9*nodeNum2+2;
			break;
		case CONSTRAINTRELATIVEDX1:
			dofLoc.x = 9*nodeNum+3;
			dofLoc.y = 9*nodeNum2+3;
			break;
		case CONSTRAINTRELATIVEDY1:
			dofLoc.x = 9*nodeNum+4;
			dofLoc.y = 9*nodeNum2+4;
			break;
		case CONSTRAINTRELATIVEDZ1:
			dofLoc.x = 9*nodeNum+5;
			dofLoc.y = 9*nodeNum2+5;
			break;
		case CONSTRAINTRELATIVEDX2:
			dofLoc.x = 9*nodeNum+6;
			dofLoc.y = 9*nodeNum2+6;
			break;
		case CONSTRAINTRELATIVEDY2:
			dofLoc.x = 9*nodeNum+7;
			dofLoc.y = 9*nodeNum2+7;
			break;
		case CONSTRAINTRELATIVEDZ2:
			dofLoc.x = 9*nodeNum+8;
			dofLoc.y = 9*nodeNum2+8;
			break;
		}
	}
};

class Force{
public:
	float3 direction;
	double magnitude;
	int element;
	double2 position;

	Force(int element, double2 position, double magnitude, float3 normal)
	{
		this->element = element;
		this->position = position;
		this->magnitude = magnitude;
		this->direction = normal;
	}
};

class ANCFSystem{
private:

	ofstream posFile;
	ofstream resultsFile1;
	ofstream resultsFile2;
	ofstream resultsFile3;

	//variables
	int timeIndex;
	double time; //current time
	double simTime; //time to end simulation
	double h; //time step

	double alphaHHT;
	double betaHHT;
	double gammaHHT;
	double tol;

	mat p;
	mat v;
	mat a;
	mat pnew;
	mat vnew;
	mat anew;
	mat fext;
	mat fint;
	mat curvat0;
	mat strain0;
	mat fapp;
	mat fcon;
	mat mass;
	mat phi;
	mat phi_o; // initial phi values
	mat phi_q;
	mat lambda;
	mat stiffness;
	mat lhsInv;

	thrust::host_vector<double3> strainDerivative;
	thrust::host_vector<double3> curvatureDerivative;

	thrust::host_vector<double> wt6;
	thrust::host_vector<double> pt6;
	thrust::host_vector<double> wt5;
	thrust::host_vector<double> pt5;

	vector<Constraint> constraints;



public:
	ANCFSystem()
	{
		this->timeIndex=0;
		this->time=0;
		this->h=0.001;
		alphaHHT = -.2;
		betaHHT = 1 - alphaHHT;
		betaHHT = betaHHT*betaHHT*.25;
		gammaHHT = 0.5 - alphaHHT;
		tol = 1e-7;
		groundHeight = -.4;

		wt6.push_back(0.17132449);
		wt6.push_back(0.36076157);
		wt6.push_back(0.46791393);
		wt6.push_back(0.46791393);
		wt6.push_back(0.36076157);
		wt6.push_back(0.17132449);

		pt6.push_back(-0.93246951);
		pt6.push_back(-0.66120939);
		pt6.push_back(-0.23861918);
		pt6.push_back(0.23861918);
		pt6.push_back(0.66120939);
		pt6.push_back(0.93246951);

		wt5.push_back((322. - 13.*sqrt(70.))/900.);
		wt5.push_back((322. + 13.*sqrt(70.))/900.);
		wt5.push_back(128./225.);
		wt5.push_back((322. + 13.*sqrt(70.))/900.);
		wt5.push_back((322. - 13.*sqrt(70.))/900.);

		pt5.push_back(-(sqrt(5. + 2.*sqrt(10./7.)))/3.);
		pt5.push_back(-(sqrt(5. - 2.*sqrt(10./7.)))/3.);
		pt5.push_back(0.);
		pt5.push_back((sqrt(5. - 2.*sqrt(10./7.)))/3.);
		pt5.push_back((sqrt(5.+2.*sqrt(10./7.)))/3.);

		sphere = make_double4(.3,-.5,.3,.4);
		numCollisions = 0;
		numContactPoints = make_int2(5,5);
		coefRestitution = 0;
		frictionCoef = .3;
		timeToSimulate = 0;

		// set up position files
		char filename1[100];
		char filename2[100];
		char filename3[100];
		sprintf(filename1, "position.dat");
		resultsFile1.open(filename1);
		sprintf(filename2, "energy.dat");
		resultsFile2.open(filename2);
		sprintf(filename3, "reactions.dat");
		resultsFile3.open(filename3);

		fileIndex = 0;
	}
	vector<Element> elements;
	vector<Material> materials;
	vector<Force> appliedForces;
	double4 sphere;
	double groundHeight;
	int2 numContactPoints;
	int numCollisions;
	double coefRestitution;
	double frictionCoef;

	double timeToSimulate;
	int fileIndex;

	double getCurrentTime();
	double getSimulationTime();
	double getTimeStep();
	double getTolerance();
	int getTimeIndex();
	int setSimulationTime(double simTime);
	int setTimeStep(double h);
	int setTolerance(double tolerance);
	int addElement(Element& element);
	int DoTimeStep();
	float3 getXYZPosition(int elementIndex, double xi, double eta);
	int calculateInitialPhi();
	int initializeSystem();
	int updateInternalForces(double* position, int elementNum);
	int updatePhiq();
	int updatePhi();
	int updateAppliedForces();
	int detectCollisions();
	int applyContactForce(int elementNum, double xi, double eta, double a, double b, double4 collision);
	int writeToFile();
	int getInitialCurvature();

	int addPointForce(Force force)
	{
		appliedForces.push_back(force);
		return 0;
	}

	int clearAppliedForces()
	{
		ANCFSystem::appliedForces.clear();
		return 0;
	}

//	Node getFirstNode(Element element)
//	{
//		double* ptr = p.memptr();
//		ptr = &ptr[element.getElementIndex()*12];
//		return Node(ptr[0],ptr[1],ptr[2],ptr[3],ptr[4],ptr[5]);
//	}
//
//	Node getLastNode(Element element)
//	{
//		double* ptr = p.memptr();
//		ptr = &ptr[element.getElementIndex()*12+6];
//		return Node(ptr[0],ptr[1],ptr[2],ptr[3],ptr[4],ptr[5]);
//	}

	// constraint code (by node number)
	int addConstraint_AbsoluteX(int nodeNum);
	int addConstraint_AbsoluteY(int nodeNum);
	int addConstraint_AbsoluteZ(int nodeNum);

	int addConstraint_AbsoluteDX1(int nodeNum);
	int addConstraint_AbsoluteDY1(int nodeNum);
	int addConstraint_AbsoluteDZ1(int nodeNum);

	int addConstraint_AbsoluteDX2(int nodeNum);
	int addConstraint_AbsoluteDY2(int nodeNum);
	int addConstraint_AbsoluteDZ2(int nodeNum);

	int addConstraint_RelativeX(int nodeNum1, int nodeNum2);
	int addConstraint_RelativeY(int nodeNum1, int nodeNum2);
	int addConstraint_RelativeZ(int nodeNum1, int nodeNum2);

	int addConstraint_RelativeDX1(int nodeNum1, int nodeNum2);
	int addConstraint_RelativeDY1(int nodeNum1, int nodeNum2);
	int addConstraint_RelativeDZ1(int nodeNum1, int nodeNum2);

	int addConstraint_RelativeDX2(int nodeNum1, int nodeNum2);
	int addConstraint_RelativeDY2(int nodeNum1, int nodeNum2);
	int addConstraint_RelativeDZ2(int nodeNum1, int nodeNum2);

	int addConstraint_AbsoluteFixed(int nodeNum);
	int addConstraint_RelativeFixed(int nodeNum1,int nodeNum2);
	int addConstraint_AbsoluteSpherical(int nodeNum);
	int addConstraint_RelativeSpherical(int nodeNum1, int nodeNum2);

	// constraint code (by element)
	int addConstraint_AbsoluteX(Element& element, int node_local);
	int addConstraint_AbsoluteY(Element& element, int node_local);
	int addConstraint_AbsoluteZ(Element& element, int node_local);

	int addConstraint_AbsoluteDX1(Element& element, int node_local);
	int addConstraint_AbsoluteDY1(Element& element, int node_local);
	int addConstraint_AbsoluteDZ1(Element& element, int node_local);

	int addConstraint_AbsoluteDX2(Element& element, int node_local);
	int addConstraint_AbsoluteDY2(Element& element, int node_local);
	int addConstraint_AbsoluteDZ2(Element& element, int node_local);

	int addConstraint_RelativeX(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeY(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeZ(Element& element1, int node_local1, Element& element2, int node_local2);

	int addConstraint_RelativeDX1(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeDY1(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeDZ1(Element& element1, int node_local1, Element& element2, int node_local2);

	int addConstraint_RelativeDX2(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeDY2(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeDZ2(Element& element1, int node_local1, Element& element2, int node_local2);

	int addConstraint_AbsoluteFixed(Element& element, int node_local);
	int addConstraint_AbsoluteSpherical(Element& element, int node_local);
	int addConstraint_RelativeFixed(Element& element1, int node_local1, Element& element2, int node_local2);
	int addConstraint_RelativeSpherical(Element& element1, int node_local1, Element& element2, int node_local2);
};

#endif
