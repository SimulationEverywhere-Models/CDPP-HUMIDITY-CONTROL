
#ifndef __CompareTemp_H
#define __CompareTemp_H


#include "atomic.h"     // class Atomic

class CompareTemp : public Atomic {
public:
	CompareTemp(const string &name = "CompareTemp" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &tempSensor;		//input port
	const Port &tempSetting;		//output port
	Port &tempDiff;
	int TempDiff;
	int TempQue[2];
	Time PreparationTime;

};
inline
string CompareTemp::className() const
{
	return "CompareTemp" ;
}

#endif   //__COMPARETEMP_H
