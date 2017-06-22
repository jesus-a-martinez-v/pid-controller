# PID Controller
Project implemented as part of the Udacity's Self-Driving Car Engineer Nanodegree Program.

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases).

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid <Kp> <Ki> <Kd>`. Example: `./pid 1.7 0.022 15.5`

## Reflection
The parameters used in this project were:
 - Proportional term (Kp): 1.7
 - Integral term (Ki): 0.022
 - Derivative term (Kd): 15.5

 Kp is in charge of determining how much the car should steer in order to minimize the CTE. A large value of Kp makes the car steer too wildly, while a small value reduces the responsiveness of the car to changes in the CTE (it steers very slow). To mantain Kp under control, we use the change rate of the CTE to "predict" the trajectory the car should follow. To adjust the influence of this change rate, we need another parameter: Kd. If Kp is the "pull" the car will feel to follow the desired trajectory, then Kd is the "resistance" of that pull. So, a high value of Kd reduces the influence of Kp and makes the car react slowly to changes in CTE, while a small value of Kd means that the car has less resistance towards the pull Kp exercises on it, and thus the car will oscillate. Finally, we need to take into account random influences such as bumps in the road, climatic conditions and sensor noise. These factors may affect the accuracy of our controller. To control them we introduce the parameter Ki, which controls the integral error (accumulation of all CTE over time). So, if for some reason, the car keeps too much time on one side of the desired trajectory, the integral term will be aware of this and will increase the steering angle towards the right path. We have to be careful when setting Ki, because a large value will put too much weight on random noise (thus increasing the car's oscillation), and a small value will practically ignore it, meaning that this noise or external influences might keep our car off the desired trajectory for good.

 These constants were found via a trial and error method. Although is a hard (and arguably inefficient) process, it provides a valuable insight about the contribution of each term to the overall value calculated by the controller which, in this case, was the steering angle of the vehicle to drive itself withouth leaving the track at any moment. You can watch how this parameters acts on the car to keep it driving inside the track in [this video]() :)

 ## Next steps
 There are lots of things that can be done to improve the accuracy of the model, as well as the "coolness" of it. For instance, we could implement another PID controller in charge of controlling the car's speed. Also, most definitely we should implement a way to find the best parameters in an automatic fashion, wether using stochastic gradient descent or Twiddle or any other sophisticated approach. 
