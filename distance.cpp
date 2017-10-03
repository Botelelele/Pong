#include "functions.h"
#include <cmath>


bool distance(int x1,int y1, int x2, int y2, float r)
{
    float* distance=new float;
   *distance=std::sqrt(std::pow(x1-x2,2)+std::pow(y1-y2,2));
    if(*distance<=r)
    {
        delete distance;
        return true;
    }
    else{delete distance;return false;}
    return false;
}
