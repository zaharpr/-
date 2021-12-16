//
// Created by zpris on 13.12.2021.
//

#ifndef AVS5_SECONDWORKER_H
#define AVS5_SECONDWORKER_H

#include "worker.h"


class SecondWorker : public Worker {

    void DoSomethingWithNeedle(Needle &n) override;
};

#endif //AVS5_SECONDWORKER_H
