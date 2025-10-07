#include "task_scheduler.h"
#include "command.h"
#include "earliest_time.h"
#include <iostream>
#include <thread>
#include <chrono>

class PrintCommand : public Command {
    std::string msg;
public:
    PrintCommand(std::string m) : msg(m) {}
    void execute() override {
        std::cout << msg << " at " << std::chrono::steady_clock::now().time_since_epoch().count() << std::endl;
    }
};

int main() {
    TaskScheduler scheduler(2);
    auto cmd1 = std::make_shared<PrintCommand>("Task 1 executed");
    auto cmd2 = std::make_shared<PrintCommand>("Task 2 executed");
    auto cmd3 = std::make_shared<PrintCommand>("Task 3 executed");
    int id1 = scheduler.schedule(cmd1, std::chrono::seconds(1));
    int id2 = scheduler.schedule(cmd2, std::chrono::seconds(2));
    int id3 = scheduler.schedule(cmd3, std::chrono::seconds(3));
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    scheduler.cancel(id2);  // cancel task 2
    std::this_thread::sleep_for(std::chrono::seconds(3));
    scheduler.shutdown();
    std::cout << "Scheduler shut down." << std::endl;

    // Test earliestFinishTime
    std::cout << "\nTesting earliestFinishTime function:\n";
    // Test 1: Multiple workers varying availability
    std::vector<Worker> workers1 = {{0, 5}, {2, 3}, {4, 2}};
    std::cout << "Test 1 (varying): " << earliestFinishTime(workers1) << " (expected 5)\n";
    // Test 2: All available same time
    std::vector<Worker> workers2 = {{0, 5}, {0, 3}};
    std::cout << "Test 2 (same time): " << earliestFinishTime(workers2) << " (expected 3)\n";
    // Test 3: One worker
    std::vector<Worker> workers3 = {{1, 2}};
    std::cout << "Test 3 (one worker): " << earliestFinishTime(workers3) << " (expected 3)\n";
    // Test 4: Empty
    std::vector<Worker> workers4 = {};
    std::cout << "Test 4 (empty): " << earliestFinishTime(workers4) << " (expected -1)\n";
    // Test 5: Negative
    std::vector<Worker> workers5 = {{-1, 3}, {0, 2}};
    std::cout << "Test 5 (negative): " << earliestFinishTime(workers5) << " (expected 2)\n";

    return 0;
}
