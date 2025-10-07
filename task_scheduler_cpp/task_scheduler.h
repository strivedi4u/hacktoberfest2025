#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <memory>
#include <atomic>
#include <chrono>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include "command.h"

using namespace std::chrono;

class Task {
public:
    std::shared_ptr<Command> command;
    std::atomic<bool> cancelled{false};
    int id;
    Task(int id, std::shared_ptr<Command> cmd) : id(id), command(cmd) {}
};

class TaskScheduler {
private:
    struct ScheduledTask {
        steady_clock::time_point executeAt;
        std::shared_ptr<Task> task;
        bool operator>(const ScheduledTask& other) const {
            return executeAt > other.executeAt;
        }
    };
    std::priority_queue<ScheduledTask, std::vector<ScheduledTask>, std::greater<ScheduledTask>> pq;
    std::mutex mtx;
    std::condition_variable cv;
    std::vector<std::thread> workers;
    std::unordered_map<int, std::shared_ptr<Task>> pendingTasks;
    bool stop = false;
    int nextId = 0;
    void workerThread();
public:
    TaskScheduler(size_t numThreads = 4);
    ~TaskScheduler();
    int schedule(std::shared_ptr<Command> cmd, milliseconds delay = milliseconds(0));
    void cancel(int taskId);
    void shutdown();
};

#endif // TASK_SCHEDULER_H
