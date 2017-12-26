#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>

using namespace std;

const int N=1000;
double mu = 0;
double sigma = 10;
double sum;
double sum1;

double Gauss(double mu, double sigma, double x) {
    return (1/sigma/(sqrt(2*3.14)))*exp(-(x-mu)*(x-mu)/2/sigma/sigma);
}
double Randd (double fMin, double fMax){
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



    for (double i=0; i<A.size(); i++) {
        cout <<"density: " << A[i] << endl;
    }
    for (double i=0; i<A.size(); i++) {
        sum+=A[i];
    }
    cout << "Summa bez normirovki: "<<sum << endl;



    map<double,double > map1;
    for (double i=0; i<A.size(); i++) {
        sum1+=(A[i]/sum);
        map1.emplace(sum1, X[i]);
        cout <<"   "<<sum1 << endl;
    }
    cout<<endl;

    vector <double> POINTS;

    for (int i = 0;i<N;i++) {
        double r = Randd(0,1);
        double xx = 0;
        for (auto &x: map1) {
            if (x.first > r) {
                xx = x.second;
                POINTS.push_back(xx);
                break;
            }
        }
        cout<<r<<"   "<<xx<<endl;
    }

    double Sum = 0;
    for (double i=0; i<POINTS.size(); i++) {
        Sum += POINTS[i];
    }
    double mean = Sum/POINTS.size();
    cout << mean << endl;

    double var;
    for (double i=0; i<POINTS.size(); i++) {
        var+= ((POINTS[i]-mean)*(POINTS[i]-mean));

    }
    cout << var/(POINTS.size()-1) << endl;



    return 0;
}