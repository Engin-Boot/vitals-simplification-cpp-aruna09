#include <assert.h>

float MinBPM[] = {70};
float MaxBPM[] = {150};
float MinSpo2[] = {90};
float MinRespRate[] = {30};
float MaxRespRate[] = {95};

bool checkbpm(float bpm){
  return(bpm>MinBPM[0] && bpm<MaxBPM[0]);
}
bool checkspo2(float spo2){
  return(spo2>MinSpo2[0]);
}
bool checkRespRate(float respRate){
  return(respRate>MinRespRate[0] && respRate<MaxRespRate[0]);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (checkbpm(bpm) && checkspo2(spo2) && checkRespRate(respRate));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
