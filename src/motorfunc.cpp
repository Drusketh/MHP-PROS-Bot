#include "main.h"

#define L_WHEEL_FRONT_PORT 1
#define L_WHEEL_BACK_PORT 2
#define L_INTAKE_PORT 3
#define ARM_PORT 4
#define TRAY_PORT 7
#define R_INTAKE_PORT 8
#define R_WHEEL_BACK_PORT 9
#define R_WHEEL_FRONT_PORT 10


pros::Motor l_wheel_front (L_WHEEL_FRONT_PORT);
pros::Motor l_wheel_back (L_WHEEL_BACK_PORT, true);
pros::Motor l_intake (L_INTAKE_PORT);
pros::Motor arm (ARM_PORT);
pros::Controller controller (CONTROLLER_MASTER);
pros::Motor tray (TRAY_PORT);
pros::Motor r_intake (R_INTAKE_PORT, true);
pros::Motor r_wheel_back (R_WHEEL_BACK_PORT, true);
pros::Motor r_wheel_front (R_WHEEL_FRONT_PORT);

//Math
int
sgn(int input) {
    if (input > 0)
    return 1;
    else if (input < 0)
    return -1;
    return 0;
}

int
clipnum(int input, int clip) {
    if (input > clip)
    return clip;
    else if (input < clip)
    return -clip;
    return input;
}

void
reset() {
    l_intake.set_brake_mode(MOTOR_BRAKE_HOLD);
    r_intake.set_brake_mode(MOTOR_BRAKE_HOLD);
    l_arm.set_brake_mode(MOTOR_BRAKE_HOLD);
    r_arm.set_brake_mode(MOTOR_BRAKE_HOLD);
    l_arm.set_zero_position(0);
    r_arm.set_zero_position(0);
    f_tray.set_zero_position(0);
    b_tray.set_zero_position(0);

    left_wheels.tare_position();
    right_wheels.tare_position();
}

//Set motors
void
move_tank(int input_l, int input_r) {
    left_wheels.move(input_l);
    right_wheels.move(input_r);
}

void
move_tray(int input) {
    f_tray.move(input);
    b_tray.move(input);
}


void
move_arms(int input) {
    l_arm.move(input);
    r_arm.move(input);
}

float
get_arms() {
    return l_arm.get_position();
}

void
set_arms(double position, int vel) {
    l_arm.move_relative(position, vel);
    r_arm.move_relative(position, vel);
}


void
move_intake(int input) {
    l_intake.move(input);
    r_intake.move(input);
}

//PID
int t_target;
void
set_tray_pid(int input) {
    t_target = input;
}
void
tray_pid(void*) {
	while (true) {
		move_tray((t_target-f_tray.get_position())*0.5);
		pros::delay(20);
	}
}

int a_target;
void
set_arm_pid(int input) {
    a_target = input;
}
void
arm_pid(void*) {
    while (true) {
        move_arms((a_target-l_arm.get_position())*0.5);
        pros::delay(20);
    }
}


void
auton_tank(int input_l, int input_r) {
    left_wheels.move(input_l);
    right_wheels.move(input_r);
}
