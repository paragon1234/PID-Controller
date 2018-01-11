# PID-Controller
In this C++ project, a PID controller is used to drive a simulated car around a virtual track. The project involves implementing the controller for the steering angle of the car, as well as tuning coefficients for each PID value in order to calculate a steering angle that keeps the car on the track.

## Basic Build Instructions
1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Components of PID
This section is a replication from this [site](https://github.com/paragon1234/PID-Control-Project)

The actual implementation of code for a basic PID controller is fairly straightforward, but making the controller actually perform well is the tough part. Having knowledge of each part of "PID" is important:
* The "P" for proportional means that the car will steer in proportion to the cross-track error, or CTE. CTE is essentially how far from the middle line of the road the car is. This makes sense, as if the car is to the left of the line then you would want to steer to the right; if it is far to the left of the middle with a high CTE then you want a higher steering angle. However, if the coefficient is set too high for P, the car will oscillate a ton, as the car will constantly overcorrect and overshoot the middle. If the coefficient is too low, the car may react too slowly to curves when the car gets off-center with a higher CTE.
* The "I" for integral sums up all CTEs up to that point, such that too many negative CTEs (in this case, meaning the car has been to the left of the middle of the lane for awhile) will drive up this value, causing the car to turn back toward the middle, preventing the car from driving on one side of the lane the whole time. If the coefficient is too high for I, the car tends to have quicker oscillations, and does not tend to get up to a quick speed. A low coefficent for I will cause the car to tend to drift to one side of the lane or the other for longer periods of time.
* The "D" for derivate is the change in CTE from one value to the next. This means that 1) if the derivative is quickly changing, the car will correct itself (i.e. higher steering angle) faster, such as in the case of a curve, and 2) if the car is moving outward from the middle, this will cause the steering to get larger (as the derivative sign will match the proportional sign), but if the car is moving toward the center (meaning the derivative value will be negative), the car's steering angle will get smoothed out, leading to a more smoother driving experience. Too high of a coefficient leads to almost constant steering angle changes of large degrees, where although the car will be well-centered it can hardly move. Too low of a D coefficient will lead to the oscillations being too high with more overshooting.


## Reflections
The P controller causes the car to move toward the cente of lane, but the reversal happens slowly and hence it overshoots. Similarly when it tries to correct the overshoot, it again result in overshooting in other direction. This causes oscillation around the centre line and the oscillation increases in magnitude at the turn of the road, causing the car to go out of the lane. 

Initially I tried with larger values of Kp but the car was always going out of the lane. Then I tried incorporating PD Controller which result in stabilizing the car(by reducing oscillation). As a result, the car was able to traverse for a few extra distance. But no matter how much I increase D Controller, the car always went out of the lane.

Then I used PID controller to correct bias, but it also did not work. On the contrary it increased the oscillations and the car quickly went out of the lane.

Getting a good value for Kp and Kd parameter was difficult. The key moment came when I realized that kp has to be very small compared to Kd. With this condition, the car was able to successfully navigate the lane. At this stage I tried to incorporate Ki, but it always resulted in taking the car out of the lane(due to oscillations). Again, the key moment came when I realized that Ki has to be extremely small (close to zero). Infact, having a small value of Ki reduces oscillation and result in better driving experience. The impact of small value of Ki is evident from the table below, where we can see that the squared cross track error(CTE) is minimized.

It was very difficult to manually get the coefficients of the PID controller because they vary widely in their range (from 6 to 0.0003). Once successfull to get the initial coefficients(3, 0.3, 0.0003) that can drive the car around the simulated track, I then used squared CTE to tune the parameters to get the least error. The following table gives the value of the coefficient and the squared CTE for one complete lap:

| Kd    | Kp     | Ki      | squared cte|
| ----- |:------:| -------:| -----------|
| 3     | 0.3    | 0.0006  | 3574       |
| 3     | 0.2    | 0.0006  | 1595       |
| 3     | 0.2    | 0.0003  | 1468       |
| 3     | 0.2    | 0.0004  | 1483       |
| 4     | 0.2    | 0.0003  | 1306       |
| 4     | 0.3    | 0.0003  | 1304       |
| 4     | 0.3    | 0.0004  | 1350       |
| 4     | 0.25   | 0.0003  | 1147       |
| 4.5   | 0.25   | 0.0003  | 1125       |
| 5     | 0.25   | 0.0003  | 1076       |
| 5.5   | 0.25   | 0.0003  | 1069       |
| 6     | 0.25   | 0.0003  | 1011       |
| 6.5   | 0.25   | 0.0003  | 997        |
| 7     | 0.25   | 0.0003  | 1012       |
| 6.5   | 0.2    | 0.0003  | 1193       |
| 6.5   | 0.2    | 0       | 1391       |     

As per above table, the minimum value of squared CTE is when Kp=0.25, Ki = 0.0003 and Kd=6.5. These are the parameters I have used in my code (line 37-40 in main.cpp)
