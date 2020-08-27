#include <assert.h>

bool checkbpm(int min, int max, int bpm){
  return(bpm>min && bpm<max);
}
bool checkspo2(int min, int spo2){
  return(spo2<min);
}
bool checkRespRate(int min, int max, int respRate){
  return(respRate>min && respRate<max);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (checkbpm && checkspo2 && checkRespRate);
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
