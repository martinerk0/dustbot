### Introduction

The idea for this project came from living in a dusty environment at dormitory 17. Listopadu. 
Because of its unfortunate proximity to busy road Mestsky okruh, and old air conditioning from the communist era, rooms are filled with dusty particles exceptionally fast - fast enough to warrant building an autonomous robot for cleaning them.
 
 <img src="./images/kolej_sunset.jpg" alt="drawing" height="300" width="300"/>
 
### Goals

We loosely summarized our project requirements in these goals: 

- Create robot that cleans dust in a room,
- should be autonomous,
- use available, not expensive components,
- should be adaptable,
- could be designed iteratively
- could be easily replicated

### Design of robot
Since this is my first experience with robotics, I strived for easy design that could be easily modified and adapted. We designed chassis of Dustbot in an easy beginner friendly online app www.tinkercad.com.

Here can see bottom part of the Dustbot. It provides support for the whole robot. Notice that motel is rotated by 180 degrees, that is because this is the way it is 3D printed, but actually it is used upside down.

<img src="./images/bottom.png" alt="drawing" height="300" width="300"/>

Because we added components on the fly, we used **iterated design**. As you can see on this picture, you can see progress of design of bottom part of Dustbot. With 3D printer you can see which parts really holds up in real world or not, and improve them if necessary.

<img src="./images/progress.jpg" alt="drawing" height="300" width="300"/>

I also wanted to utilize already created parts, which is raspberry holder and camera holder, and incorporate them into the robot easily.

[Thingiverse](https://www.thingiverse.com)


### Parts of Robot
- chassis: 3D printed
- actuators: motors with wheels
- sensors: 
    - range: camera
  </br>      ultrasound
  </br>      lidar
    - bodily: odometry
    - tactile: switches

### Actuators
I chose [differential steering](https://en.wikipedia.org/wiki/Differential_steering) because it is easy to program, and uses only two motors.


We used TT motors, they are available on Ebay or Aliexpress for 2 dollars each.

<img src="./images/kolej_sunset.jpg" alt="drawing" height="300" width="300"/>




### sensors
 
# Tactile
 microswitch
 
# Odometry
 use motor with encoder, but that is not cheap, so we adapted model from thingiverse for TT motor
 
 
# Camera 
 Camera is very rich and cheap sensor, that could be used in future improvements for object detection and collision evasion.
 
# Ultrasound
We bought several ultrasound sensors that will be added in future versions.


# Software:
- _Raspberry Pi_
- Ubuntu
- RO
- PySerial
- Arduino
- For getting input and control motors


- add some images

