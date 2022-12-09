#ifndef SPEED_CONTROLLER
#define SPEED_CONTROLLER


#include <effortDatum.h>

#include <Romi32U4.h>
#include <PIDController.h>

// Lab/Feature Related

#include <Encoders.h>


class SpeedController{
    private:
        const float Kp = 0.5; //Adapt the parameters until your robot moves at the speed you command it to drive
        const float Ki = 0.1; 
        float E_left = 0; 
        float E_right = 0;
        int counts = 1440; //assignment
        
        Romi32U4Motors motors;
        Encoder MagneticEncoder;
        

    public:
        SpeedController() {};
        effortDatum targEffort;

        void loop();    //maybe make a boolean

        void Init(void);
        void Stop(void);
        void Move(float target_velocity_left, float target_velocity_right);
        void setEfforts(float lE, float rE);
        void setTwist(float linSp, float angSp);
        
};

#endif