
#include "Job.h"


backend::Job::Job(int jobId, const Payload& p): payload(p),id(jobId),status(JobStatus::Pending){}

int backend::Job::getId() const {
    return id;
}

backend::Job::JobStatus backend::Job::getStatus() const {
    return status;
}

const backend::Payload &backend::Job::getPayload() const{
    return payload;
}

void backend::Job::setStatus(backend::Job::JobStatus jobStatus) {
    if(status == jobStatus)
        return;
    if(status == JobStatus::Done || status == JobStatus::Failed)
        return;

    switch (status) {
        case JobStatus::Pending:
            if (jobStatus == JobStatus::Running) {
                status = jobStatus;
            }
            break;

        case JobStatus::Running:
            if (jobStatus == JobStatus::Done || jobStatus == JobStatus::Failed) {
                status = jobStatus;
            }
            break;

        default:
            break;
    }
}






