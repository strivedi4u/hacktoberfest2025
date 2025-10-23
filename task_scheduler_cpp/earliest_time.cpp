#include "earliest_time.h"
#include <limits>

long long earliestFinishTime(const std::vector<Worker>& workers) {
    if (workers.empty()) {
        return -1; // or throw exception, but for simplicity
    }
    long long minTime = std::numeric_limits<long long>::max();
    for (const auto& worker : workers) {
        long long finishTime = worker.availableAt + worker.processingTime;
        if (finishTime < minTime) {
            minTime = finishTime;
        }
    }
    return minTime;
}
