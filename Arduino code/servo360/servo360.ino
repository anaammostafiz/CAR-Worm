#include <Servo.h>

Servo wheel_1;
Servo wheel_2;
Servo tail_1;
Servo tail_2;

// pin numbers subject to change

void setup() {

// rotate wheel 1 forward 360 degrees

wheel_1.attach(9);
wheel_1.write(0);
delay(6000);
wheel_1.detach();

// rotate wheel 2 forward 360 degrees

wheel_2.attach(9);
wheel_2.write(180);
delay(6000);
wheel_2.detach();

// activate tail 1

tail_1.attach(9);

// extend tail 1
// tail_1.write(0);

// retract tail 1
// tail_1.write(180);

delay(2500);
tail_1.detach();

// activate tail 2

tail_2.attach(9);

// extend tail 2
// tail_2.write(180);

// retract tail 2
// tail_2.write(180); 

delay(2500);
tail_2.detach();

}
