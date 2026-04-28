

#include "Worker.h"

backend::Worker::Worker(backend::TaskQueue &TQ): taskQueue(TQ) {}

void backend::Worker::processNextJob() {
    auto nextJob = taskQueue.pop();
    if(nextJob == nullptr)
        return;

    nextJob->setStatus(backend::Job::JobStatus::Running);

    std::cout<<"[Worker] Processing Job ID: " << nextJob->getId()
             << " | Description: " << nextJob->getPayload().description<<std::endl;

    nextJob->setStatus(backend::Job::JobStatus::Done);

}
