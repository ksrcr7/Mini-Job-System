#include "TaskQueue.h"

void backend::TaskQueue::push(std::unique_ptr<Job> job) {
    jobs.push(std::move(job));

}

std::unique_ptr<backend::Job> backend::TaskQueue::pop() {
    if(jobs.empty())
        return nullptr;

    auto job = std::move(jobs.front());
    jobs.pop();
    return job;

}

bool backend::TaskQueue::empty() const {
    return jobs.empty();
}

size_t backend::TaskQueue::size() const {
    return jobs.size();
}
