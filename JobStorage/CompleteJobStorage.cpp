
#include "CompleteJobStorage.h"

void backend::CompleteJobStorage::addJob(std::unique_ptr<Job> job) {
        storage.emplace_back(std::move(job));
}

size_t backend::CompleteJobStorage::size() const {
    return storage.size();
}

const std::vector<std::unique_ptr<backend::Job>> &backend::CompleteJobStorage::getAll() {
    return storage;
}
