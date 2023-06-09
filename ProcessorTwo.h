
#ifndef __ProcessorTwo_H
#define __ProcessorTwo_H


#include "atomic.h"     // class Atomic

class ProcessorTwo : public Atomic {
public:
	ProcessorTwo(const string &name = "ProcessorTwo" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &tempDiff1;		//input port
	const Port &humidDiff1;
	Port &port1, &port2;        //port1 for heater/conditioner; port2 for humidifier
	int onOFF[2];
	Time PreparationTime;

};
inline
string ProcessorTwo::className() const
{
	return "ProcessorTwo" ;
}

#endif   //__ProcessorTwo_H
