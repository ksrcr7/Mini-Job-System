
#include "Job.h"


backend::Job::Job(int jobId, const Payload& p): payload(p),id(jobId),status(JobStatus::Pending){}

int backend::Job::getId() const {
    return id;
}

backend::Job::JobStatus backend::Job::getStatus() const {
    return status;
}

const backend::Payload &backend::Job::getPayload() {
    return payload;
}




