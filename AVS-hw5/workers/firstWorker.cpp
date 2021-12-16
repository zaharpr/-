//
// Created by zpris on 16.12.2021.
//

#include "firstWorker.h"

void FirstWorker::DoSomethingWithNeedle(Needle &n) {
    std::printf("[Worker 1] [Needle %d] checking if crooked\n", n.id);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (n.crooked) {
        std::printf("[Worker 1] [Needle %d] crooked, fixing...\n", n.id);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        n.crooked = false;
        std::printf("[Worker 1] [Needle %d] fixed!\n", n.id);
    }
    std::printf("[Worker 1] [Needle %d] giving to the second worker...\n", n.id);
}