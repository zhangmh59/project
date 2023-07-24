#include<iostream>

//2 lambdas
auto add = [](float a, float b) {return a + b;};
auto mul = [](float a, float b) {return a * b;};

//function pointer type
using FCE = float(*)(float, float);


void fce(FCE f, float a, float b) {
	std::cerr << "fce: " << f(a, b) << std::endl;
};

int main(int argc, char* argv[]) {

	fce(add, 10, 20);
	fce(mul, 10, 20);
	return 0;
}