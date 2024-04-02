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
      RVwings.set(true);
      wait (1,sec);
      RVwings.set(false);
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
      "scores stuff (:"
  });

  ms.Assign("Match", "Right", "Simple", new auton{
    [](){
      RHwings.set(true);
      RHwings.set(false);
      chassis.drive_with_voltage(10, 12);
      wait (1.5,sec);
    },
      "scores stuff (:"
  });

  ms.SetTestAutonomous("Match", "Right", "Simple");
	while(ms.should_update && (Competition.isFieldControl() || Competition.isCompetitionSwitch())){
		ms.Update();
		wait(20, msec);
	}
}