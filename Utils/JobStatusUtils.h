#ifndef MINI_JOB_SYSTEM_JOBSTATUSUTILS_H
#define MINI_JOB_SYSTEM_JOBSTATUSUTILS_H


#include "../Model/Job.h"
#include <string>

namespace backend{
    std::string toString(backend::Job::JobStatus status){
        switch (status) {
            case Job::JobStatus::Pending:
                return "Pending";
            case Job::JobStatus::Done:
                return "Done";
            case Job::JobStatus::Running:
                return "Running";
            case Job::JobStatus::Failed:
                return "Failed";
            default:
                return "Unknown";
        }
    }
}








#endif //MINI_JOB_SYSTEM_JOBSTATUSUTILS_H
