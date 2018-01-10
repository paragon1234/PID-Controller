#include<iostream>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
        //cout << "Init" << Kp_ << " " << Ki_ << " " << Kd_ << endl;
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

        mse = 0.0;
}

void PID::UpdateError(double cte) {
        //cout << "Update" << cte << endl;
        mse += cte*cte;
	d_error = cte - p_error;
	p_error = cte;
	i_error += cte;
}

double PID::TotalError() {
	double temp = -Kp*p_error - Kd*d_error - Ki*i_error;
        cout << "totalError" << Kp << " " << Kd << " " << Ki << " " << p_error << " " << d_error << " " << i_error << " " << temp << " " << mse << endl;
        return temp;
}

