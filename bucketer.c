#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  
  //iterating over the chargeCycleCounts array for the number of batteries present in it
  for(int i=0; i<nBatteries; i++){
    if(cycles[i]<400) // increments the number of low counts only if it is less than 400
        counts.lowCount+=1; // accesses and increments the struct variables
    else if(cycles[i]>400 && cycles[i]<=919) //increments the number of medium counts if it is in given range
        counts.mediumCount+=1;
    else
        counts.highCount+=1; // increments the number of high counts counts only if it is more than or equal to 920
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
