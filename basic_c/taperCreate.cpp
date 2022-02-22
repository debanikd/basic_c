#include <iostream>
using namespace std;

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <string>

//typedef Matrix<VectorXcd, Dynamic, 1> DistXcd;
int main() {

	cout << "taper profile for acoustic blackhole"<< endl;

	double latticeA;
	double height;
	double residual_height;
	double taper_radius;

	double epsilon, m;
	double x, function;

	int numPoints= 101;

	double xStart, xEnd, xIncrement;

	latticeA= 0.14;
	height= 0.008;
	residual_height=0.0011;
	taper_radius= 0.05;

	epsilon= 5.0;
	m= 2.2;

	xStart= 0.0;
	xEnd= taper_radius;


	xIncrement = (xEnd-xStart)/double(numPoints-1);
	cout << "the increment is "<< xIncrement<< endl;


	char outbuffer[200];
	sprintf( outbuffer ,"taperprofile.csv"); //opens and writes on the file eig.out	
	ofstream foutF(outbuffer);// for output

	foutF<< "#========================================================= " << endl; 
	foutF<< "#taperprofile"<< endl;
	foutF<< "#========================================================= " << endl; 
	for(int i=0; i< numPoints; i++ )
	{
		x= xStart+ xIncrement* i;
		function= residual_height + epsilon * pow(x, m);

		cout << x + latticeA/2.0<< "\t"<< function<< endl;
		foutF<< x+ latticeA/2.0<< ","<< function<< endl;


	}




	//==============================================================================================
	foutF.close();
	//==============================================================================================
	//==============================
	//==============================
	//==============================
	//==============================
	//==============================
	//==============================




}
