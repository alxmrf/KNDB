#ifndef KNDBCollumnObject_H
#define KNDBCollumnObject_H


class KNDBCollumnObject {
public:
    virtual char * getObjectCode() = 0;
    virtual int getObjectLegnth() = 0;
    virtual ~KNDBCollumnObject() = default;
};


#endif
