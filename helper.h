#include <iostream>
#include <cmath>
#include <stdlib.h>

struct values{
	float L;
	float W;
	float Lq;
	float Wq;
	float p;
	float p0;
};
typedef struct values values_t;

class Helper{
	public:
	static values_t* MM1(float l, float u){
		values_t * v = (values_t*)malloc(sizeof(values_t));
		v->L = l/(u-l);
		v->W = 1/(u-l);
		v->Lq = (l*l)/(u*(u-l));
		v->Wq = l/(u*(u-l));
		v->p = l/u;
		v->p0 = 1-(l/u);
	}

	static values_t* MMm(float l, float u, int m){
		values_t * v = (values_t*)malloc(sizeof(values_t));
		float sum = 0;
		for(int i = 0; i < m; ++i)
			sum += (1/(float)factorial(i))*pow(l/u, i);
		v->p0 = 1/(sum+(1/(float)factorial(m))*pow(l/u, m)*(m*u/(m*u - l)));
		v->L = ((l*u*pow(l/u, m))/((float)factorial(m-1)*(m*u -l)*(m*u - l)))*v->p0 + (l/u);
		v->W = v->L/l;
		v->Lq = v->L-(l/u);
		v->Wq = (v->Lq/l);
		v->p = l/(m*u);
	}

	static int factorial(int n){
		return (n > 1)? n*factorial(n-1) : 1;
	}

	static void printValues(values_t* v){
		std::cout << "L = " << v->L << "; W = " << v->W << "; Lq = " << v->Lq << "; Wq = " << v->Wq << "; p = " << v->p << "; p0 = " << v->p0 << std::endl;
	}
};