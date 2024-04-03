#include "vex.h"

/*

FIRST

"Match"
"Skills"

SECOND

"Left"
"Center"
"Right"

THIRD

"Simple"
"Complex"
"Half Winpoint"
"Winpoint"
*/

void pre_auton(){
  Calibrate();

  ms.Assign("Match", "Left", "Winpoint", new auton{
    [](){
      intake.setVelocity(100,percent);
      intake.spinFor(45,degrees);
      chassis.drive_with_voltage(-3,-7);
      wait (1.5,sec);
      RVwings.set(true);
      chassis.drive_with_voltage(3,6);
      wait (1,sec);
      chassis.drive_with_voltage(-10,10);
      wait (.4,sec);
      RVwings.set(false);
      chassis.drive_with_voltage(2,-2);
      wait (1,sec);
      chassis.drive_distance(16);
      intake.spinFor(-10000,degrees);
    },
      "Basic winpoint"
  });

  ms.Assign("Match", "Right", "Simple", new auton{
    [](){
      intake.setVelocity(100,percent);
      intake.spinFor(45,degrees,false);
      RHwings.set(true);
      wait (1,sec);
      RHwings.set(false);
      intake.spinFor(4500,degrees,false);
      chassis.drive_with_voltage(10, 12);
      wait (.95,sec);
      chassis.drive_with_voltage(-4, 4);
      wait (0.3,sec);
      chassis.drive_with_voltage(4, 4);
      wait (0.4,sec);
      chassis.drive_with_voltage(-4, -4);
      wait (0.4,sec);
      chassis.drive_with_voltage(4, -4);
      wait (0.4,sec);
      RHwings.set(true);
      LHwings.set(true);
      intake.spinFor(-1000,degrees);
      chassis.drive_with_voltage(10, 10);
      wait (1,sec);
      RHwings.set(false);
      LHwings.set(false);
      chassis.drive_with_voltage(-10, -10);
      wait (0.85,sec);
      intake.spinFor(10000,degrees);
      chassis.drive_with_voltage(10, 1);
      wait (.8,sec);
      chassis.drive_with_voltage(1, 1);
    },
      "5 ball"
  });

  ms.SetTestAutonomous("Match", "Right", "Simple");
	while(ms.should_update && (Competition.isFieldControl() || Competition.isCompetitionSwitch())){
		ms.Update();
		wait(20, msec);
	}
}