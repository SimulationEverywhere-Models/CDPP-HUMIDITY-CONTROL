
#ifndef __CompareHumidity_H
#define __CompareHumidity_H


#include "atomic.h"     // class Atomic

class CompareHumidity : public Atomic {
public:
	CompareHumidity(const string &name = "CompareHumidity" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &humiditySensor;		//input port
	const Port &humiditySetting;		//output port
	Port &humidDiff;
	int HumidDiff;
	int HumidQue[2];
	Time PreparationTime;

};
inline
string CompareHumidity::className() const
{
	return "CompareHumidity" ;
}

#endif   //__COMPAREHUMIDITY_H
