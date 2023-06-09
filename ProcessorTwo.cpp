#include "ProcessorTwo.h"
#include "message.h"
#include "mainsimu.h"

//define constructor
ProcessorTwo::ProcessorTwo( const string &name ) : Atomic( name )
, tempDiff1( addInputPort( "tempDiff1" ) )
, humidDiff1( addInputPort( "humidDiff1" ) )
, port1( addOutputPort( "port1" ) )  //port1 is used for temp output
, port2( addOutputPort( "port2" ) )  //port2 is used for humidity output
, PreparationTime( 0, 0, 5, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		 PreparationTime = time ;

}

Model &ProcessorTwo::initFunction(){
	onOFF[0] = 2;
	onOFF[1] = 2;
	this -> passivate();
	return *this;
}

Model &ProcessorTwo::externalFunction( const ExternalMessage &msg ){
	if (this->state() == passive){
		if (msg.port() == tempDiff1){
			if (msg.value() < 0){
				onOFF[0] = 0;  //heater on/conditioner off
				cout<<"heater on"<<"\n";
			}else if (msg.value() > 0){
				onOFF[0] = 1;  //conditioner on/heater off
				cout<<"conditioner on"<<"\n";
			}else{
				onOFF[0] = 2;  //conditioner off/heater off
				cout<<"off"<<"\n";
			}
			holdIn(Atomic::active, PreparationTime );
			return *this;
		}else if (msg.port() == humidDiff1){
			if (msg.value() < 0){
				onOFF[1] = 0; //humidifier off
				cout<<"humidifier off"<<"\n";
			}else{
				onOFF[1] = 1;  //humidifier on
				cout<<"humidifier on"<<"\n";
			}
			holdIn(Atomic::active, PreparationTime );
			return *this;
		}
	//else if ( this->state()==active){
	//		Time dif = ( msg.time() - this->lastChange() ) ;
	//}
	}
	return *this;
}

Model &ProcessorTwo::internalFunction( const InternalMessage &msg ){
	passivate();
	return *this;
}

Model &ProcessorTwo::outputFunction( const InternalMessage &msg ){
	sendOutput( msg.time(), port1, onOFF[0]);
	sendOutput( msg.time(), port2, onOFF[1]);
	return *this ;
}
