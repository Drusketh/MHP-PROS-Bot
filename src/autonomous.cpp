#include "main.h"

//Drivetrain: 360deg wheel = 840deg motor
//360deg motor = 5.38 in wheel travel
//1 wheel rot = 12.553rep in

//1'6" to start cubes
//3'10" to get all 4 cubes

//Outline:
//flip ramp
//Drive forward 3078


void autonomous() {
	pros::Motor l_wheel_back (2, true);
	reset();

	//Flip Ramp?
	move_arms(-90);
	pros::delay(500);

	move_intake(105);
	pros::delay(1000);

	move_intake(-105);
	move_arms(80);
	pros::delay(1000);

	move_intake(0);
    move_arms(0);

	//Drive Forward 3078deg
    int dist = 3078*2;
	move_auton_tank(dist, dist, 127, 127);
    move_intake(105);
	while (!((l_wheel_back.get_position() < dist+5) && (l_wheel_back.get_position() > dist-5))) {
	    pros::delay(2);
	}

    reset();
    move_intake(0);

    move_auton_tank(-dist, -dist, 127, 127);
    while (!((l_wheel_back.get_position() < dist+5) && (l_wheel_back.get_position() > dist-5))) {
	    pros::delay(2);
	}

    // reset();
    // dist = 420;
    // move_auton_tank(dist, -dist, 127, 127);
    // while (!((l_wheel_back.get_position() < dist+5) && (l_wheel_back.get_position() > dist-5))) {
	//     pros::delay(2);
	// }
}
