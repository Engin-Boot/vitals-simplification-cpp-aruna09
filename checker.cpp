#include <assert.h>

float MinBPM[] = {70};
float MaxBPM[] = {150};
float MinSpo2[] = {90};
float MinRespRate[] = {30};
float MaxRespRate[] = {95};

class AlertInSms{
  public:
    void SendAlert(const char* vitalName, const char* Message){
      std::cout<<"Alert! "+vitalName+"breached";
}
class AlertInSound{
  public:
    void SendAlert(const char* vitalName, const char* Message){
      std::cout<<"Alert! "+vitalName+"breached";
}
  
class BpmCheck: public VitalCheck
{
  public:
    bool checkVitalIsOk(float value) override
    {
      if(value<MinBPM[0])
        SendAlert("BPM", "Value less than Min BPM");
      if(value>MaxBPM[0])
        SendAlert("BPM", "Value more than Max BMP");
    }
};
  
class spo2Check: public VitalCheck
{
  public:
    bool checkVitalIsOk(float value) override
    {
      if(value<Minspo2[0])
        SendAlert("Spo2", "Value less than Min Spo2");
    }
};
  
class RespRateCheck: public VitalCheck
{
  public:
    bool checkVitalIsOk(float value) override
    {
      if(value<MinRespRate[0])
        SendAlert("Respiration Rate", "Value less than Min RespRate");
      if(value>MaxRespRate[0])
        SendAlert("Respiration Rate", "Value more than Max RespRate");
    }
};
class VitalCheck{
  public:
  virtual bool checkVitalIsOk(float value) = 0;
};

int main() {
  VitalCheck vitalcheck = new VitalCheck();
  
  assert(checkVitalIsOk(80, 60, 100) == true);
  assert(checkVitalIsOk(60, 40, 90) == true);
  assert(checkVitalIsOk(3, 40, 90) == false);
  assert(checkVitalIsOk(15, 20, 50) == false);
}
