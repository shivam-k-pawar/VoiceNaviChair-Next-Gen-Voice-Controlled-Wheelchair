# VoiceNaviChair-Next-Gen-Voice-Controlled-Wheelchair
Manual wheelchairs provide mobility for individuals with limited lower body function. However, for those with upper body limitations as well, handling a traditional wheelchair can be challenging or even impossible. This significantly restricts their independence and ability to perform daily activities. This project addresses this challenge by developing a voice-controlled wheelchair prototype utilizing an Arduino microcontroller and an Ai-Thinker VC-01 module for voice recognition. This system leverages speech recognition technology to allow users to control the wheelchair's movement through voice commands by eliminating the need for manual control.
This wheelchair offers two control methods:

Voice Commands: Users can navigate the wheelchair by issuing simple voice commands, enhancing independence for those with limited hand and arm function.
Joystick Control: A traditional joystick remains available, providing a familiar control method and a backup option for situations where voice recognition might not be ideal.
Components:
Voice Recognition Module (Ai-Thinker VC-01): The VC-01 is a low-cost offline speech recognition module. It utilizes pre-programmed algorithms to convert spoken commands into digital data. This data is then sent to the microcontroller for interpretation and control of the wheelchair’s movement.
Microcontroller (Arduino Uno): The Arduino Uno is a versatile open-source microcontroller board. The Arduino Uno is programmed to understand the received voice commands and translate them into control signals. These signals are then sent to the motor driver to regulate the wheelchair's movement according to the user's intent.
Joystick: The joystick acts as an alternative control method for users who may prefer it or require it in situations where voice commands might not be ideal. It’s a hand-held device used to control the direction and speed of the wheelchair motors.
Motor driver (L298N): It receives control from the Arduino. It amplifies the weak control signals from the Arduino to a level sufficient for driving the wheelchair motors.
2 DC Motors: Propel the wheelchair based on the control signals received from the motor driver. The direction and speed of rotation determine the wheelchair's movement (forward, backward, turn).
Battery: Provides the power to all the components of the system.
Working of Project
Voice Recognition Module (AI Thinker VC-01): The VC-01 module is responsible for recognizing voice commands spoken by the user and providing feedback in the form of voice responses.
Arduino Uno: The Arduino Uno serves as the central processing unit, receiving input signals from both the voice recognition module and the joystick. It processes these signals and sends appropriate commands to the motor driver.
Motor Driver: The motor driver receives commands from the Arduino Uno and controls the movement of the wheelchair's motors accordingly.
Voice-Controlled Mode: By default, the wheelchair operates in voice-controlled mode. The user can issue commands such as "up," "down," "left," "right," "stop," etc., using voice input. When a voice command is detected by the AI Thinker VC-01 module, it triggers a signal to the Arduino Uno.
For example, when the user says "up," the AI Thinker VC-01 module sends a signal to the Arduino Uno indicating the "up" command. The Arduino Uno then translates this signal into motor commands and sends them to the motor driver.
Joystick Control: Alternatively, the user can switch to joystick control mode by issuing the command "joystick on." When this command is recognized by the AI Thinker VC-01 module, it triggers a signal to the Arduino Uno, indicating that joystick control is enabled.
Once joystick control is activated, the user can manipulate the joystick to control the wheelchair's movement. The Arduino Uno reads the input signals from the joystick and sends corresponding commands to the motor driver.
Feedback: When a voice command is successfully recognized and executed, the VC-01 module provides auditory feedback to the user, confirming the action taken. For example, if the user says "move forward," the VC-01 module might respond with "Moving forward" to indicate that the command was understood and executed.
This integration of voice recognition with auditory feedback enhances the user experience by providing real-time confirmation of their commands and actions
WhatsApp Image 2024-05-29 at 21 56 45_c7cee198
WhatsApp Image 2024-05-29 at 20 32 15_ab11c735
