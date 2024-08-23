#include <iostream>

using namespace std;
//생성자 생성

class car{
private:
    int gasolineGauge;

public:
    //car():gasolineGauge(0){}
    car(int n):gasolineGauge(n){
        cout << "car(int n)\n";
    }

    int GetGasGauge(){
        return gasolineGauge;
    }
    
    // ~car(){
    //     cout << "Delete car\n";
    // }
};

class HybridCar : public car{
private:
    int electriGauge;
public:
    //HybridCar():electriGauge(0){}
    //HybridCar(int n):electriGauge(n){}
    HybridCar(int a, int b):car(a),electriGauge(b){
        cout << "HybridCar(int a, int b)\n";
    }

    int GetElecGauge(){
        return electriGauge;
    }
    // ~HybridCar(){
    //     cout << "Delete HybridCar\n";
    // }
};

class HybridWaterCar : public HybridCar{
private:
    int waterGauge;
public:
    // HybridWaterCar():waterGauge(0){}
    // HybridWaterCar(int n):waterGauge(n){}
    HybridWaterCar(int a, int b, int c):HybridCar(a, b),waterGauge(c){
        cout << "HybridWaterCar(int a, int b, int c)\n";
    }

    void ShowCurrentGauge(){
        cout << "잔여 가솔린: " << GetGasGauge() <<endl;
        cout << "잔여 전기량: " << GetElecGauge() <<endl;
        cout << "잔여 워터량: " << waterGauge <<endl;
    }
    // ~HybridWaterCar(){
    //     cout << "Delete HybridWaterCar\n";
    // }
};

int main(void){
    HybridWaterCar HWC(20,30,40);
    HWC.ShowCurrentGauge();
    return 0;
}


//nf-ripa