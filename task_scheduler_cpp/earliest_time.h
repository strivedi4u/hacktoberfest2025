#ifndef EARLIEST_TIME_H
#define EARLIEST_TIME_H

#include <vector>
#include <limits>

struct Worker {
    long long availableAt;
    long long processingTime;
};

long long earliestFinishTime(const std::vector<Worker>& workers);

#endif // EARLIEST_TIME_H
