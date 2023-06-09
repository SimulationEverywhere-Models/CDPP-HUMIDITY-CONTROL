[top]
components : processorTwo@ProcessorTwo

in : inp1 inp2
out : Port1 Port2

Link : inp1 tempDiff1@ProcessorTwo
Link : inp2 humidDiff1@ProcessorTwo
Link : port1@ProcessorTwo Port1
Link : port2@ProcessorTwo Port2

[processorTwo]
preparation : 00:00:5:000 



