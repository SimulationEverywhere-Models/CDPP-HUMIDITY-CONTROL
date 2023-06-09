#include "CompareHumidity.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"

//define constructor
CompareHumidity::CompareHumidity( const string &name ) : Atomic( name )
, humiditySensor( addInputPort( "humiditySensor" ) )
, humiditySetting( addInputPort( "humiditySetting" ) )
, humidDiff( addOutputPort( "humidDiff" ) )
, PreparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" ) PreparationTime = time ;

}

Model &CompareHumidity::initFunction(){
	//this->holdIn(Atomic::active,Time::Zero);
	this->passivate();
	HumidDiff = 0;
	HumidQue[0] = 1000;
	HumidQue[1] = 1000;
	return *this;
}

Model &CompareHumidity::externalFunction( const ExternalMessage &msg ){

	//if the message is from sensor and nothing from tempSetting wait store value
	if ( this->state() == passive){
		if (msg.port() == humiditySensor){
			HumidQue[0] = msg.value();
			if(HumidQue[1] != 1000){
				HumidDiff = HumidQue[0] - HumidQue[1];
				holdIn(active, PreparationTime );
			}
		}else if (msg.port() == humiditySetting){
			HumidQue[1] = msg.value();
			if(HumidQue[0] != 1000){
				HumidDiff = HumidQue[0] - HumidQue[1];
				holdIn(active, PreparationTime );
			}
		}
	}


	//Time dif = ( msg.time() - this->lastChange() ) ;


return *this;

}

Model &CompareHumidity::internalFunction( const InternalMessage &msg ){
	passivate();
	return *this;
	}

Model &CompareHumidity::outputFunction( const InternalMessage &msg ){
		sendOutput( msg.time(), humidDiff, HumidDiff) ;
		return *this ;
	}
