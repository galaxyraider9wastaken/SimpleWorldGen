#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> 

void CreateHeightMap(int length, int width, int Density, int SpreadChancex, int SpreadChancey, int RunTime){
  SpreadChancex += SpreadChancey;
  int HeightMap[length][width];
  for(int i=0;i<length;i++){
    for(int i1=0;i1<width;i1++){
      HeightMap[i][i1] = 0;
    }
  }
  for(int i =0;i<Density;i++){
    int z = (rand() % length) + 1;
    int x = (rand() % width) +1;
    HeightMap[z][x] +=1;
  }
  for(int i=0;i<RunTime;i++){
    for(int i1=0;i1<length;i1++){
      for(int i2=0;i2<width;i2++){
        if(HeightMap[i1][i2] >= 1){
          int ran = (rand() % 100) + 1;
          SpreadChancey -= HeightMap[i1][i2]-1;
          if(ran >= SpreadChancey && ran <= SpreadChancex){
            int ran1 = (rand() % 4) +1;
            if(i1 -1 >= 0 && i1 +1 < length && i2 -1 >= 0 && i2 +1 < width){
              if(ran1 == 1){
                if(HeightMap[i1-1][i2] <= HeightMap[i1][i2] + 1){
                  HeightMap[i1-1][i2] +=1;
                }
              }
              if(ran1 == 2){
                if(HeightMap[i1+1][i2] <= HeightMap[i1][i2] + 1){
                  HeightMap[i1+1][i2] +=1;
                }
              }
              if(ran1 == 3){
                if(HeightMap[i1][i2-1] <= HeightMap[i1][i2] + 1){
                  HeightMap[i1][i2-1] +=1;
                }
              }
              if(ran1 == 4){
                if(HeightMap[i1][i2+1] <= HeightMap[i1][i2] + 1){
                  HeightMap[i1][i2+1] +=1;
                }
              }
            }
          }
          if(ran <= SpreadChancey){
             HeightMap[i1][i2] +=1;
          }
        }
      }
    }
  } 
}
