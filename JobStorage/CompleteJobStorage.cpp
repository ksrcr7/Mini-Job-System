
#include "CompleteJobStorage.h"

void backend::CompleteJobStorage::addJob(std::unique_ptr<Job> job) {
        storage.emplace_back(std::move(job));
}
