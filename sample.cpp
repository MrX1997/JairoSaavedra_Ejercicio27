#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#define PI 3.141592653589793
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits>
using namespace std;
static const double epsilon = std::numeric_limits<double>::min();
void i1(double *u,int n,double mu,double sigma);
void i2(double *u,int n,double mu,double sigma);
void i3(double *u,int n,double mu,double sigma);
void i4(double *u,int n,double mu,double sigma);
double _rn(void);
double gg(double mu, double sigma);
time_t t;


int main (int argc, char *argv[] )
{
	if( argc != 4 ) 
	{
		cout << "La entrada debe ser de la forma N mu sigma\n", argv[0];
		exit(0);
  }
  int N = atoi(argv[1]);
	int mu = atoi(argv[2]);
	int sigma = atoi(argv[3]);
  srand((unsigned) time(&t));
	double n1[N]={};
	double n2[N]={};
	double n3[N]={};
	double n4[N]={};
	ofstream myfile ("sample.dat");

	int i;
	for(i=0;i<N+1;i++)
	{
		
		n1[i]=gg(mu,sigma);
		n2[i]=gg(mu,sigma);	
		n3[i]=gg(mu,sigma);
		n4[i]=gg(mu,sigma);	
  }
  i1(n1,N,mu,sigma);
  i2(n2,N,mu,sigma);
  i3(n3,N,mu,sigma);
  i4(n4,N,mu,sigma);
  return 0;
}
double _rn(void)
{
    return (double) rand()/(RAND_MAX*1.0);
}


void i1(double *u,int n,double mu,double sigma)
{
	ofstream myfile ("sample_1.dat");
  if (myfile.is_open())
  {
		int i;
		for(i=0;i<n+1;i++)
		{
			myfile << u[i] << '\n';
		}
    myfile.close();
  }
  else cout << "Unable to open file";
}
void i2(double *u,int n,double mu,double sigma)
{
	ofstream myfile ("sample_2.dat");
  if (myfile.is_open())
  {
		int i;
		for(i=0;i<n+1;i++)
		{
			myfile << u[i] << '\n';
		}
    myfile.close();
  }
  else cout << "Unable to open file";
}
void i3(double *u,int n,double mu,double sigma)
{
	ofstream myfile ("sample_3.dat");
  if (myfile.is_open())
  {
		int i;
		for(i=0;i<n+1;i++)
		{
			myfile << u[i] << '\n';
		}
    myfile.close();
  }
  else cout << "Unable to open file";
}
void i4(double *u,int n,double mu,double sigma)
{
	ofstream myfile ("sample_4.dat");
  if (myfile.is_open())
  {
		int i;
		for(i=0;i<n+1;i++)
		{
			myfile << u[i] << '\n';
		}
    myfile.close();
  }
  else cout << "Unable to open file";
}

double gg(double mu, double sigma)
{
	static const double epsilon = std::numeric_limits<double>::min();
	static const double two_pi = 2.0*3.14159265358979323846;

	thread_local double z1;
	thread_local bool generate;
	generate = !generate;

	if (!generate)
	   return z1 * sigma + mu;

	double u1, u2;
	do
	 {
	   u1 = _rn();
	   u2 = _rn();
	 }
	while ( u1 <= epsilon );

	double z0;
	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	return z0 * sigma + mu;
}
