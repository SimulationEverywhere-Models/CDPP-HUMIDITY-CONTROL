[top]
components : compareTemp@CompareTemp



in : in1 in2
out : tempDiff1

Link : in1 tempSensor@CompareTemp
Link : in2 tempSetting@CompareTemp
Link : tempDiff@CompareTemp tempDiff1


[compareTemp]
preparation : 00:00:5:000 




