#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;

double gen_rand(int min, int max)
{
	return (min + static_cast <double> (rand()) /
		( static_cast <double> (RAND_MAX/(max-min))));
}

void gen_numbers(double numbers[], int how_many)
{
	for (int i = 0; i < how_many; i++)
	{
		numbers[i] = gen_rand(0, 10);
	}
}

double serial_sum(double numbers[], int total_numbers)
{
	double sum = 0.0;
	for(int i = 0; i < total_numbers; i++)
	{
		sum += numbers[i];
	}
	return sum;
}

int main()
{
    int NSIZE  = 10000;
    double* numbers= new double[NSIZE];
    gen_numbers(numbers, NSIZE);
    cout<<"Computation started.."<<endl;
	  auto start = chrono::steady_clock::now();
    
    double sum = serial_sum(numbers, NSIZE);
	
    auto end = chrono::steady_clock::now();
    double compute_time = chrono::duration<double>(end - start).count();
    cout<<"sum = " << sum <<endl;
    cout<<"Computation time = " << compute_time << " seconds"<<endl;
    return 0;
}
