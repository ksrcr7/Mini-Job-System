

#include "TaskQueue.h"

void backend::TaskQueue::push(std::unique_ptr<Job> job) {
    jobs.push(std::move(job));

}
