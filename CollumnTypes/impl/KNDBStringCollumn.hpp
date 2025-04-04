#ifndef KNDBSTRINGCOLLUMN_H
#define KNDBSTRINGCOLLUMN_H

#include "../KNDBCollumnObject.hpp"

class KNDBStringCollumn : public KNDBCollumnObject {
  private:
    static inline char * object_code = "str";
    int object_length;
  
  public:
    KNDBStringCollumn(int length);
    char * getObjectCode();
    int getObjectLegnth();
    char * getObjectFlags();


};



#endif
