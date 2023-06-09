#include "SeasonAndTimeGen.h"
#include "message.h"
#include "mainsimu.h"

//define constructor
SeasonAndTimeGen::SeasonAndTimeGen( const string &name ) : Atomic( name )
, seasonPort( addOutputPort( "seasonPort" ) )
, timePort( addOutputPort( "timePort" ) )
, PreparationTime( 0, 0, 3, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		 PreparationTime = time ;

}

Model &SeasonAndTimeGen::initFunction(){
	timeOfDay = 9;		//assume 9am in the morning
	season = 0;			//assume it's Spring
	count = 0;
	holdIn(Atomic::active, Time::Zero);
	//cout << "\nI am in init func";
	return *this;
}

Model &SeasonAndTimeGen::externalFunction( const ExternalMessage &msg ){
	return *this;  //since no inputs this function is empty
}

Model &SeasonAndTimeGen::internalFunction( const InternalMessage &msg ){
	//cout << "\nI am in internal func\n";
	this->timeOfDay = (++timeOfDay % 24);
	//cout << timeOfDay;
	//cout << "\n";
	//cout << "\njust before count increments";
	this->count = (count++ % 10);
	//cout << count;
	//cout << "\n";
	if (count == 10){  //For simulation purposes, season changes per 10 hours
		//cout << "\nseason changes here\n";
		this->season = (++season % 4);
		//cout << "I got season\n";
		//cout << season;
		//cout << "\n";
	}

	this -> holdIn(active, PreparationTime);
	return *this;
}

Model &SeasonAndTimeGen::outputFunction( const InternalMessage &msg ){
	sendOutput( msg.time(), this->seasonPort, season);
	sendOutput( msg.time(), this->timePort, timeOfDay);
	return *this ;
}
