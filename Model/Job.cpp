
#include "Job.h"

#include <utility>

backend::Job::Job(int jobId, backend::Payload p): payload(std::move(p)),id(jobId),status(JobStatus::Pending){}

int backend::Job::getId() const {
    return id;
}
