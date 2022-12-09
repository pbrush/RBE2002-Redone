#include <Romi32U4.h>
#include "Encoders.h"
#include "Speed_controller.h"           //TODO: put all of this in the .h file
           
#include <Arduino.h>

#include <Filter.h>


void SpeedController::Init(void)
{
    MagneticEncoder.Init();
    motors.init();
}

void SpeedController::loop()
{
   Stop();
}

void SpeedController::setEfforts(float lE, float rE) {
    motors.setEfforts(lE, rE);
}

void SpeedController::Move(float target_velocity_left, float target_velocity_right)
{
    if(MagneticEncoder.UpdateEncoderCounts()){
        float e_left = target_velocity_left - MagneticEncoder.ReadVelocityLeft();
        float e_right = target_velocity_right - MagneticEncoder.ReadVelocityRight();

        E_left += e_left;
        E_right += e_right;

        float u_left = Kp*e_left + Ki*E_left;
        float u_right = Kp*e_right + Ki*E_right;

        motors.setEfforts(u_left,u_right);
    }
}

void SpeedController::Stop()
{
    motors.setEfforts(0,0);
}

void SpeedController::setTwist(float linSp, float angSp) 
{
    //Serial.print("Ang Effort: ");
    //Serial.println(angSp);
    Move(linSp-angSp, linSp+angSp);     //motor.setEfforts?
}
