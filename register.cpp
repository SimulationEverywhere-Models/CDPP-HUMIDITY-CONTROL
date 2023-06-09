

#include "modeladm.h"
#include "mainsimu.h"
#include "CompareTemp.h"
#include "CompareHumidity.h"
#include "ProcessorTwo.h"
#include "Memory.h"
#include "PatientInfo.h"
#include "SeasonAndTimeGen.h"
#include "ProcessorOne.h"

void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CompareTemp>(), "CompareTemp" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CompareHumidity>(), "CompareHumidity" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ProcessorTwo>(), "ProcessorTwo" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Memory>(), "Memory" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PatientInfo>(), "PatientInfo" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<SeasonAndTimeGen>(), "SeasonAndTimeGen" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ProcessorOne>(), "ProcessorOne" ) ;
}

