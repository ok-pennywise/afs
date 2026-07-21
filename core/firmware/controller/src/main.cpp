#include "pipeline.hpp"
#include "priority.hpp"
#include "scheduler.hpp"

void imu();
void pid();
void apply_corrections();

void log();

int main(){
    Pipeline control;
    Pipeline logging;

    Scheduler scheduler;

    control.add_task(imu);
    control.add_task(pid);
    control.add_task(apply_corrections);
    control.priority = Priority::CRITICAL;

    logging.add_task(log);
    logging.priority = Priority::LOW;

    scheduler.add_pipeline(&control);
    scheduler.add_pipeline(&logging);

    while (1)
    {
        scheduler.run();
    }
    
    
}