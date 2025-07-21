## Differential Signaling

## Single-ended Signaling

## Clock Signal
A clock signal is a consistent alternating voltage provided over a wire to synchronize 2 devices, this is used for so example so a receiving device knows what points in time the transmitting device is trying to convey what bits over a different wire (so the receiving device knows how long each bit takes to transmit), if this process isn't sychronized this can result in the receiving device getting wrong data. I²C is an example which uses clock signals, I²C is a serial communication bus standard that uses clock signals on one wire and sends the data on the other.

## Clock Recovery
Clock recovery is the process of recovering the clock timing using voltage changes in serial communication in response to clock drift, the receiving and transmitting device will usually be synchronized using something like a quartz oscillator for example oscilating at the same hertz, once some drift occurs the receiving device can look at a change of voltage in the serial communication so it can readjust the osciallator so it has the same "beat" timing as the transmitter.

## Short Circuit