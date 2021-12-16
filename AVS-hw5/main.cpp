#include <functional>
#include <iostream>
#include <random>
#include "needle.h"
#include "workers/firstWorker.h"
#include "workers/secondWorker.h"
#include "workers/thirdWorker.h"


int main() {
    FirstWorker first_worker;
    SecondWorker second_worker;
    ThirdWorker third_worker;

    first_worker.SetProduceCallback([&](const Needle &n) {
        second_worker.Consume(n);
    });
    second_worker.SetProduceCallback([&](const Needle &n) {
        third_worker.Consume(n);
    });
    third_worker.SetProduceCallback([&](const Needle &n) {
        std::printf("Needle %d processed successfully\n", n.id);
    });

    first_worker.Start();
    second_worker.Start();
    third_worker.Start();

    std::mt19937 gen(32);

    for (int i = 0; i < 20; i++) {
        Needle n;
        n.id = i;
        n.crooked = gen() % 2 == 0;
        n.sharpness_level = gen() % 11;
        first_worker.Consume(n);
    }

    first_worker.Join();
    second_worker.Join();
    third_worker.Join();
    return 0;
}
