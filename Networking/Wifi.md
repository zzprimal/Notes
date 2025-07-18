# Wifi
Wifi is a wireless networking technology that allows users to connect to a wireless local area network (WLAN) and if that WLAN is connected to the internet allows that user to get access to the internet, wifi is the main way how all communication is done on WLANs with each WLAN having a main access point (AP) which facilitates all communication between devices connected to it and also communication to the internet. Wifi usually transmits radio waves at 2.4GHz, 5GHz, and 6GHz in the electromagnetic radiation spectrum, these frequencies a router uses for it's radio waves is called a band, these bands are further split up into channels which are ranges of frequencies that we use to communicate on this band. For example the 2.4GHz band has 14 channels with frequency ranges for each channel being as follows...

- channel 1: 2401–2423MHz
- channel 2: 2406–2428MHz
- channel 3: 2411–2433MHz
- channel 4: 2416–2438MHz
- channel 5: 2421–2443MHz
- channel 6: 2426–2448MHz
- channel 7: 2431–2453MHz
- channel 8: 2436–2458MHz
- channel 9: 2441–2463MHz
- channel 10: 2446–2468MHz
- channel 11: 2451–2473MHz
- channel 12: 2456–2478MHz
- channel 13: 2461–2483MHz
- channel 14: 2473–2495MHz

Hosts and the AP then uses one of these channels to choose communication on, notice that some of these channels overlap which can cause interference between radio waves transmitted at frequencies that are part of multiple channels since the radio waves can interfere with eachother messing up the data that was carried in the 2 radio waves transmitted at that frequency (as we'll see with qam its possible to extract data from 2 carrier waves that interfere but this requires the 2 hosts communicating to specify in the Protocol to do so and also even if that is done now host to AP communication will be sending 2 carrier waves so if the waves from 2 hosts to the AP interfere it will be the combination of 4 carrier waves and we'll have no way to isolate the individual data), thats why using only channels 1, 6, and 11 are recommended since these are the most amount of channels that can be used without suffering the consequence of interference. If interference does occur some reliable data transfer Protocol in the link layer (aka a MAC Protocol) needs to be used like for example CSMA/CA. Unfortunately carrier waves of different frequencies can combine into a single carrier waves, but fortunately for us they do not interfere meaning the individual waves of each frequency can be recovered from this combined carrier wave via fast fourier transformations (FFT). 

A good question is how do channels make use of the range of frequencies that are available to them, why are a range of frequencies necessary for communication when we are not using frequency based modulation since we can just do communication on one constant frequency, the answer is more bandwidth, the more available frequencies a channel has the more carrier waves they are able to send at different frequencies hence the more data that is able to be sent so increased bandwidth, so the channels are split into smaller frequency ranges that are used for communication between hosts, but each of these carrier waves at different frequencies split the channel frequency range into smaller ranges, this is because the frequency of the carrier wave can change during transmission so this smaller range is to account for the fact that radio waves can have their frequency change mid travel, and to also possibly account for the fact that we can only transmit radio waves at a certain percision of accuracy for frequency values.

## Multiplexing
Multiplexing refers to the process of splitting the transmission of data of multiple data streams over a single shared channel, ideally we would like to share the channel equally over all data streams (assuming no QoS), there are multiple methods for multiplexing and they are as follows...

### FDM (Frequency Division Multiplexing)
This multiplexing techniques splits a channel into smaller frequency ranges that will be used by each individual data stream (or potentially by multiple data streams if more bandwidth is needed), and between each frequency range there is what we call a guard band which is also just a small frequency range inbetween each frequency range that is left unused, this guard band is to help prevent interference (?) between 2 of the smaller bands

### TDM (Time Division Multiplexing)
This multiplexing techniques allows each data stream to use a channel at its full throughput (The method to maximize the throughput of data a data stream gets is unclear (TODO can't find an answer), but each data stream will have access to the full width of the channel) but splits the time using the channel among the data streams, usually time is split into a unit of time called frames and each data stream uses the full throughput of the channel for that frame time period then for the next frame another data stream gets to use the full throughput of the channel

### OFDM (Orthogonal Frequency Division Multiplexing)
This multiplexing techniques

## Modulation and Demodulation:
Modulation and Demodulation is the process of turning bits on wires/data into radio waves (modulation) which then the host receives and then transforms the radio waves back into bits on wires/data (demodulation), some modulation and demodulation techniques are as follows

### QAM (Quadrature Amplitude Modulation)
This modulation technique takes advantage of the fact that you can recover the amplitudes of 2 carrier waves that have the same frequency aslong as they are out of phase from eachother at all times (meaning the peaks of 1 wave corresponds with the lows of the other), this modulation technique uses this fact to send 2 carrier waves at the same frequency that are out of phase from eachother, then during demodulation the amplitudes of the 2 waves are extracted from the combined radio wave and used to select a bit pattern which communicates the data being sent, this can be thought of as the 2 amplitudes being corrdinates on a 2 dimensional graph which whatever point that is created on the graph by the 2 amplitudes will be whatever bit pattern that was intended to be sent.

### AM (Amplitude Modulation)
This modulation technique

## Wifi Network Security
All data that travels through a WLAN using wifi (IEEE 802.11 standard) is usually encrypted which is up to the network owner, if they decide to not encrypt all trafic on their network the network is called open, if they do decide to encrypt to encrypt all trafic on their network the network is called secured. On secured networks no user not apart of the network is able to see the trafic on the network above layer 2 (the data link layer, meaning the payload of the data link layer is all encrypted so outside users not part of the network is unable to see the ip addresses of individual devices and port numbers and such), but users apart of the network will be able to see this info since they have access to the encryption key, while on open networks all users are able to see this info regardless of whether or not they are part of the network. In this section we will discuss the different encryption Protocols that have been used in the past and present to encrypt WLANs, some of these encryption techniques are as follows...

### WEP
WEP was the first Wifi security technique to ever be introduced to WLANs in 1997 which supported 64-bit and 128-bit keys and is now depreciated because of its lack of security and it being easily hackable for outside users of the network to decrypt traffic inside the network. WEP uses the RC4 cipher to encrypt traffic in the network, the RC4 cipher is a stream cipher that generates a key stream that is xored with the bits that are meant to be encrypted, the key stream is generated through a process of shuffling an array of 256 integers going from 0 to 255 (notice this covers all possible values for a byte), then randomly selecting values from that shuffled array, adding that to the key stream, then keep shuffling until you generate the required length for the keystream to encrypt the message, this process of shuffling also involves a key which is the password of the wifi network. A problem with this is that the keystream generated is always the exact same for messages of identical length which makes the key more supseptible to cryptanalysis by giving the attacker a large number of examples of encryption using the key, a solution came up to solve this problem was to change the amount of bits required for the key from 64 bits to 40 bits and fill the remaining 24 bits with an initialization vector (IV) which would be a random sequence of 24 bits generated for each frame that is sent and the IV would be sent with the frame unencrypted so the receiver can unenrypt the contents of the frame in combination with the already known 40 bit key, this adds extra protection by reducing the amount of examples the attacker will have of encryption with an identical key by randomizing the IV for each frame sent, but unfortunately this wasn't sufficient as 24 bits only equates to 16,777,216 possibilities which is trivial for computers and so spamming enough traffic in the network can allow an attacker to get many examples of encryption using an identical key and hence recover the actual key of the network. WEP in 2005 was demostrated to easily be cracked in 3 minutes, now days you can use a tool like Aircrack-ng to crack WEP networks and get access, since then WEP has been depreciated for it's insecurity and afterwards replaced by WAP.

### WAP
WAP was meant as a temporary solution for the insecurity of WEP to support the hardware that WEP runs on via a software update and WAP provides 3 new security features to help increase the security of WEP, these new security measures were called TKIP and were meant as an upgrade to the security of the old hardware that ran WEP while newer and safer security Protocols were being developed that required better networking hardware. The 3 extra security measures that TKIP added to WEP were as follows...
- Instead of the IV being mearly concatenated to the key in WEP then using that to run the RC4 algorithm, instead a mixing function was implemented that mixes the IV with the key so now it was much harder to get the actual key of the network from the key of the RC4 algorithm
- A sequence counter is now implemented to prevent replay attacks where an attacker saves a packet sent on the network and replays it in hopes of getting some sort of response from the recepient that the attacker can maliciously use,

### WAP2

### WAP3









