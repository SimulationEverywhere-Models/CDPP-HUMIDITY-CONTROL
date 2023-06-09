
#ifndef __PatientInfo_H
#define __PatientInfo_H



#include "atomic.h"     // class Atomic

class PatientInfo : public Atomic {
public:
	PatientInfo(const string &name = "PatientInfo" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	//const Port &inPort;		//input port
	Port &infoOut;          //output port to processor1
//	port &peopleOut;		//output port for people leaving
	int count;
//	int initial;		//initial number of patients in hospital
//	Distribution *distribution;
	Time PreparationTime;

};
inline
string PatientInfo::className() const
{
	return "PatientInfo" ;
}

#endif   //__ProcessorTwo_H
