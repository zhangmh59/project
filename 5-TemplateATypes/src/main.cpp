#include <iostream>
#include <string_view>
#include <typeinfo> 

//Task 1: Write function that takes any number of parameters and prints the count of the parameters
// overloading
void printParaCount(){
	std::cout << "Number of parameters: 0" << std::endl;
}

template<typename T, typename... Args>
void printParaCount(const T& firstArgs, const Args&... args){
	std::cout << "Number of parameters: " << sizeof...(Args) + 1 << std::endl; 
}

//Task 2: write function that nicely converts template types to “strings" and print the string
//primary template
template <typename T>
constexpr std::string_view TypeToString(){
	return "unknown";
}

//specification for some common types
template<>
constexpr std::string_view TypeToString<int>() {
	return "int";
}

template <>
constexpr std::string_view TypeToString<double>() {
	return "double";
}

template <>
constexpr std::string_view TypeToString<std::string>() {
	return "string";
}

template <>
constexpr std::string_view TypeToString<int32_t[1][2][3]>() {
	return "int32_t[1][2][3]";
}

// Function to print the type as string
template <typename T>
void printTypeAsString() {
	std::cout << TypeToString<T>() << std::endl;
}

// another way to complete Task 2
template <typename T>
std::string printType() {
	return typeid(T).name();
}




int main(){

	printParaCount(1, 2, 3);
	printParaCount("Have", "a", "nice", "day", "!");

	printTypeAsString<int>();          // Output: int
	printTypeAsString<double>();       // Output: double
	printTypeAsString<std::string>();  // Output: string
	printTypeAsString<int32_t[1][2][3]>();  // Output: int32_t[1][2][3]

	std::cout << printType<std::string>() << std::endl;  // print std::string


	return 0;
}

