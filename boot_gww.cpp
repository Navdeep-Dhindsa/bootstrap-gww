#include <iostream>
#include <fstream>
using namespace std;
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <complex>

extern "C" void zgeev_ (char *, char *, int *, double at[], int *, double b[],
			double dummy[], int *, double dummy2[], int *,
			double work[], int *, double work2[], int *);

int
main ()
{

  int N = 9, signal;
  int SWEEPS = 2000000;
  double rand_num;
  srand(time(0));

  ofstream f_data;
  f_data.open ("data.txt");

  complex <double >Eig[N];
  double Elm[2 * N * N], cc[4 * N * N], dd[2], E[2 * N], X[2 * N];
  char nn = 'N';
  int c1 = N, c2 = 2 * N, c3 = 1, k, i, j;
  double count = 0.5, lambda;

  for (int sim = 0; sim < SWEEPS; sim++)
    {
      rand_num = 0.25 + ((double) rand()/RAND_MAX) * 0.75;
      lambda = ((double) rand()/RAND_MAX) * 2.0;
      
      X[0] = 1.0;
      X[1] = rand_num;
      X[2] = X[0] - 2 * lambda * X[1];

      for (i = 2; i < N; i++)
	{
	  X[i + 1] = X[i-1] - 2 * lambda * X[i];
	  for (k = 1; k < i; k++){
	  X[i+1] -= 2 * lambda * X[k] * X[i-k];   
	  }
	}

      for (i = 0; i < N; i++)
	{
	  for (j = 0; j < N; j++)
	    {
	      if(i == j){Elm[2 * (N * i + j)] = X[0];} 
	      if(i > j){Elm[2 * (N * i + j)] = X[i - j];}
	      if(j > i){Elm[2 * (N * i + j)] = X[j - i];}
	      Elm[2 * (N * i + j) + 1] = 0;
	    }
	}

      zgeev_ (&nn, &nn, &c1, Elm, &c1, E, dd, &c3, dd, &c3, cc, &c2, cc, &k);
      // Arguments in this LAPACK routine not nicely defined, will be updated. 

      signal = 1;
      for (j = 0; j < N; j++)
	{
	  Eig[j] = complex <double >(E[2 * j], E[2 * j + 1]);
	  if (E[2 * j + 1]  > 0.00001)
	    {
	      cout << "Caution " << endl;
	    }
	  if (E[2 * j] < 0)
	    {
	      signal = 0;
	    }
	}
      f_data << rand_num << "  " << lambda;
    /*  for (j = 0; j < N; j++)
	{
	  f_data << "  " << Eig[j];
	} */
      f_data << "  " << signal << endl;
    }

}
