#ifndef MINI_JOB_SYSTEM_WORKER_H
#define MINI_JOB_SYSTEM_WORKER_H

#include "../Queue/TaskQueue.h"


namespace backend{
    class Worker {
    private:
        TaskQueue& taskQueue;


    public:
        explicit Worker(TaskQueue& TQ);


    };
}



#endif //MINI_JOB_SYSTEM_WORKER_H
