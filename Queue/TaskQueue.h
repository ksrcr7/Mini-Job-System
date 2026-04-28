#ifndef MINI_JOB_SYSTEM_TASKQUEUE_H
#define MINI_JOB_SYSTEM_TASKQUEUE_H

#include "../Model/Job.h"
#include <queue>
#include <memory>

namespace backend{

    class TaskQueue {
    private:
        std::queue<std::unique_ptr<Job>> jobs;

    public:
        void push(std::unique_ptr<Job> job);
        std::unique_ptr<Job> pop();
        bool empty() const;
        

    };
}






#endif //MINI_JOB_SYSTEM_TASKQUEUE_H
