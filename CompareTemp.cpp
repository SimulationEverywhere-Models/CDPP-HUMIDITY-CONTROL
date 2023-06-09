#include "CompareTemp.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"
//define constructor
CompareTemp::CompareTemp( const string &name ) : Atomic( name )
, tempSensor( addInputPort( "tempSensor" ) )
, tempSetting( addInputPort( "tempSetting" ) )
, tempDiff( addOutputPort( "tempDiff" ) )
, PreparationTime( 0, 0, 5, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		 PreparationTime = time ;


}
Model &CompareTemp::initFunction(){
	this->passivate();
	TempDiff = 0;
	TempQue[0] = 1000;
	TempQue[1] = 1000;
	return *this;
}
Model &CompareTemp::externalFunction( const ExternalMessage &msg ){

	//if the message is from sensor and nothing from tempSetting wait store value
	if ( this->state() == passive){
		if (msg.port() == tempSensor){
			TempQue[0] = msg.value();
			if(TempQue[1] != 1000){
				TempDiff = TempQue[0] - TempQue[1];
				holdIn(Atomic::active, PreparationTime );
			}
		}else if (msg.port() == tempSetting){
			TempQue[1] = msg.value();
			if(TempQue[0] != 1000){
				TempDiff = TempQue[0] - TempQue[1];
				holdIn(Atomic::active, PreparationTime );
			}
		}
	}



	return *this;

}
Model &CompareTemp::internalFunction( const InternalMessage &msg ){
	passivate();
	return *this;
	}

Model &CompareTemp::outputFunction( const InternalMessage &msg ){
		this->sendOutput( msg.time(), tempDiff , TempDiff) ;
		return *this ;
}





