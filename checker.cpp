#include <assert.h>
#include<iostream>
using namespace std;

float MinBPM[] = {70};
float MaxBPM[] = {150};
float MinSpo2[] = {90};
float MinRespRate[] = {30};
float MaxRespRate[] = {95};

class Alert
{
  public:
    virtual void SendAlert(const char* vitalName, const char* Message) = 0;
};
class AlertInSms: public Alert
{
  public:
    void SendAlert(const char* vitalName, const char* Message)
    {
      std::cout<<vitalName<<": "<<Message<<endl;
    }
};
class AlertInSound: public Alert
{
  public:
    void SendAlert(const char* vitalName, const char* Message)
    {
      std::cout<<vitalName<<": "<<Message<<endl;
    }
};


 void checkRespRateIsOk(Alert *alert, float value)
    {
      if(value<MinRespRate[0])
        alert->SendAlert("Respiration Rate", "is lower than the minimum limit");
      else if(value>MaxRespRate[0])
        alert->SendAlert("Respiration Rate", "is higher than the maximum value");
      else
        alert->SendAlert("Respiration Rate", "is normal");
    }

    void checkSpo2IsOk(Alert *alert,float value)
    {
      if(value<MinSpo2[0])
        alert->SendAlert("Spo2", "is less than minimum.");
      else
        alert->SendAlert("Spo2", "is in range");
    }

    void checkBPMIsOk(Alert *alert,float value)
    {
      if(value<MinBPM[0])
        alert->SendAlert("BPM", "Below minimum range.");
      else if(value>MaxBPM[0])
        alert->SendAlert("BPM", "Higher than maximum");
      else
        alert->SendAlert("BPM", "is in range");
    }
void checkAllVitals(float bpm, float spo2, float respRate)
{
      Alert *alert = new AlertInSms();

      checkBPMIsOk(alert, bpm);
      checkRespRateIsOk(alert, respRate);
      checkSpo2IsOk(alert, spo2);
}


int main() 
{
  checkAllVitals(10,20,30);
  return 0;
}
