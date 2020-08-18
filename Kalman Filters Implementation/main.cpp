//
//  main.cpp
//  Kalman Filters Implementation
//
//  Created by PavanKumar on 18/08/2020.
//  Copyright © 2020 PavanKumar. All rights reserved.
//

/* 1D Gaussian that calculates the probability occurrence of a value given a mean and a variance! of the distribution */

#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

class Gauss{
public:
    Gauss(double mn, double vr, double mnt) : mean(mn), variance(vr), measurement(mnt){}
    void calcGaussian();
private:
    double mean;
    double variance;
    double measurement;
};

void Gauss :: calcGaussian(){
    double prob = 1.0 / sqrt(2.0 * M_PI * variance) * exp(-0.5 * pow((measurement - mean), 2.0) / variance);
    cout << "Frequency of given measurement is : " << prob << endl;
}

int main(int argc, const char * argv[]) {
     
    Gauss gs(10.0, 4.0, 8.0);
    gs.calcGaussian();
    
    return 0;
}
