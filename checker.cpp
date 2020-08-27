#include <assert.h>

int MinBPM = 70;
int MaxBPM = 150;
int MinSpo2 = 90;
int MinRespRate = 30;
int MaxRespRate = 95;

bool checkbpm(float bpm){
  return(bpm>MinBPM && bpm<MaxBPM);
}
bool checkspo2(float spo2){
  return(spo2>MinSpo2);
}
bool checkRespRate(float respRate){
  return(respRate>MinRespRate && respRate<MaxRespRate);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (checkbpm(bpm) && checkspo2(spo2) && checkRespRate(respRate));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
