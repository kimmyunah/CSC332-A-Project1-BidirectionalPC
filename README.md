# CSC332-A-Project1-BidirectionalPC
CSC 332-A Project 1 - Sensor Nodes
by Haoyang Chen and Yunah Kim

# Project Description: 
The project is a Bidirectional People Counter that utilizes two HC-SR04 Ultrasonic Sensors with an Arduino UNO board. The main function of the prototype is to count the number of people coming through the gate in both entering and exiting directions. 

The ultrasonic sensors used in the Bidirectional People Counter will periodically send out and receive ultrasonic sound waves to calculate distance. A change in this distance, which we created and set a determining threshold for as 30 subtracted from the intial measured distance, indicates the entry/exit of a person. The passing direction of the person (either entry or exit) is determined by which sensor detects the (shorter) change in distance first. An LED is additionally implemented in our prototype for visual observation of people-counting performance. This LED blinks whenever the sensors detect a person passing through the set environment, regardless of the direction in which they are passing through. 

# Code Explanation: 
For our prototype, we use two ultrasonic sensors.

[INCLUDE VAR EXPLANATIONS/DETAILS]
[INCLUDE LOGIC-RELATED EXPLANATIONS]

# Testing Process:
We were able to test our prototype in our classroom/lab environment and used a fixed distance of approximately 350-60 centimeters. Through simulating an average walking pace with minimized arm movement, we were able to yield accurate results. Each time we "entered" past the Bidirectional People Counter, the people count incremented by one and the LED blinked. Similarly, each time we "exited" past the prototype, the people count decremented and the LED blinked accordingly. When setting up this testing environment we ensured the initial distance measurements made by the two ultrasonic sensors were as balanced (close in value) as possible. 

We encountered some issues with a few test trials. [INCLUDE FAILURES/AREAS OF WEAKNESS]

# Pictures and Videos:
Our protoype in three views: 
![IMG_0002](https://user-images.githubusercontent.com/59979632/155042458-806ddb04-ae2f-45b4-a937-f733f1155f36.jpg)
![IMG_0005](https://user-images.githubusercontent.com/59979632/155042467-fd3bb078-a229-4711-bb12-70d151637717.jpg)
![IMG_0006](https://user-images.githubusercontent.com/59979632/155042478-271bb903-0e60-43b6-abbe-8d487aa1a5a4.jpg)

Our prototype with LED in action:
https://drive.google.com/file/d/1xtJAxPB-MvXRVmNVGYDbtobuS1xkQbUM/view?usp=sharing

Sample serial output from one test (part 1):
<img width="977" alt="Screen Shot 2022-02-17 at 4 07 56 PM" src="https://user-images.githubusercontent.com/59979632/155044150-42e5d7a8-df76-4231-883f-82ef0b3caf69.png">
Sample serial output from one test (part 2):
<img width="978" alt="Screen Shot 2022-02-17 at 4 08 15 PM" src="https://user-images.githubusercontent.com/59979632/155044156-5c3a17b2-ff80-4a1a-abb9-010ba585cf2a.png">
Sample serial output with time stamps during another test:
<img width="843" alt="Screen Shot 2022-02-17 at 4 18 00 PM" src="https://user-images.githubusercontent.com/59979632/155044191-ba3f3bd1-a6dc-49c2-afc8-3fbd4a254c10.png">

# Possible Usage and Main Takeaways:
Information provided by the Bidirectional People Counter may be applied in a number of different ways. [ADD MORE INFO HERE]  
Future applications may implement the use of other alternative sensors like IR sensors.  
