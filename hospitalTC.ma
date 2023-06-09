[top]
components : sAT@SeasonAndTimeGen
components : pI@PatientInfo
components : pO@ProcessorOne
components : SC
components : TC

in : tSensor0 hSensor0
out : condHeat humidD

Link : seasonPort@sAT seasonIn@pO
Link : timePort@sAT timeIn@pO
Link : infoOut@pI peopleIn@pO
Link : tSensor0 tempIn1@TC
Link : hSensor0 humidIn1@TC
Link : tempOut@pO tempIn1@TC
Link : humidOut@pO humidIn1@TC
Link : TPort1@TC condHeat
Link : TPort2@TC humidD

[sAT]
preparation : 00:00:03:000
[pI]
preparation : 00:00:03:000
[pO]
preparation : 00:00:03:000

[TC]
components : SC
components : memory@Memory

in : tSensor tempIn1 humidIn1 hSensor 
out : TPort1 TPort2

Link : tSensor in1@SC
Link : tempIn1 tempIn@memory
Link : humidIn1 humidIn@memory
Link : tempOut@memory in2@SC
Link : humidOut@memory in3@SC
Link : hSensor in4@SC
Link : SPort1@SC TPort1
Link : Sport2@SC TPort2

[memory]
preparation : 00:00:03:000

[SC]
components : ct@CompareTemp
components : pT@ProcessorTwo
components : ch@CompareHumidity

in : in1 in2 in3 in4
out : SPort1 SPort2

Link : in1 tempSensor@ct
Link : in2 tempSetting@ct
Link : in3 humiditySetting@ch
Link : in4 humiditySensor@ch
Link : port1@pT SPort1
Link : port2@pT SPort2
Link : tempDiff@ct tempDiff1@pT
Link : humidDiff@ch humidDiff1@pT

[ct]
preparation : 00:00:03:000 
[ch]
preparation : 00:00:03:000 
[pT]
preparation : 00:00:03:000 
