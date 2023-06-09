[top]
components : cH@CompareHumidity



in : in1 in2
out : humidDiff1

Link : in1 humiditySensor@cH
Link : in2 humiditySetting@cH
Link : humidDiff@cH humidDiff1


[cH]
preparation : 00:00:5:000 




