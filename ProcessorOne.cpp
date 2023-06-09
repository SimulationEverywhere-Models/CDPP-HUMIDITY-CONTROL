#include "ProcessorOne.h"
#include "message.h"
#include "mainsimu.h"

//define constructor
ProcessorOne::ProcessorOne( const string &name ) : Atomic( name )
, timeIn( addInputPort( "timeIn" ) )
, seasonIn( addInputPort( "seasonIn" ) )
, peopleIn( addInputPort( "peopleIn" ) )
, tempOut( addOutputPort( "tempOut" ) )
, humidOut( addOutputPort( "humidOut" ) )
, PreparationTime( 0, 0, 5, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		 PreparationTime = time ;

}

Model &ProcessorOne::initFunction(){
	numPatient = 10;  //assume 10 people in hospital initially
	time = 9;	//assume 9am in the morning
	season = 0;	//assume in Spring
	calcTemp = 0;
	calcHumid = 0;
	this -> passivate();

	return *this;
}

Model &ProcessorOne::externalFunction( const ExternalMessage &msg ){

	if (this->state() == passive){
		if (msg.port() == seasonIn){
			season = msg.value();

			if (season == 0){
				if (time >= 0 && time < 8 && numPatient <= 100){
					calcTemp = 26;
					calcHumid = 50;
				}else if (time >= 0 && time < 8 && numPatient > 100){
					calcTemp = 25;
					calcHumid = 55;
				}else if (time >= 8 && time < 16 && numPatient <= 100){
					calcTemp = 24;
					calcHumid = 60;
				}else if (time >= 8 && time < 16 && numPatient > 100){
					calcTemp = 23;
					calcHumid = 65;
				}else if (time >= 16  && numPatient <= 100){
					calcTemp = 25;
					calcHumid = 67;
				}else if (time >= 16  && numPatient > 100){
					calcTemp = 24;
					calcHumid = 63;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}else if (season == 1){
				if (time >= 0 && time < 8 && numPatient <= 100){
					calcTemp = 20;
					calcHumid = 45;
				}else if (time >= 0 && time < 8 && numPatient > 100){
					calcTemp = 19;
					calcHumid = 42;
				}else if (time >= 8 && time < 16 && numPatient <= 100){
					calcTemp = 17;
					calcHumid = 50;
				}else if (time >= 8 && time < 16 && numPatient > 100){
					calcTemp = 15;
					calcHumid = 47;
				}else if (time >= 16  && numPatient <= 100){
					calcTemp = 21;
					calcHumid = 60;
				}else if (time >= 16  && numPatient > 100){
					calcTemp = 20;
					calcHumid = 63;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}else if (season == 2){
				if (time >= 0 && time < 8 && numPatient <= 100){
					calcTemp = 27;
					calcHumid = 65;
				}else if (time >= 0 && time < 8 && numPatient > 100){
					calcTemp = 26;
					calcHumid = 62;
				}else if (time >= 8 && time < 16 && numPatient <= 100){
					calcTemp = 25;
					calcHumid = 50;
				}else if (time >= 8 && time < 16 && numPatient > 100){
					calcTemp = 24;
					calcHumid = 57;
				}else if (time >= 16  && numPatient <= 100){
					calcTemp = 26;
					calcHumid = 60;
				}else if (time >= 16  && numPatient > 100){
					calcTemp = 25;
					calcHumid = 61;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}else if (season == 3){
				if (time >= 0 && time < 8 && numPatient <= 100){
					calcTemp = 28;
					calcHumid = 65;
				}else if (time >= 0 && time < 8 && numPatient > 100){
					calcTemp = 27;
					calcHumid = 62;
				}else if (time >= 8 && time < 16 && numPatient <= 100){
					calcTemp = 26;
					calcHumid = 50;
				}else if (time >= 8 && time < 16 && numPatient > 100){
					calcTemp = 25;
					calcHumid = 57;
				}else if (time >= 16  && numPatient <= 100){
					calcTemp = 24;
					calcHumid = 60;
				}else if (time >= 16  && numPatient > 100){
					calcTemp = 25;
					calcHumid = 60;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}
		}else if (msg.port() == timeIn){

			time = msg.value();

			if (time >= 0 && time < 8){
				if (season == 0 && numPatient <= 100){
					calcTemp = 24;
					calcHumid = 55;
				}else if (season == 0 && numPatient > 100){
					calcTemp = 23;
					calcHumid = 54;
				}else if (season == 1 && numPatient <= 100){
					calcTemp = 23;
					calcHumid = 53;
				}else if (season == 1 && numPatient > 100){
					calcTemp = 22;
					calcHumid = 52;
				}else if (season == 2 && numPatient <= 100){
					calcTemp = 21;
					calcHumid = 51;
				}else if (season == 2 && numPatient > 100){
					calcTemp = 20;
					calcHumid = 50;
				}else if (season == 3 && numPatient <= 100){
					calcTemp = 27;
					calcHumid = 60;
				}else if (season == 3 && numPatient > 100){
					calcTemp = 26;
					calcHumid = 59;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;

			}else if (time >= 8 && time < 16){
				if (season == 0 && numPatient <= 100){
					calcTemp = 23;
					calcHumid = 54;
				}else if (season == 0 && numPatient > 100){
					calcTemp = 23;
					calcHumid = 53;
				}else if (season == 1 && numPatient <= 100){
					calcTemp = 22;
					calcHumid = 52;
				}else if (season == 1 && numPatient > 100){
					calcTemp = 21;
					calcHumid = 52;
				}else if (season == 2 && numPatient <= 100){
					calcTemp = 20;
					calcHumid = 51;
				}else if (season == 2 && numPatient > 100){
					calcTemp = 19;
					calcHumid = 50;
				}else if (season == 3 && numPatient <= 100){
					calcTemp = 26;
					calcHumid = 59;
				}else if (season == 3 && numPatient > 100){
					calcTemp = 25;
					calcHumid = 58;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}else if (time >= 16){
				if (season == 0 && numPatient <= 100){
					calcTemp = 25;
					calcHumid = 57;
				}else if (season == 0 && numPatient > 100){
					calcTemp = 24;
					calcHumid = 55;
				}else if (season == 1 && numPatient <= 100){
					calcTemp = 21;
					calcHumid = 50;
				}else if (season == 1 && numPatient > 100){
					calcTemp = 20;
					calcHumid = 50;
				}else if (season == 2 && numPatient <= 100){
					calcTemp = 21;
					calcHumid = 52;
				}else if (season == 2 && numPatient > 100){
					calcTemp = 20;
					calcHumid = 55;
				}else if (season == 3 && numPatient <= 100){
					calcTemp = 27;
					calcHumid = 61;
				}else if (season == 3 && numPatient > 100){
					calcTemp = 26;
					calcHumid = 57;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}
		}else if (msg.port() == peopleIn){

			numPatient = msg.value();

			if (numPatient <= 100){
				if (season == 0 && time >= 0 && time < 8){
					calcTemp = 25;
					calcHumid = 57;
				}else if (season == 0 && time >= 8 && time < 16){
					calcTemp = 24;
					calcHumid = 55;
				}else if (season == 0 && time >= 16){
					calcTemp = 20;
					calcHumid = 49;
				}else if (season == 1 && time >= 0 && time < 8){
					calcTemp = 21;
					calcHumid = 50;
				}else if (season == 1 && time >= 8 && time < 16){
					calcTemp = 20;
					calcHumid = 50;
				}else if (season == 1 && time >= 16){
					calcTemp = 21;
					calcHumid = 52;
				}else if (season == 2 && time >= 0 && time < 8){
					calcTemp = 20;
					calcHumid = 55;
				}else if (season == 2 && time >= 8 && time < 16){
					calcTemp = 19;
					calcHumid = 53;
				}else if (season == 2 && time >= 16){
					calcTemp = 20;
					calcHumid = 58;
				}else if (season == 3 && time >= 0 && time < 8){
					calcTemp = 27;
					calcHumid = 61;
				}else if (season == 3 && time >= 8 && time < 16){
					calcTemp = 26;
					calcHumid = 57;
				}else if (season == 3 && time >= 16){
					calcTemp = 25;
					calcHumid = 58;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}else if (numPatient > 100){
				if (season == 0 && time >= 0 && time < 8){
					calcTemp = 24;
					calcHumid = 56;
				}else if (season == 0 && time >= 8 && time < 16){
					calcTemp = 23;
					calcHumid = 54;
				}else if (season == 0 && time >= 16){
					calcTemp = 19;
					calcHumid = 48;
				}else if (season == 1 && time >= 0 && time < 8){
					calcTemp = 20;
					calcHumid = 49;
				}else if (season == 1 && time >= 8 && time < 16){
					calcTemp = 19;
					calcHumid = 49;
				}else if (season == 1 && time >= 16){
					calcTemp = 20;
					calcHumid = 51;
				}else if (season == 2 && time >= 0 && time < 8){
					calcTemp = 19;
					calcHumid = 54;
				}else if (season == 2 && time >= 8 && time < 16){
					calcTemp = 18;
					calcHumid = 52;
				}else if (season == 2 && time >= 16){
					calcTemp = 19;
					calcHumid = 57;
				}else if (season == 3 && time >= 0 && time < 8){
					calcTemp = 26;
					calcHumid = 60;
				}else if (season == 3 && time >= 8 && time < 16){
					calcTemp = 25;
					calcHumid = 56;
				}else if (season == 3 && time >= 16){
					calcTemp = 24;
					calcHumid = 57;
				}
				holdIn(Atomic::active, PreparationTime );
				return *this;
			}
		}
	}
	return *this;
}


Model &ProcessorOne::internalFunction( const InternalMessage &msg ){

	passivate();
	return *this;
}

Model &ProcessorOne::outputFunction( const InternalMessage &msg ){

	sendOutput( msg.time(), this->tempOut, calcTemp);
	sendOutput( msg.time(), this->humidOut, calcHumid);
	return *this ;
}
