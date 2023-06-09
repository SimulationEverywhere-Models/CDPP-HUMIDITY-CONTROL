[top]
components : TC
components : po@ProcessorOne

in : season time people tSensor2 hSensor2
out : humidD condHeat

Link : season seasonIn@po
Link : time timeIn@po
Link : people peopleIn@po
Link : tSensor2 tSensor1@TC
Link : hSensor2 hSensor1@TC
Link : tempOut@po tempIn1@TC
Link : humidOut@po humidIn1@TC
Link : TPort1@TC condHeat
Link : TPort2@TC humidD

[po]
preparation : 00:00:03:000


[TC]
components : SC
components : memory@Memory

in : tSensor1 hSensor1 tempIn1 humidIn1
out : TPort1 TPort2

Link : tSensor1 in1@SC
Link : tempIn1 tempIn@memory
Link : humidIn1 humidIn@memory
Link : tempOut@memory in2@SC
Link : humidOut@memory in3@SC
Link : hSensor1 in4@SC
Link : SPort1@SC TPort1
Link : Sport2@SC TPort2

[memory]
preparation : 00:00:03:000

[SC]
components : ct@CompareTemp
components : pt@ProcessorTwo
components : ch@CompareHumidity

in : in1 in2 in3 in4
out : SPort1 SPort2

Link : in1 tempSensor@ct
Link : in2 tempSetting@ct
Link : in3 humiditySetting@ch
Link : in4 humiditySensor@ch
Link : port1@pt SPort1
Link : port2@pt SPort2
Link : tempDiff@ct tempDiff1@pt
Link : humidDiff@ch humidDiff1@pt

[ct]
preparation : 00:00:03:000 
[ch]
preparation : 00:00:03:000 
[pt]
preparation : 00:00:03:000 
