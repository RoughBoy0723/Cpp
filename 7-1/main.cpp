#include <iostream>

using namespace std;
//생성자 생성

class car{
private:
    int gasolineGauge;

public:
    int GetGasGauge(){
        return gasolineGauge;
    }
};

class HybridCar : public car{
private:
    int electriGauge;
public:
    int ShowCurrentGauge(){
        return electriGauge;
    }
};

class HybridWaterCar : public HybridCar{
private:
    int waterGauge;
public:
    void ShowCurrentGauge(){
        cout << "잔여 가솔린" << GetGasGauge() <<endl;
        cout << "잔여 전기량" << GetElecGauge() <<endl;
        cout << "잔여 워터량" << waterGauge <<endl;
    }
};

int main(void){

}