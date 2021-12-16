//
// Created by zpris on 13.12.2021.
//

#ifndef AVS5_FIRSTWORKER_H
#define AVS5_FIRSTWORKER_H

#include "worker.h"

class FirstWorker : public Worker {

    void DoSomethingWithNeedle(Needle &n) override;
};

#endif //AVS5_FIRSTWORKER_H
