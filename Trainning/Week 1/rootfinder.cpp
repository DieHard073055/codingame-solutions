#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;


inline double fcn(double x){return x * x - 1;}
inline double fcn2(double x){return x * x * x * x * x - exp( x ) - 2;}

double root_find(
    double f(double),
    double a, double b,
    double eps,
    double *root
){
    if( b -a < eps){
        *root = b(b + a) / 2.0;
        return f(*root);
    }
    else{
        if(f(a) * f((b + a)/2) <= 0)
            return root_find(f, a, (b+a)/2, esp, root);
            
        else
            return root_find(f, (b+a)/2, b, eps, root);
    }
}
int main(void){
    double x;
    
    root_find(fcn, 0.0, 4.0, 0.00001, &x);
    cout << "\n\tRoot Finder" << endl
        << "root is at " << static_cast<double>(x) << "with residual " << static_cast<double>(fcn(x)) << endl;
    
    root_find(fcn2, 0.0, 14.0, 0.00001, &x);
    cout << "Root is at " << static_cast<double>(x) << endl;
    
       
    return 0;
}


/*

    main()
    
    double x;
	
	printf("Root Finder\n");
	root_find(fcn, 0.0, 4.0, 0.00001, &x);
	printf("root is at %g with residual %g \n", x, fcn(x));
	root_find(fcn2, 0.0, 14.0, 0.00001, &x);
	printf("root is at %g\n", x);
	
    ---- Required Output ---
    
    Root Finder
    root is at 0.999996 with residual -7.62938e-06 
    root is at 1.44167

*/
