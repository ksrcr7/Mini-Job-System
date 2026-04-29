#include "Worker/Worker.h"

int main() {
    backend::TaskQueue queue;
    backend::Worker worker(queue);

    backend::Payload pay1("Buy Milk");
    backend::Job job1(1,pay1);
    backend::Payload pay2("Buy Pc");
    backend::Job job2(2,pay2);
    backend::Payload pay3("Buy Laptop");
    backend::Job job3(3,pay3);

    queue.push(std::make_unique<backend::Job>(job1));
    queue.push(std::make_unique<backend::Job>(job2));
    queue.push(std::make_unique<backend::Job>(job3));

    worker.processNextJob();
    worker.processNextJob();
    worker.processNextJob();



}
