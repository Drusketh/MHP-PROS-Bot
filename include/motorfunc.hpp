#ifndef MOTOR_HPP
#define MOTOR_HPP

void move_tank(int input_l, int input_r);
void move_auton_tank(int l_deg, int r_deg, int l_speed, int r_speed);
void move_tray(int input);
void move_arms(int input);
float get_arms();
void set_arms(double position, int vel);
void move_intake(int input);
void move_tray_pid(int input);
void tray_pid(void*);
void move_arm_pid(int input);
void arm_pid(void*);
void reset();

#endif
