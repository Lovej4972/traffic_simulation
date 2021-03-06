
#ifndef TRAFFIC_SIMULATION_OBSTACLE_H
#define TRAFFIC_SIMULATION_OBSTACLE_H
#include <math.h>

struct Obstacle
{
    double start;		// position of the start of the obstacle
    double end;			// position of the end of the obstacle

    /**
    * New setpoints
    */
    double speed_limit;
    double time_headway;	// difference between the time when a vehicle arrives at a point on the highway and the time the next vehicle arrives at the same point
    double space_headway;   // desired minimum distance (gap) between vehicles


    Obstacle(double start, double end, double speed_limit, double time_headway, double space_headway)
        : start(start), end(end), speed_limit(speed_limit), time_headway(time_headway), space_headway(space_headway) {}
    Obstacle(double start, double end, double speed_limit)
        : start(start), end(end), speed_limit(speed_limit), time_headway(0), space_headway(0) {}
    Obstacle() 
        : start(0), end(0), speed_limit(INF), time_headway(0), space_headway(0) {}
};

struct TrafficLight
{
    double pos;
    double period;
    double duty_cycle;    // proportion of green time
    double initial_delay; // time before the light becomes active (green until then)

    TrafficLight(double pos, double period, double duty_cycle = 0.5, double delay = 0.0)
        : pos(pos), period(period), duty_cycle(duty_cycle), initial_delay(delay) {}
    TrafficLight()
        : pos(0), period(1), duty_cycle(1), initial_delay(0) {}

    bool isRed(double t) const
    {
        if (t < initial_delay) return false;
        return fmod(t-initial_delay, period) / period >= duty_cycle;
    }
};

#endif //TRAFFIC_SIMULATION_OBSTACLE_H
