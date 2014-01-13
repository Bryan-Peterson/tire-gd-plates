#include "include.h"

int ancf_shape_derivative_x(double* Sx, double x, double y, double a, double b)
{
	Sx[0] = - (y / b - 1) / a * ( (2 * y * y *  pow( b,  (-2))) -  (y / b) + 0.2e1 * x * x * pow(a, -0.2e1) - x / a - 0.1e1 + (x / a - 0.1e1) * (0.4e1 * x / a - 0.1e1));
	Sx[1] = - (y / b - 1) * (pow(x / a - 0.1e1, 0.2e1) + 0.2e1 * x / a * (x / a - 0.1e1));
	Sx[2] = - y *   pow( (y / b - 1),  2) / a;
	Sx[3] =  (y / b - 1) / a * ( (2 * y * y *  pow( b,  (-2))) -  (y / b) + 0.2e1 * x * x * pow(a, -0.2e1) - 0.3e1 * x / a + x / a * (0.4e1 * x / a - 0.3e1));
	Sx[4] = - (y / b - 1) * (0.2e1 * x / a * (x / a - 0.1e1) + x * x * pow(a, -0.2e1));
	Sx[5] =  y *   pow( (y / b - 1),  2) / a;
	Sx[6] = - y /  b / a * (0.1e1 - 0.3e1 * x / a -  (3 * y / b) +  (2 * y * y *  pow( b,  (-2))) + 0.2e1 * x * x * pow(a, -0.2e1) + x / a * (0.4e1 * x / a - 0.3e1));
	Sx[7] =  y /  b * (0.2e1 * x / a * (x / a - 0.1e1) + x * x * pow(a, -0.2e1));
	Sx[8] = 0.1e1 /  b *  (y * y) *  (y / b - 1) / a;
	Sx[9] =  y /  b / a * (0.2e1 * x * x * pow(a, -0.2e1) - x / a -  (3 * y / b) +  (2 * y * y *  pow( b,  (-2))) + (x / a - 0.1e1) * (0.4e1 * x / a - 0.1e1));
	Sx[10] =  y /  b * (pow(x / a - 0.1e1, 0.2e1) + 0.2e1 * x / a * (x / a - 0.1e1));
	Sx[11] = -0.1e1 /  b *  (y * y) *  (y / b - 1) / a;

	return 0;
}
int ancf_shape_derivative_y(double* Sy, double x, double y, double a, double b)
{
	Sy[0] = (x / a - 1) * (6 * y / b - 6 * y * y *  pow( b,  (-2)) - 2 * x * x *  pow( a,  (-2)) + x / a) / b;
	Sy[1] = -x *  pow( (x / a - 1),  2) / b;
	Sy[2] = -(3 * y / b - 1) * (y / b - 1) * (x / a - 1);
	Sy[3] = x / a * (6 * y * y *  pow( b,  (-2)) - 6 * y / b + 2 * x * x *  pow( a,  (-2)) - 3 * x / a + 1) / b;
	Sy[4] = -1 / a * x * x * (x / a - 1) / b;
	Sy[5] = x / a * (3 * y / b - 1) * (y / b - 1);
	Sy[6] = -x / a * (6 * y * y *  pow( b,  (-2)) - 6 * y / b + 2 * x * x *  pow( a,  (-2)) - 3 * x / a + 1) / b;
	Sy[7] = 1 / a * x * x * (x / a - 1) / b;
	Sy[8] = y / b * x / a * (3 * y / b - 2);
	Sy[9] = -(x / a - 1) * (6 * y / b - 6 * y * y *  pow( b,  (-2)) - 2 * x * x *  pow( a,  (-2)) + x / a) / b;
	Sy[10] = x *  pow( (x / a - 1),  2) / b;
	Sy[11] = -y / b * (3 * y / b - 2) * (x / a - 1);

	return 0;
}
int ancf_shape_derivative2_x(double* Sxx, double x, double y, double a, double b)
{
	Sxx[0] = -6 * (2 * x / a - 1) * (y / b - 1) *  pow( a,  (-2));
	Sxx[1] = -2 * (3 * x / a - 2) * (y / b - 1) / a;
	Sxx[2] = 0;
	Sxx[3] = 6 * (2 * x / a - 1) * (y / b - 1) *  pow( a,  (-2));
	Sxx[4] = -2 * (3 * x / a - 1) * (y / b - 1) / a;
	Sxx[5] = 0;
	Sxx[6] = -6 * y / b * (2 * x / a - 1) *  pow( a,  (-2));
	Sxx[7] = 2 * y / b * (3 * x / a - 1) / a;
	Sxx[8] = 0;
	Sxx[9] = 6 * y / b * (2 * x / a - 1) *  pow( a,  (-2));
	Sxx[10] = 2 * y / b * (3 * x / a - 2) / a;
	Sxx[11] = 0;

	return 0;
}
int ancf_shape_derivative2_y(double* Syy, double x, double y, double a, double b)
{
	Syy[0] = -6 * (-x + a) / a * (b - 2 * y) *  pow( b,  (-3));
	Syy[1] = 0;
	Syy[2] = -2 * (-3 * y + 2 * b) * (-x + a) *  pow( b,  (-2)) / a;
	Syy[3] = -6 * x / a * (b - 2 * y) *  pow( b,  (-3));
	Syy[4] = 0;
	Syy[5] = -2 * x * (-3 * y + 2 * b) *  pow( b,  (-2)) / a;
	Syy[6] = 6 * x / a * (b - 2 * y) *  pow( b,  (-3));
	Syy[7] = 0;
	Syy[8] = -2 * x * (-3 * y + b) *  pow( b,  (-2)) / a;
	Syy[9] = 6 * (-x + a) / a * (b - 2 * y) *  pow( b,  (-3));
	Syy[10] = 0;
	Syy[11] = -2 * (-3 * y + b) * (-x + a) *  pow( b,  (-2)) / a;

	return 0;
}

mat expandShape(mat Sx)
{
	mat ID = eye(3,3);
	Sx = trans(Sx);
	return join_rows(join_rows(join_rows(join_rows(join_rows(join_rows(join_rows(join_rows(join_rows(join_rows(join_rows(Sx(0,0)*ID,Sx(1,0)*ID),Sx(2,0)*ID),Sx(3,0)*ID),Sx(4,0)*ID),Sx(5,0)*ID),Sx(6,0)*ID),Sx(7,0)*ID),Sx(8,0)*ID),Sx(9,0)*ID),Sx(10,0)*ID),Sx(11,0)*ID);
}

mat strainDerivativeUpdate(double x, double y, double a, double b, double* p, mat& strainD)
{
	mat Sx = zeros(1,12);
	mat Sy = zeros(1,12);
	ancf_shape_derivative_x(Sx.memptr(),x,y,a,b);
	ancf_shape_derivative_y(Sy.memptr(),x,y,a,b);

	mat Sdx = expandShape(Sx);
	mat Sdy = expandShape(Sy);

	mat d = zeros(12,3);
	int k = 0;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<3;j++)
		{
			d(i,j) = p[k];
			k++;
		}
	}

	mat strain = zeros(3,1);
	mat blah = .5*(Sx*(d*trans(d))*trans(Sx)-1.);
	strain(0,0) = blah(0,0);
	blah = .5*(Sy*(d*trans(d))*trans(Sy)-1.);
	strain(1,0) = blah(0,0);
	blah = (Sx*(d*trans(d))*trans(Sy));
	strain(2,0) = blah(0,0);

	strainD.row(0) = Sx*d*Sdx;
	strainD.row(1) = Sy*d*Sdy;
	strainD.row(2) = Sx*d*Sdy + Sy*d*Sdx;

	return strain;
}

mat cross2(mat m1, mat m2)
{
	mat m3 = zeros(3,36);
	for(int i=0;i<36;i++)
	{
		m3.col(i) = cross(m1.col(i),m2.col(i));
	}
	return m3;
}

mat curvatDerivUpdate(double x, double y, double a, double b, double* p, mat& ke)
{
	mat Sx = zeros(1,12);
	mat Sy = zeros(1,12);
	mat Sxx = zeros(1,12);
	mat Syy = zeros(1,12);

	ancf_shape_derivative_x(Sx.memptr(),x,y,a,b);
	ancf_shape_derivative_y(Sy.memptr(),x,y,a,b);
	ancf_shape_derivative2_x(Sxx.memptr(),x,y,a,b);
	ancf_shape_derivative2_y(Syy.memptr(),x,y,a,b);
	mat Sxy = Syy;

	mat Sdx = expandShape(Sx);
	mat Sdy = expandShape(Sy);
	mat Sdxx = expandShape(Sxx);
	mat Sdyy = expandShape(Syy);
	mat Sdxy = expandShape(Sxy);

	mat d = zeros(12,3);
	int count = 0;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<3;j++)
		{
			d(i,j) = p[count];
			count++;
		}
	}

	mat k = zeros(3,1);

	mat r_x = trans(d)*trans(Sx);
	mat r_xx = trans(d)*trans(Sxx);
	mat r_y = trans(d)*trans(Sy);
	mat r_yy = trans(d)*trans(Syy);
	mat r_xy = trans(d)*trans(Sxy);

	mat f = cross(r_x,r_y);
	double nf = norm(f,2);
	double g = nf*nf*nf;
	mat nn = f/g;

	mat blah = trans(r_xx)*nn;
	k(0,0) = blah(0,0);
	blah = trans(r_yy)*nn;
	k(1,0) = blah(0,0);
	blah = 2*(trans(r_xy)*nn);
	k(2,0) = blah(0,0);

	mat r_yrep = r_y*ones(1,36);
	mat r_xrep = r_x*ones(1,36);

	mat f_e = cross2(Sdx,r_yrep)+cross2(r_xrep,Sdy);
	mat g_e = 3*nf*trans(f)*f_e;
	mat nn_e = (g*f_e-f*g_e)/(g*g);

	ke.row(0) = trans(r_xx)*nn_e+trans(nn)*Sdxx;
	ke.row(1) = trans(r_yy)*nn_e+trans(nn)*Sdyy;
	ke.row(2) = 2*(trans(r_xy)*nn_e+trans(nn)*Sdxy);

	return k;
}

int ANCFSystem::getInitialCurvature()
{
	double x = 0;
	double y = 0;
	mat strain = zeros(3,1);
	mat curvat = zeros(3,1);

	mat strainD = zeros(3,36);
	mat ke = zeros(3,36);
	mat fint1;
	mat fint2;

	double* pAll = p.memptr();
	double* p;

	double th;
	double E;
	double a;
	double b;
	double nu;

	for(int i=0;i<ANCFSystem::elements.size();i++)
	{
		p = &pAll[36*i];

		E = elements[i].getElasticModulus();
		a = elements[i].getLength_l();
		b = elements[i].getLength_b();
		nu = elements[i].getNu();

		mat E_eps = eye(3,3);
		E_eps(0,1) = nu;
		E_eps(1,0) = nu;
		E_eps(2,2) = .5*(1-nu);
		E_eps = E_eps*E/(1-nu*nu);

		int count = 0;
		for(int j=0;j<pt6.size();j++)
		{
			x = .5*a*(1.+pt6[j]);
			for(int k=0;k<wt6.size();k++)
			{
				y = .5*b*(1.+pt6[k]);
				strain = strainDerivativeUpdate(x,y,a,b,p,strainD);
				strain0.col(36*i+count) = strain;
				count++;
			}
		}

		count = 0;
		for(int j=0;j<pt5.size();j++)
		{
			x = .5*a*(1.+pt5[j]);
			for(int k=0;k<wt5.size();k++)
			{
				y = .5*b*(1.+pt5[k]);
				curvat = curvatDerivUpdate(x,y,a,b,p,ke);
				curvat0.col(25*i+count) = curvat;
				count++;
			}
		}
	}

	return 0;
}

int ANCFSystem::updateInternalForces(double* pAll, int elementNum)
{
	int i = elementNum;
	double x = 0;
	double y = 0;
	mat strain = zeros(3,1);
	mat curvat = zeros(3,1);

	double* intForceAll = ANCFSystem::fint.memptr();

	mat strainD = zeros(3,36);
	mat ke = zeros(3,36);
	mat fint1;
	mat fint2;

	double* intForce;
	double* p;

	double th;
	double E;
	double a;
	double b;
	double nu;

	//for(int i=0;i<36;i++) pAll[i] = 1;

	//stiffness = zeros(36*elements.size(),36*elements.size());

	mat stiffnessEl1 = zeros(36,36);
	mat stiffnessEl2 = zeros(36,36);

//#pragma omp parallel for
	//for(int i=0;i<ANCFSystem::elements.size();i++)
	//{

		intForce = &intForceAll[36*i];
		p = &pAll[36*i];

		th = elements[i].getThickness();
		E = elements[i].getElasticModulus();
		a = elements[i].getLength_l();
		b = elements[i].getLength_b();
		nu = elements[i].getNu();

		mat E_eps = eye(3,3);
		E_eps(0,1) = nu;
		E_eps(1,0) = nu;
		E_eps(2,2) = .5*(1-nu);
		E_eps = E_eps*E/(1-nu*nu);

		fint1 = zeros(36,1);
		fint2 = zeros(36,1);

		int count = 0;
		for(int j=0;j<pt6.size();j++)
		{
			x = .5*a*(1.+pt6[j]);
			for(int k=0;k<wt6.size();k++)
			{
				y = .5*b*(1.+pt6[k]);
				strain = strainDerivativeUpdate(x,y,a,b,p,strainD);
				//addStiffness(i,stiffness,wt6[j]*wt6[k]*a*b*th*.25*E/(1-nu*nu),strainD,nu);
				stiffnessEl1 += trans(strainD)*E_eps*strainD*wt6[j]*wt6[k];
				fint1 += (trans(strainD)*E_eps*(strain-strain0.col(36*i+count)))*wt6[j]*wt6[k];
				count++;
			}
		}
		fint1 = fint1*a*.5*b*.5*th;
		stiffnessEl1 = stiffnessEl1*a*.5*b*.5*th;

		count = 0;
		for(int j=0;j<pt5.size();j++)
		{
			x = .5*a*(1.+pt5[j]);
			for(int k=0;k<wt5.size();k++)
			{
				y = .5*b*(1.+pt5[k]);
				curvat = curvatDerivUpdate(x,y,a,b,p,ke);
				//addStiffness(i,stiffness,wt5[j]*wt5[k]*a*b*pow(th,3)*.25*E/(1-nu*nu),strainD,nu);
				stiffnessEl2 += trans(ke)*E_eps*ke*wt5[j]*wt5[k];
				fint2 += (trans(ke)*E_eps*(curvat-curvat0.col(25*i+count)))*wt5[j]*wt5[k];
				count++;
			}
		}
		fint2 = fint2*a*.5*b*.5*th*th*th/12.0;
		stiffnessEl2 = stiffnessEl2*a*.5*b*.5*th*th*th/12.0;

		for(int j=0;j<36;j++) intForce[j] = fint1[j]+fint2[j];
		stiffness.submat(36*i,36*i,36*i+35,36*i+35)=stiffnessEl1+stiffnessEl2;
		stiffnessEl1 = zeros(36,36);
		stiffnessEl2 = zeros(36,36);
	//}

	return 0;
}
