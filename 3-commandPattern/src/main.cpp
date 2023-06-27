#include <iostream>
#include <string>
#include <vector>

// Command（命令）接口
class Command {
public:
    virtual void execute() = 0;
};

// ConcreteCommand（具体命令）类
class ConcreteCommand : public Command {
private:
    std::string message;

public:
    ConcreteCommand(const std::string& msg) : message(msg) {}

    void execute() override {
        std::cout << "Execute command: " << message << std::endl;
        // 在这里执行实际的操作
    }
};

// Receiver（接收者）类
class Receiver {
public:
    void performAction() {
        std::cout << "Action performed by receiver" << std::endl;
        // 实际的业务逻辑在这里执行
    }
};

// Invoker（调用者）类
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* cmd) {
        commands.push_back(cmd);
    }

    void executeCommands() {
        for (Command* cmd : commands) {
            cmd->execute();
        }
        commands.clear();
    }
};

int main() {
    // 创建接收者对象
    Receiver receiver;

    // 创建具体命令对象
    Command* command1 = new ConcreteCommand("Command 1");
    Command* command2 = new ConcreteCommand("Command 2");
    Command* command3 = new ConcreteCommand("Command 3");

    // 创建调用者对象，并添加命令
    Invoker invoker;
    invoker.addCommand(command1);
    invoker.addCommand(command2);
    invoker.addCommand(command3);

    // 执行命令
    invoker.executeCommands();

    // 释放内存
    delete command1;
    delete command2;
    delete command3;

    return 0;
}
