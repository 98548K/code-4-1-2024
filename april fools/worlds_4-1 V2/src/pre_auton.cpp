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
      intake.spinFor(4250,degrees,false);
      chassis.drive_with_voltage(10, 12);
      wait (.95,sec);
      chassis.drive_with_voltage(-4, 4);
      wait (0.3,sec);
      RHwings.set(true);
      LHwings.set(true);
      chassis.drive_with_voltage(12, 12);
      wait (0,sec);
      chassis.drive_distance(6);
      intake.spinFor(-1000,degrees);
      chassis.drive_distance(5);
      chassis.drive_distance(-7);
    },
      "5 ball"
  });

  ms.SetTestAutonomous("Match", "Right", "Simple");
	while(ms.should_update && (Competition.isFieldControl() || Competition.isCompetitionSwitch())){
		ms.Update();
		wait(20, msec);
	}
}