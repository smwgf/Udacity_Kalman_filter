#include <iostream>
#include <sstream>
#include <vector>
#include "Eigen/Dense"
#include "ukf.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main() {

	// Create a UKF instance
	UKF ukf;

	/**
	* Programming assignment calls
	*/
	MatrixXd Xsig_aug = MatrixXd(7, 15);
	ukf.AugmentedSigmaPoints(&Xsig_aug);

	MatrixXd Xsig_pred = MatrixXd(15, 5);
	ukf.SigmaPointPrediction(&Xsig_pred);

	VectorXd x_pred = VectorXd(5);
	MatrixXd P_pred = MatrixXd(5, 5);
	ukf.PredictMeanAndCovariance(&x_pred, &P_pred);

	VectorXd z_out = VectorXd(3);
	MatrixXd S_out = MatrixXd(3, 3);
	ukf.PredictRadarMeasurement(&z_out, &S_out);

	VectorXd x_out = VectorXd(5);
	MatrixXd P_out = MatrixXd(5, 5);
	ukf.UpdateState(&x_out, &P_out);

	std::string text;
	std::cin >> text;
	std::cout << text;
	return 0;
}