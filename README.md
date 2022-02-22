# CSC332-A-Project1-BidirectionalPC
CSC 332-A Project 1 - Sensor Nodes
by Haoyang Chen and Yunah Kim

# Project Description: 
The project is a Bidirectional People Counter that utilizes two HC-SR04 Ultrasonic Sensors with an Arduino UNO board. The main function of the prototype is to count the number of people coming through the gate in both entering and exiting directions. 

The ultrasonic sensors used in the Bidirectional People Counter will periodically send out and receive ultrasonic sound waves to calculate distance. A change in this distance, which we created and set a determining threshold for as 30 subtracted from the intial measured distance, indicates the entry/exit of a person. The passing direction of the person (either entry or exit) is determined by which sensor detects the (shorter) change in distance first. An LED is additionally implemented in our prototype for visual observation of people-counting performance. This LED blinks whenever the sensors detect a person passing through the set environment, regardless of the direction in which they are passing through. 

# Code Explanation: 
For our prototype, we use two ultrasonic sensors, each of which includes a trigger pin for output and an echo pin for input. With this, each of the ultrasonic sensors are able to measure the distance between itself and any possible "obstacle." We include a measureDistance function that facilitates this by taking a trigger and echo pin number, as well as int variables initialDistance1 and initialDistance2 that are representative of the initial distance measurement of each ultrasonic sensor. 

In order to differentiate between a person entering and exiting the set environment or room, we utilize two different ultrasonic sensors. If the first sensor is triggered and then the second is triggered, a person is entering and the counter is consequently incremented. However, if the second is triggered first and the first follows, a person is exiting and the counter is decremented. To facilitate this, we use a string variable named sequence. If sensor 1 is triggered, the string is "1", and vice versa for sensor 2. If sensor 2 is triggered after sensor 1, the sequence is concatenated and becomes "12". This is similar for the case in which sensor 1 is triggered after sensor 2. If statements are used for this concatenation process (note that these use the threshold we created for this prototype of the initial distance minus 30).

If the sequence is "12," then the number of current people are incremented and the sequence is reset to an empty string. This is representative of a person entering. Else if the sequence is "21," the number of current people are decremented and the sequence is similarly reset to an empty string. And this is representative of a person exiting.

Error handling if statements are similarly included for invalid sequences like "11" and "22" as well as timeouts. 

Serial output includes readings of the two sensor distance measurements as well as the number of current people.

We include delays throughout our program to facilitate how often readings are taken. Throughout our testing process, we experimented with a range of different delay values, in addition to our intiial environment setup in regards to initial distance, and found that the included values worked best with our current prototype and setup.

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
