
#include "KNDBStringCollumn.hpp"

KNDBStringCollumn::KNDBStringCollumn(int length) {
  this -> object_length = length;
}

char * KNDBStringCollumn::getObjectCode(){
  return this -> object_code;
}
int KNDBStringCollumn:: getObjectLegnth(){
  return this -> object_length;
}


