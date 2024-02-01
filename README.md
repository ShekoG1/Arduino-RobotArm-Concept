# Arduino Robot Arm Concept

This Arduino project demonstrates a robot arm control concept using a potentiometer, a switch button, and an RGB LED. The robot arm comprises two servos, and the control mechanism allows users to manipulate either the base or the arm itself based on the switch state. The RGB LED changes color in response to the switch state.

The servos would ideally, in a real application, be connected via a simple pan & tilt servo kit.

## Code Explanation

The provided CPP code utilizes the Arduino framework and Servo library to control the robot arm. Here is a breakdown of the main components and functionalities:

- **Declarations:**
  - `potentiometerPin`: Analog pin connected to the potentiometer.
  - `rgbLED01_pins`: Array of pins connected to the RGB LED (Red, Green, Blue).
  - `switchPin`: Digital pin connected to the switch button.
  - `servo_5` and `servo_6`: Servo motor objects for controlling the robot arm.
  - Various variables to track button state and control arm movement.

- **Setup Function:**
  - Initializes pins for RGB LED and switch.
  - Attaches servo motors to their respective pins.
  - Initiates serial communication for debugging.

- **Loop Function:**
  - Reads the state of the switch button.
  - Sets the RGB LED color to white.
  - Changes LED color to red or blue based on the switch state.
  - Adjusts the control mode (base/arm) accordingly.
  - Reads the potentiometer value to determine the arm position.
  - Controls the servo motors based on potentiometer input.

- **Debugging:**
  - Serial communication is used for debugging purposes.

## View the Circuit

![Emulated View](https://github.com/ShekoG1/Arduino-RobotArm-Concept/blob/main/EmulatedView.png)

## License

This project is licensed under the MIT License.

**Thank you for viewing. Have a lovely day ahead!**

## Authors

- Made with &#x2764; by **[Shekhar Maharaj](https://www.theshekharmaharaj.com)**

## 🔗 Links
[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://www.theshekharmaharaj.com)
[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/the-shekhar-maharaj/)
[![twitter](https://img.shields.io/badge/twitter-1DA1F2?style=for-the-badge&logo=twitter&logoColor=white)](https://twitter.com/therealsheko)

*'Making dreams come true'*