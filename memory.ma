[top]
components : memory@Memory

in : tempIn1 humidIn1
out : tempOut1 humidOut1


Link : tempIn1 tempIn@Memory
Link : humidIn1 humidIn@Memory
Link : tempOut@Memory tempOut1
Link : humidOut@Memory  humidOut1

[memory]
preparation : 00:00:5:000 


