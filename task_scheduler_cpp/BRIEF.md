# Task Scheduler C++ Project Brief

## Overview
This project implements a multithreaded task scheduler in C++ with scheduling, cancellation, and delay capabilities, along with a utility function for calculating earliest task completion times.

## Components Built

### 1. Command Interface (`command.h`)
- Abstract base class defining the `Command` interface
- Allows for extensible task definitions through polymorphism
- Provides a clean separation between task scheduling and execution logic

### 2. Task Scheduler (`task_scheduler.h`, `task_scheduler.cpp`)
- **Multithreaded Architecture**: Uses a thread pool with configurable number of worker threads (default: 4)
- **Priority Queue**: Maintains scheduled tasks ordered by execution time using `std::priority_queue`
- **Thread Safety**: Implements mutex and condition variable for safe concurrent access
- **Task Management**:
  - Schedule tasks with optional delays
  - Cancel pending tasks by ID
  - Graceful shutdown functionality
- **Features**:
  - Atomic task cancellation flags
  - Unique task ID assignment
  - Pending task tracking with unordered_map

### 3. Earliest Finish Time Calculator (`earliest_time.h`, `earliest_time.cpp`)
- **Worker Model**: Defines workers with availability time and processing time
- **Algorithm**: Finds the minimum completion time across all workers
- **Formula**: `finishTime = worker.availableAt + worker.processingTime`
- **Edge Cases**: Handles empty worker lists, negative times, and single worker scenarios

### 4. Test Implementation (`main.cpp`)
- Demonstrates scheduler functionality with delayed task execution
- Shows task cancellation in action
- Comprehensive test suite for `earliestFinishTime` function with multiple scenarios:
  - Varying worker availability times
  - Simultaneous availability
  - Single worker cases
  - Empty input handling
  - Negative time values

## Key Features
- **Concurrency**: Thread-safe task scheduling and execution
- **Flexibility**: Support for immediate and delayed task execution
- **Cancellation**: Ability to cancel tasks before execution
- **Extensibility**: Command pattern allows easy addition of new task types
- **Performance**: Priority queue ensures efficient scheduling (O(log n) insertions)

## Usage Example
```cpp
TaskScheduler scheduler(2);  // 2 worker threads
auto cmd = std::make_shared<PrintCommand>("Hello World");
int taskId = scheduler.schedule(cmd, std::chrono::seconds(1));  // Schedule with 1s delay
scheduler.cancel(taskId);  // Cancel if needed
scheduler.shutdown();      // Clean shutdown
```

## Testing
The project includes built-in tests that verify:
- Task scheduling with delays
- Task cancellation
- Multithreaded execution
- Earliest finish time calculations across various scenarios

## Compilation & Execution
- Compiled successfully with C++ standard library
- Tested on macOS with multithreading support
- All TODO items completed and verified working
