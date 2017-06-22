#include "PID.h"
#include <time.h>
#include <iostream>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	this->p_error = 0;
	this->i_error = 0;
	this->d_error = 0;

	this->previous_time = 0;
}

void PID::UpdateError(double cte) {
	double current_time = clock();
    double dt = (current_time - previous_time)/CLOCKS_PER_SEC;
    previous_time = current_time;

    std::cout << dt << std::endl;

	d_error = (cte - p_error) / dt; // Because p_error is actually the previous cte
	p_error = cte;
	i_error += cte * dt;
}

double PID::TotalError() {
	return -Kp * p_error - Ki * i_error - Kd * d_error;
}

