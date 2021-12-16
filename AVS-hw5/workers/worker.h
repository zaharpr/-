//
// Created by zpris on 13.12.2021.
//

#ifndef AVS5_WORKER_H
#define AVS5_WORKER_H


#include <condition_variable>
#include <queue>
#include <thread>
#include <functional>
#include "../needle.h"

class Worker {
public:
    std::mutex mutex_;
    std::condition_variable cv_;
    std::queue<Needle> queue_;
    std::function<void(const Needle &)> callback_;
    std::thread t_;
    bool finished_{false};

    void Consume(const Needle &n);

    void SetProduceCallback(const decltype(callback_) &callback);

    void Start();

    virtual void DoSomethingWithNeedle(Needle &n) = 0;

    void Finish();

    void Join();
};


#endif //AVS5_WORKER_H
