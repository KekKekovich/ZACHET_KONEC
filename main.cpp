#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>

using namespace std;

const int N=100;
double mu = 0;
double sigma = 10;
double sum;
double sum1;

double Gauss(double mu, double sigma, double x) {
    return (1/sigma/(sqrt(2*3.14)))*exp(-(x-mu)*(x-mu)/2/sigma/sigma);
}
double Rand (double fMin, double fMax){
    double f=(double)rand()/ RAND_MAX;
    return fMin+f*(fMax-fMin);
}


int main() {
    srand(time(0));
    vector <double> A;
    vector<double > X;
    for (double i=-10; i<11; i+=1) {
        A.push_back(Gauss(mu, sigma, i));
        X.push_back(i);
    }

    for (auto &x: A) {
        sum+=x;
    }
    //cout << "Summa bez normirovki: "<<sum << endl;

    map<double,double > map1;
    for (double i=0; i<A.size(); i++) {
        sum1+=(A[i]/sum);
        map1.emplace(sum1, X[i]);
        //cout <<sum1 << " | " << X[i]<< endl;
    }
    cout<<endl;

    vector <double> POINTS;
    for (int i = 0;i<N;i++) {
        POINTS.push_back(map1.lower_bound(Rand(0,1)) -> second);
        cout << POINTS[i] << ", ";
    }
    cout << endl;

    double Sum = 0;
    for (auto &x: POINTS) {
        Sum+=x;
    }
    double mean = Sum / N;
    cout <<"MU: " <<mean << endl;

    double var;
    for (auto &x: POINTS) {
        var+=(x-mean)*(x-mean);
    }
    cout <<"SIGMAKVADRAT:" <<var/(POINTS.size()-1) << endl;

    return 0;
}