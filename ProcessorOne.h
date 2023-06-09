
#ifndef __ProcessorOne_H
#define __ProcessorOne_H


#include "atomic.h"     // class Atomic

class ProcessorOne : public Atomic {
public:
	ProcessorOne(const string &name = "ProcessorOne" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &timeIn;			//input port from SeasonAndTimeGen
	const Port &seasonIn;		//input port from SeasonAndTimeGen
	const Port &peopleIn;		//input port from PatientInfo
	Port &tempOut, &humidOut;   //output port to Temperature controller
	int numPatient;
	int calcTemp;
	int calcHumid;
	int time;
	int season;
	Time PreparationTime;

};

inline
string ProcessorOne::className() const
{
	return "ProcessorOne" ;
}

#endif   //__ProcessorTwo_H
