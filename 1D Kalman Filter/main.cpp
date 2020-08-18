//
//  main.cpp
//  1D Kalman Filter
//
//  Created by PavanKumar on 18/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <tuple>

using std::cout;
using std::endl;
using std::tuple;

 

class priorBelief{
protected:
    double mean = 20.0;
    double variance = 9.0;
};

class measurementBelief{
protected:
    double mean = 30.0;
    double variance = 3.0;
};

class KalmanOneD :  priorBelief, public measurementBelief{
public:
    tuple<double, double> measurementUpdate();
    tuple<double, double> statePrediction(double mean, double variance);
private:
    double posteriorMean{0};
    double posteriorVariance{0};
};

tuple<double, double> KalmanOneD :: measurementUpdate(){
    
    posteriorMean = (measurementBelief::variance * priorBelief::mean + priorBelief::variance * measurementBelief::mean) / (measurementBelief::variance + priorBelief::variance);
    posteriorVariance = 1 / (1 / measurementBelief::variance + 1 / priorBelief::variance);
    
    printf("[%f, %f]\n", posteriorMean, posteriorVariance);
    return std::make_tuple(posteriorMean, posteriorVariance);
}

tuple<double, double> KalmanOneD :: statePrediction(double mean_, double variance_){
    
    /*After the measurement update is the state prediction step where the posterior belief obtained after the measurement update step becomes the prior belief fro the state prediction step. */
    
    priorBelief::mean = posteriorMean;
    priorBelief::variance = posteriorVariance;
    
    posteriorMean = priorBelief::mean + mean_;
    posteriorVariance = priorBelief::variance + variance_;
    
    printf("[%f, %f]\n", posteriorMean, posteriorVariance);
    return std::make_tuple(posteriorMean, posteriorVariance);
}

int main(int argc, const char * argv[]){
    
   KalmanOneD k1d;

   k1d.measurementUpdate();
    
   /* Let teh Robot execute the command of move forwatd by 7.5mts. Result is a gaussian distribution centered arounf the mean of 7.5 and variance 5(say). */
    double motionCommandMean = 7.5;
    double motionCommandVariance = 5;
    
    k1d.statePrediction(motionCommandMean, motionCommandVariance);
    return 0;
    
}
