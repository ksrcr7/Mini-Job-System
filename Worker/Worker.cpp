

#include "Worker.h"
#include <mutex>

std::mutex coutMutex;

backend::Worker::Worker(backend::TaskQueue &TQ,CompleteJobStorage& JB): taskQueue(TQ),jobStorage(JB) {}

void backend::Worker::processNextJob() {
    auto nextJob = taskQueue.pop();
    if(nextJob == nullptr)
        return;

    nextJob->setStatus(backend::Job::JobStatus::Running);

    std::cout<<"[Worker] Processing Job ID: " << nextJob->getId()
             << " | Description: " << nextJob->getPayload().description<<std::endl;

    nextJob->setStatus(backend::Job::JobStatus::Done);
    jobStorage.addJob(std::move(nextJob));

}

void backend::Worker::run() {
    while (true) {

        auto job = taskQueue.pop();
        if (job == nullptr)
            break;

        job->setStatus(backend::Job::JobStatus::Running);

        {
            std::lock_guard<std::mutex> lock(coutMutex);

            std::cout << "[Worker] Processing Job ID: " << job->getId()
                      << " | Description: " << job->getPayload().description
                      << std::endl;
        }

        job->setStatus(backend::Job::JobStatus::Done);
        jobStorage.addJob(std::move(job));
    }
}
