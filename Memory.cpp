#include "Memory.h"
#include "message.h"
#include "mainsimu.h"
#include "iostream.h"

//define constructor
Memory::Memory( const string &name ) : Atomic( name )
, tempIn( addInputPort( "tempIn" ) )
, humidIn( addInputPort( "humidIn" ) )
, tempOut( addOutputPort( "tempOut" ) )
, humidOut( addOutputPort( "humidOut" ) )
, PreparationTime( 0, 0, 5, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		 PreparationTime = time ;

}

Model &Memory::initFunction(){
	temp = 0;
	humid = 0;
	this -> passivate();
	return *this;
}

Model &Memory::externalFunction( const ExternalMessage &msg ){
if (this->state() == passive){

		if (msg.port() == tempIn ){
			temp = msg.value();
			cout<<"temperature is "<<temp<<"\n";
			holdIn(Atomic::active, PreparationTime );
		}

		 if (msg.port() == humidIn){
			humid = msg.value(); //humidifier off
			 cout<<"humidity is "<<humid<<"\n";
			holdIn(Atomic::active, PreparationTime );
		}

}
	return *this;
}

Model &Memory::internalFunction( const InternalMessage &msg ){
	passivate();
	return *this;
}

Model &Memory::outputFunction( const InternalMessage &msg ){
	sendOutput( msg.time(), tempOut, temp);
	sendOutput( msg.time(), humidOut, humid);
	return *this ;
}
