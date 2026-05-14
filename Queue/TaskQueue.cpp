#include "TaskQueue.h"

void backend::TaskQueue::push(std::unique_ptr<Job> job) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        jobs.push(std::move(job));
    }
    cv.notify_one();
}

std::unique_ptr<backend::Job> backend::TaskQueue::pop() {

    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock,[this](){
        return !jobs.empty() || stop;
    });

    if(jobs.empty())
        return nullptr;

    auto job = std::move(jobs.front());
    jobs.pop();
    return job;

}

bool backend::TaskQueue::empty() const {
    std::lock_guard<std::mutex> lock(mtx);
    return jobs.empty();
}

size_t backend::TaskQueue::size() const {
    std::lock_guard<std::mutex> lock(mtx);
    return jobs.size();
}

void backend::TaskQueue::shutdown() {
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
    }

    cv.notify_all();
}
