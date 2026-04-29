#ifndef MINI_JOB_SYSTEM_COMPLETEJOBSTORAGE_H
#define MINI_JOB_SYSTEM_COMPLETEJOBSTORAGE_H

#include "../Model/Job.h"

#include <vector>
#include <memory>

namespace backend{

    class CompleteJobStorage {
    private:
        std::vector<std::unique_ptr<backend::Job>> storage;


    public:
        void addJob(std::unique_ptr<Job> job);

    };

}



#endif //MINI_JOB_SYSTEM_COMPLETEJOBSTORAGE_H
