#include "task_scheduler.h"
#include <iostream>

TaskScheduler::TaskScheduler(size_t numThreads) {
    for (size_t i = 0; i < numThreads; ++i) {
        workers.emplace_back(&TaskScheduler::workerThread, this);
    }
}

TaskScheduler::~TaskScheduler() {
    shutdown();
}

void TaskScheduler::shutdown() {
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
    }
    cv.notify_all();
    for (auto& t : workers) {
        if (t.joinable()) t.join();
    }
}

int TaskScheduler::schedule(std::shared_ptr<Command> cmd, milliseconds delay) {
    auto now = steady_clock::now();
    auto executeAt = now + delay;
    std::unique_lock<std::mutex> lock(mtx);
    int id = nextId++;
    auto task = std::make_shared<Task>(id, cmd);
    pendingTasks[id] = task;
    pq.push({executeAt, task});
    cv.notify_one();
    return id;
}

void TaskScheduler::cancel(int taskId) {
    std::unique_lock<std::mutex> lock(mtx);
    auto it = pendingTasks.find(taskId);
    if (it != pendingTasks.end()) {
        it->second->cancelled = true;
        pendingTasks.erase(it);
    }
}

void TaskScheduler::workerThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return stop || !pq.empty(); });
        if (stop && pq.empty()) return;
        auto now = steady_clock::now();
        if (!pq.empty() && pq.top().executeAt <= now) {
            auto st = pq.top();
            pq.pop();
            lock.unlock();
            pendingTasks.erase(st.task->id);
            if (!st.task->cancelled.load()) {
                st.task->command->execute();
            }
        } else if (!pq.empty()) {
            auto waitTime = pq.top().executeAt - now;
            cv.wait_for(lock, waitTime);
        }
    }
}
