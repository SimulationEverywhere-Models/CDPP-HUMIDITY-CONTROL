#ifndef __Memory_H
#define __Memory_H


#include "atomic.h"     // class Atomic

class Memory : public Atomic {
public:
	Memory(const string &name = "Memory" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &tempIn;			//input port
	const Port &humidIn;		//input port
	Port &tempOut, &humidOut;        //port1 for heater/conditioner; port2 for humidifier
	double temp;
	double humid;
	Time PreparationTime;

};

inline
string Memory::className() const
{
	return "Memory" ;
}

#endif   //__ProcessorTwo_H
