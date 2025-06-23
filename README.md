
# SMART CITY WASTE SORTING ROBOT

Group Members and roles:

1. Dickson Mbogo - Program Developer
2. Elisha Jilo - Electrical Systems Developer
3. Shem Koech - Mechanical Designer
4. Masika - Supervisor


Overview
An autonomous system that classifies waste into three types—metal, plastic, and organic—using sensors and sorts them using three servo motors, each linked to a dedicated bin.

 Working
Detection:

Object placed on input chute.

Sensors analyze:

Inductive sensor → detects metal.

IR sensor → detects plastic.

Moisture sensor → detects organic.

Decision:

Microcontroller reads sensor output.

Decides which servo to activate.

Sorting:
https://trello.com/invite/b/67b381944852fa081ac035bd/ATTI09b28d262ff8065e7019820daa05c8408FD4BF4F/smart-city
trello link

Servo 1 rotates chute to bin 1 for metal.

Servo 2 rotates chute to bin 2 for plastic.

Servo 3 rotates chute to bin 3 for organic.

Reset:

Chute returns to initial position.

Waits for next input.

