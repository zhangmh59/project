#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#include<chrono>


//Task 1: Write function that can receive lambda by parameter, execute the lambda and measure the execution time
template<typename F>
void measureTime(F func) {
	auto startTime = std::chrono::steady_clock::now();
	func(10, 20);
	auto endTime = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

	std::cout << "The execution time of task 1 is： " << duration << std::endl;
}


//Task 2: Write recursive lambda (lambda that calls itself)
std::function<int(int, int)> func_task2 = [](int a, int b) {

	if (a <= 0 || b <= 0) return 0;  
	
	std::cout << "Here is the output of task 2" << std::endl;
	std::cout << "a =: " << a << std::endl;
	std::cout << "b =: " << b << std::endl;
	std::cout << "The output of task 2: " << a * b << std::endl;

	return func_task2(a - 1, b - 1);
};

//Task 3: write lambda that return lambda
auto func_task3 = [](int a) {
	return [a](int b) {return a * b;};
};



int main(){

	
	//1.the first case
	std::function<int(int)> func = [](int x)->int{
		return ++x;
	};
	
	for (int i = 0; i < 10; i++){
		std::cout << "basic case: " << func(i) << std::endl;
	}

	//2. the simpler case to realize same effect as the above code
	auto func1 = [](int x) {return ++x;};

	for (int i = 0; i < 10; i++) {
		std::cout << "simpler case: " << func1(i) << std::endl;
	}


	//3. lamebda function [], [=], [&]
	int multiplier = 2;
	std::vector<int>arr = {1, 3, 5, 7, 9};

	std::for_each(arr.begin(), arr.end(), [](int x) {std::cout << "x: " << x << std::endl;});

	// We just copy the value of outer variant, but we can't modify the value of captured varient
	std::for_each(arr.begin(), arr.end(), [=](int x) {std::cout << "x * multiplier: " << x * multiplier << std::endl;});

	//In this case, we can modify the value of captured varient
	std::for_each(arr.begin(), arr.end(), [&](int x) {
		multiplier++;
		std::cout << "x * (multiplier++): " << x * multiplier<< std::endl;
	});

	
	measureTime([](float a, float b) {std::cout << "The output from lambda function: " << a + b << std::endl;});
	func_task2(3, 2);

	auto lambda3 = func_task3(5);
	std::cout << "The output of lambda3 is: " << lambda3(9) << std::endl;



	//Task 4: Write command list (vector of std::function of lambdas)


	
}
