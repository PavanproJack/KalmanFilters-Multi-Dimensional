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

double postMean, postVariance;

class priorBelief{
protected:
    int mean = 10;
    int variance = 8;
};

class measurementBelief{
protected:
    int mean = 13;
    int variance = 2;
};

class KalmanOneD :  priorBelief, public measurementBelief{
public:
    tuple<double, double> measurementUpdate();
};

tuple<double, double> KalmanOneD :: measurementUpdate(){
    
    postMean = (measurementBelief::variance * priorBelief::mean + priorBelief::variance * measurementBelief::mean) / (measurementBelief::variance + priorBelief::variance);
    postVariance = 1 / (   1 / (measurementBelief::variance) +  1 / (priorBelief::variance)  );
     
    return std::make_tuple(postMean, postVariance);
}

int main(int argc, const char * argv[]){
    
   KalmanOneD k1d;
    
        std::tie(postMean, postVariance) = k1d.measurementUpdate();
        printf("[%f, %f]", postMean, postVariance);
        return 0;
    
}
