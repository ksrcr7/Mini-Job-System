#ifndef MINI_JOB_SYSTEM_JOB_H
#define MINI_JOB_SYSTEM_JOB_H

#include <iostream>



namespace backend{
    struct Payload{std::string description;};

    class Job {
        enum class JobStatus{Pending,Running,Done,Failed};
    private:
        Payload payload;
        int id;
        JobStatus status;

    public:
        Job(int num,const Payload&  p);
        [[nodiscard]] int getId()const;
        [[nodiscard]] JobStatus getStatus()const;
        const Payload& getPayload();




    };
}




#endif //MINI_JOB_SYSTEM_JOB_H
