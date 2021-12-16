//
// Created by zpris on 13.12.2021.
//

#ifndef AVS5_THIRDWORKER_H
#define AVS5_THIRDWORKER_H

#include "worker.h"

class ThirdWorker : public Worker {

    void DoSomethingWithNeedle(Needle &n) override;
};

#endif //AVS5_THIRDWORKER_H
