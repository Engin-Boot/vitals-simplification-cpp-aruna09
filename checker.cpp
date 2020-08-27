#include <assert.h>

float MinBPM[] = {70};
float MaxBPM[] = {150};
float MinSpo2[] = {90};
float MinRespRate[] = {30};
float MaxRespRate[] = {95};

// bool checkbpm(float bpm){
//   return(bpm>MinBPM[0] && bpm<MaxBPM[0]);
// }
// bool checkspo2(float spo2){
//   return(spo2>MinSpo2[0]);
// }
// bool checkRespRate(float respRate){
//   return(respRate>MinRespRate[0] && respRate<MaxRespRate[0]);
// }

bool vitalsAreOk(float value, float low, float high) {
  return (value>low && value<high);
}

int main() {
  assert(vitalsAreOk(80, 60, 100) == true);
  assert(vitalsAreOk(60, 40, 90) == true);
  assert(vitalsAreOk(3, 40, 90) == false);
  assert(vitalsAreOk(15, 20, 50) == false);
}
