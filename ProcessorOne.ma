[top]
components : pOne@ProcessorOne

in : seasonIn1 timeIn1 peopleIn1
out : tempOut1 humidOut1

Link : seasonIn1 seasonIn@pOne
Link : timeIn1 timeIn@pOne
Link : peopleIn1 peopleIn@pOne
Link : tempOut@pOne tempOut1
Link : humidOut@pOne humidOut1

[pOne]
preparation : 00:00:05:000 



