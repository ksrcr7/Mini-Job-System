#ifndef MINI_JOB_SYSTEM_WORKER_H
#define MINI_JOB_SYSTEM_WORKER_H

#include "../Queue/TaskQueue.h"
#include "../JobStorage/CompleteJobStorage.h"


namespace backend{
    class Worker {
    private:
        TaskQueue& taskQueue;
        CompleteJobStorage& jobStorage;


    public:
        explicit Worker(TaskQueue& TQ,CompleteJobStorage& JB);
        void processNextJob();
        void run();


    };
}



#endif //MINI_JOB_SYSTEM_WORKER_H
