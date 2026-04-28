#ifndef MINI_JOB_SYSTEM_JOB_H
#define MINI_JOB_SYSTEM_JOB_H

#include <iostream>



namespace backend{
    struct Payload{std::string description;};

    class Job {
    public:
        enum class JobStatus{Pending,Running,Done,Failed};
        Job(int jobId,const Payload&  p);
        [[nodiscard]] int getId()const;
        [[nodiscard]] JobStatus getStatus()const;
        [[nodiscard]] const Payload& getPayload() const;
        void setStatus(JobStatus jobStatus);

    private:
        Payload payload;
        int id;
        JobStatus status;






    };
}




#endif //MINI_JOB_SYSTEM_JOB_H
