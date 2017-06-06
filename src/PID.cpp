#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp = Kp;
	Ki = Ki;
	Kd = Kd;
}

void PID::UpdateError(double cte) {
	p_error = - Kp * cte;
	i_error = - Ki * (i_error + cte);
	d_error = - Kd * (cte - d_error);
}

double PID::TotalError() {
	return p_error + i_error + d_error;
}

