[top]

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
components : pp@ProcessorTwo
components : ch@CompareHumidity

in : in1 in2 in3 in4
out : SPort1 SPort2

Link : in1 tempSensor@ct
Link : in2 tempSetting@ct
Link : in3 humiditySetting@ch
Link : in4 humiditySensor@ch
Link : port1@pp SPort1
Link : port2@pp SPort2
Link : tempDiff@ct tempDiff1@pp
Link : humidDiff@ch humidDiff1@pp

[ct]
preparation : 00:00:03:000 
[ch]
preparation : 00:00:03:000 
[pp]
preparation : 00:00:03:000 
