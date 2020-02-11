#include "main.h"
#include "motorfunc.cpp"

void autonomous() {
	l_intake.move(127);
	r_intake.move(127);
	l_ramp.move(45);
	r_ramp.move(45);
	pros::delay(2000);

	l_intake.move(-127);
	r_intake.move(-127);
	l_ramp.move(-45);
	r_ramp.move(-45);
	pros::delay(500);

	l_intake.move(0);
	r_intake.move(0);
	l_ramp.move(0);
	r_ramp.move(0);
}
