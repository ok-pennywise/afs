#include "scheduler.hpp"
#include "pipeline.hpp"

void read();

int main(){

    Pipeline* control;
    control->add_task(read);

    Scheduler::instance()->add_pipeline(control);
    
    while (1) {
        Scheduler::instance()->run();
    }
}