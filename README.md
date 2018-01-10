# PID-Controller
In this C++ project, a PID controller is used to drive a simulated car around a virtual track. The project involves implementing the controller for the steering angle of the car, as well as tuning coefficients for each PID value in order to calculate a steering angle that keeps the car on the track.

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Reflections
It was very difficult to manually get the coefficients of the PID controller because they vary widely in their range (from 6 to 0.0003). Once successfull to get the initial coefficients(3, 0.3, 0.0003) that can drive the car around the simulated track, I then used squared error of the cte(cross track error) to tune the parameters to get the least error. The following table gives the value of the coefficient and the squared cte for one complete lap:

| Kd            |Kp             | Ki    |  squared cte   |
| ------------- |:-------------:| -----:|  ------------- |
| col 3 is      | right-aligned | $1600 |  col 3 is      |
| col 2 is      | centered      |   $12 |  col 3 is      | 
| zebra stripes | are neat      |    $1 |  col 3 is      | 
| col 3 is      | right-aligned | $1600 |  col 3 is      |
| col 2 is      | centered      |   $12 |  col 3 is      | 
| zebra stripes | are neat      |    $1 |  col 3 is      | 
| col 3 is      | right-aligned | $1600 |  col 3 is      |
| col 2 is      | centered      |   $12 |  col 3 is      | 
| zebra stripes | are neat      |    $1 |  col 3 is      | 
