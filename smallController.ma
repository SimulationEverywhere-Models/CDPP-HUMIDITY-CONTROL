[top]
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
preparation : 00:00:06:000 
[pp]
preparation : 00:00:10:000 


