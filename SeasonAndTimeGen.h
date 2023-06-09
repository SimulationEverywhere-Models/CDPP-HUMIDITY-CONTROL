
#ifndef __SeasonAndTimeGen_H
#define __SeasonAndTimeGen_H


#include "atomic.h"     // class Atomic

class SeasonAndTimeGen : public Atomic {
public:
	SeasonAndTimeGen(const string &name = "SeasonAndTimeGen" );					//Default constructor
	virtual string className() const;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port &seasonPort, &timePort;        //output ports
	int season;        //0:spring, 1:summer, 2:fall, 3:winter
	int timeOfDay;		  //Only hours of a day is meaningful to this model
	int count;
	Time PreparationTime;

};
inline
string SeasonAndTimeGen::className() const
{
	return "SeasonAndTimeGen" ;
}

#endif   //__ProcessorTwo_H
