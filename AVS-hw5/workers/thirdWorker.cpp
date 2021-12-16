//
// Created by zpris on 16.12.2021.
//

#include "thirdWorker.h"

void ThirdWorker::DoSomethingWithNeedle(Needle &n) {
    std::printf("[Worker 3] [Needle %d] checking for quality\n", n.id);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    if (n.sharpness_level == 10 && !n.crooked) {
        std::printf("[Worker 3] [Needle %d] quality is good!\n", n.id);
    } else {
        throw std::logic_error("bad quality!");
    }
}
