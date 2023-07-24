#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <any>

class Vars {
public:
    //Add a variable to the registry.
    template <typename T>
    void add(const std::string& name, const T& value) {
        var_[name] = value;
    }

    //Get the specified type and name
    template <typename T>
    T get(const std::string& name) const {
        auto it = var_.find(name);
        if (it != var_.end()) {
            //"it" points to name
            return std::any_cast<T>(it->second);
        }
        else {
            std::cerr << "Error: Variable not found - " << name << std::endl;
            throw std::runtime_error("Variable not found");
        }
    }

private:
    std::map<std::string, std::any> var_;
};


int main() {
    
    Vars vars;
    vars.add<float>("weight", 3.4);
    vars.add<int>("number", 9);
    vars.add<std::string>("string", "Have");

    int* ptr = new int(42);
    vars.add<int*>("ptr_var", ptr);
 


    std::cout << "Weight: " << vars.get<float>("weight") << std::endl;
    std::cout << "Number: " << vars.get<int>("number") << std::endl;
    std::cout << "String: " << vars.get<std::string>("string") << std::endl;
    std::cout << "String: " << *vars.get<int*>("ptr_var") << std::endl;

    return 0;
}
