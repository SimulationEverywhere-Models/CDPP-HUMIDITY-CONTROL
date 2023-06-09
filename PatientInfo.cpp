#include "PatientInfo.h"
#include "message.h"
#include "mainsimu.h"
#include <stdlib.h>

//define constructor
PatientInfo::PatientInfo( const string &name ) : Atomic( name )
, infoOut( addOutputPort( "infoOut" ) )
, PreparationTime( 0, 0, 20, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		 PreparationTime = time ;

}

Model &PatientInfo::initFunction(){
	this -> count = 200;
	this -> holdIn(Atomic::active, Time::Zero);
	return *this;
}

Model &PatientInfo::externalFunction( const ExternalMessage &msg ){
	return *this;
}

Model &PatientInfo::internalFunction( const InternalMessage &msg ){
	int r = rand() % 10;
	if (r < 5){		//assume 50% people coming in and 50% people going out
		this->count = count + (rand() % 20);
	}else{
		int d = rand() % 20;
		if (count - d > 0){
			this->count =  this->count - d;
		}else{
			this->count = 0;
			this -> passivate();
		}
	}

	this->holdIn(active, PreparationTime);
	return *this;
}

Model &PatientInfo::outputFunction( const InternalMessage &msg ){
	sendOutput( msg.time(), infoOut, count);
	return *this ;
}
