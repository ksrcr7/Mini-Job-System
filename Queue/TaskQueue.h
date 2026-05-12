#ifndef MINI_JOB_SYSTEM_TASKQUEUE_H
#define MINI_JOB_SYSTEM_TASKQUEUE_H

#include "../Model/Job.h"
#include <queue>
#include <memory>
#include <mutex>

namespace backend{

    class TaskQueue {
    private:
        std::queue<std::unique_ptr<Job>> jobs;
        mutable std::mutex mtx;

    public:
        void push(std::unique_ptr<Job> job);
        std::unique_ptr<Job> pop();
        [[nodiscard]] bool empty() const;
        [[nodiscard]] size_t size() const;
        

    };
}






#endif //MINI_JOB_SYSTEM_TASKQUEUE_H
