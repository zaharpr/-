//
// Created by zpris on 16.12.2021.
//

#include "secondWorker.h"

void SecondWorker::DoSomethingWithNeedle(Needle &n) {
    std::printf("[Worker 2] [Needle %d] checking for sharpness\n", n.id);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (n.sharpness_level < 10) {
        std::printf("[Worker 2] [Needle %d] not sharp enouth, fixing...\n", n.id);
        std::this_thread::sleep_for(std::chrono::seconds(10 - n.sharpness_level));
        n.sharpness_level = 10;
        std::printf("[Worker 2] [Needle %d] fixed!\n", n.id);
    }
    std::printf("[Worker 2] [Needle %d] giving to the third worker...\n", n.id);
}