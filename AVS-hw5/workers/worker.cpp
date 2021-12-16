//
// Created by zpris on 13.12.2021.
//

#include "worker.h"

void Worker::Consume(const Needle &n) {
    std::unique_lock<std::mutex> l(mutex_);
    queue_.push(n);
    cv_.notify_one();
}

void Worker::SetProduceCallback(const decltype(callback_) &callback) {
    callback_ = callback;
}

void Worker::Start() {
    t_ = std::thread([this] {
        while (true) {
            Needle n;
            {
                std::unique_lock<std::mutex> l(mutex_);
                while (!finished_ && queue_.empty()) {
                    cv_.wait(l);
                }
                if (queue_.empty() && finished_) {
                    return;
                }
                n = queue_.front();
                queue_.pop();
            }
            DoSomethingWithNeedle(n);
            if (callback_) {
                callback_(n);
            }
        }
    });

}

void Worker::Finish() {
    std::unique_lock<std::mutex> l(mutex_);
    finished_ = true;
    cv_.notify_one();
}

void Worker::Join() {
    Finish();
    t_.join();
}
