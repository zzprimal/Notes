# 2.1 Common Ports
## TCP
- 20-21 FTP (File Transfer Protocol): transfering files between hosts, 20 is usually used for active data transfer and 21 used for control where the control port is used to initialize the data transfer and communicate to the server commands to control the data transfer and 21 is used to transfer the actual data, the reason why 2 ports are used instead of only 1 is because FTP was originally built ontop of NCP which is a transportation Protocol that uses 2 port numbers for 2 way communication instead of a single port number, but after TCP and UDP took over the 2 port numbers werent necessary anymore, but FTP was never altered and still stayed because of backwards compatibility issues aswell

- 22 SSH (Secure Shell): used to make a secure shell connection from a client to a server so the client can remotely control a server via a shell

- 23 TELNET: telnet is a non-secure version of ssh which gives you shell access to a system but over an unsecure connection (atleast if you connect to port 23, the telnet client can also be used though to send application layer data to any application accepting tcp connections)

- 25 SMTP (Simple Mail Transfer Protocol): SMPT is a push Protocol to push data onto a server, more specifically a mail server, can be used by a user agent to push a new email onto their local mail server then said mail server can use SMTP to push that email to the mail server of the receiving recepient

- 80 HTTP (Hyper Text Transfer Protocol): HTTP is the application Protocol of the world wide web and is used by web servers and clients to communicate and transfer hyper text documents to eachother (usually coded in html)

- 110 POP3 (Post Office Protocol 3): pull Protocol to retreive email from a user agents mail server

- 143 IMAP4 (Internet Message Access Protocol 4): pull Protocol to retreive email from a user agents mail server

- 139 SMB/NETBIOS session service (Network Basic Input/Output System): NETBIOS is a old protocol used in many layers of the OSI model in the past (it initially implemented from the link layer to the Session layer, then Network to the Session, and now just only the Session layer after it was taken over by other protocols like TCP and IP), its the protocol that is used by SMB (Server Message Block) for example and was used for computers over a local network to communicate with eachother. The session service of NETBIOS opens up a session between 2 computers and acts as a interface for the 2 computers to interact and offers TCP like communication to deliver messages to the application layer. Connecting to this port will create a connection with a SMB application over NETBIOS via NETBIOS sessions

- 389 LDAP (Lightweight Directory Access Protocol): LDAP is a protocol used to access directory services that possibly exists in an organization/intranet for example, directory services is a database that contains data related to a bunch of important information related to the network for the organization, a directory service maps a specific piece of information to a ip address so the user knows where to get said information (possibly needs more research).

- 443 HTTPS (Hyper Text Transfer Protocol Secure): just the secure version of HTTP that uses TLS to add encryption protection

- 445 SMB/NETBIOS or NETBIOS-LESS (Network Basic Input/Output System): This is just SMB implemented over TCP/IP as opposed to what it was originally implemented over which was NETBIOS (which is why it is called NETBIOS-LESS)

- 3389 RDP (Remote Desktop Protocol): RDP is a protocol developed by microsoft to remotely access a computer, and unlike something like ssh or telnet it gives you a full GUI for the computer you are remotely connecting to

## UDP
- 53 DNS (Domain Name System): DNS is used to resolve hostnames to ip addresses so a client can find what server it is supposed to be communicating with on the web for example when a url is clicked

- 67-68 DHCP (Dynamic Host Configuration Protocol): DHCP is a Protocol used by devices trying to join a local network to obtain an ip address by communicating with the DHCP server of said network to request a ip address, the DHCP server contains a pool of ip addresses that are free or occupied and gives you a free one on a lease, once that lease expires the client is required to either renew the lease or get a new ip address. can also use DHCP reservation on the DHCP server to always reserve a static ip address for a device's network interface 

- 137 NETBIOS name service (Network Basic Input/Output System): Refer to "NETBIOS session service" for explanation of what NETBIOS is, in order to create a session each system must register a NETBIOS name and the name service provides the means to do so and also other things related to names like deletion, finding names, etc. The name service also tells what kind of service a system offers if you establish a session with said system (more research needed)

# 2.2 Wireless Network Technologies

## 802.11/Wifi
802.11/Wifi provides standards for wirelessly connecting a device to an access point which will then give you connectivity to other devices, these standards determines things like frequency ranges used for wireless communication, how modulation and multiplexing works, the number and ranges for channels, etc. Frequency ranges of 802.11 standards are usually 2.4GHz, 5GHz, and 6GHz, the higher the frequency ranges used the higher the bandwidth since the higher frequency ranges are designed to have more channel but also more cycles per second means the more data that can be encoded per second aswell (assuming you are using proper modulation techniques which i'm assuming higher Wifi standards does so), you can also increase the width of your channels allowing for higher bandwidths to be achieved by each individual channel. The lack of channels on 2.4GHz that don't interfere with eachother are only 3 so on networks with alot of devices this will cause interference and possibly delays (though this is helped with protocals like CSMA for example)

## Bluetooth
Bluetooth provides short distance communication between devices and uses the 2.4GHz range aswell just like 802.11, it achieves this short ranges communication by putting less power/watts into the signal which transmits a weaker signal (weaker signal is correlated or maybe equivalent to the amplitude of the signal/wave). Bluetooth ranges mostly operate at a range of 10 meters.

# RFID (Radio-Frequency Identification)
RFID is used as a identification system to tell a person the identity of someone/something, a RFID tag is attached to said someone/something and when a RFID reader is used it transmits a radio wave which then the RFID tag can use the energy from said radio wave to transmit back a radio wave encoding information of the identity of said someone/something back to the RFID reader, a radio wave (or radio frequency) powers the tag, and the tag returns back the identity, hence why it's called RFID. Some RFID tags do contain some source of power source so ontop of the energy gotten from the received radio waves it can use power from the power source to transmit stronger radio waves so communication with RFID readers can be achieved from a greater distance, these are called "active tags" while the former were called "passive tags".

# NFC (Near Field Communication)
NFC is a set of communication protocols that allow communication between devices of a distance of around 4cm or less, NFC is commonly used in things like paying with tap, and opening doors wirelessly with keycards for example. NFC also helps bootstrap (help startup) other wireless protocols like bluetooth by finding the correct parameters needed to connect to a bluetooth network. NFC uses radio waves at frequencies of 3.56MHz for communication and provides data rates from 106 to 848 Kbits/s. NFC can also enable wireless charging aswell allowing devices to charge up to 1W of power over distances of up to 2cm (im assuming converting the energy radio waves to power is done to achieve this though i don't know the details) which is ideal for devices where space is a critical resource since NFC only needs small atennas.

# 2.3 Network Services

## DNS Server (Domain Name System Server)
DNS servers are responsible for mapping domain names to ip addresses so we can find what host we need to communicate with to satisfy a specific request, this is DNSs main purpose but it also provides and can be used for other services aswell, for example getting the opposite mapping (ip address to hostname) is one of them. DNS is a distributed platform (multiple interconnected devices working together to perform a specific task) with DNS servers being in the magnitude of thousands with loads being split across said servers mainly via domain names, so a group of DNS servers will be responsible for requests for a specific type of domain name and another group for a different type of domain name (ex. TLD servers where some are responsible for domain names ending in .com and others for .ca). DNS servers are usually managed by your service provider or if youre part of a sufficiently large organization the IT department for that organization.

## DHCP Server (Dynamic Host Configuration Protocol Server)
DHCP is the protocol responsible for assigning an ip address to a devices network interface so it can communicate with a network. A DHCP server provides this service to a device for a network (usually a LAN) and allows automatic assigning of ip addresses to said device. Your home private will usually have only 1 DHCP server (usually located in your SOHO router), enterprises on the other hand will usually contain multiple to connect to their network so there isn't a single point of failure.

## File Sharing Services
File Sharing Services provides centeralized storage of documents and files so you and other people can use to share, like mentioned in section 2.1 for example there are ports the you can use to connect to applications running the SMB protocol which you can then use to then share files with

## Print Server
Can add a printer to your network to provide printing as a network service, sometimes a printer can have a network card that can connect to your network which you can then use the ip address of the printer to connect to and communicate with your printer to do the printing tasks you need, or you can connect to a computer that is connected to a printer and the computer will then contain some software that communicates with the printer which then you can communicate with. There are a number of protocols which you can use to communicate with a printer to do your printing, ones listed and talked about are SMB (Server Message Block), IPP (Internet Printing Protocol), LPD (Line Printer Daemon)

## Mail Server
Mail Servers provide mail functionality so users can use email to communicate with other users, mail servers are usually managed by your ISP or by an IT department of some enterprise. Mail servers store your email messages that you received and also acts as a proxy for email messages that you are sending which the mail server sends to the mail server of the recepient, you can then retreive your email from a mail server using protocols like IMAP and HTTP for example.

## Syslog
Syslog is a protocol used for conveying event notification messages, if you have a bunch of devices you are managing (routers, switches, firewalls, etc) and you want to log relevant events that happen on these devices (example on a firewall packets that were dropped would be a good example) syslog is a protocol that you can use to do this. You can have each of these devices send these log messages via the syslog protocol to a central database on your network which can store all the log messages for the devices on your network which then you can access later, this central database is called a SIEM (Security Information and Event Manager). Depending on the scale of your network and how many devices are using the syslog protocol the SIEM is going to need alot of disk space to store all these log messages.

## Webserver
Webservers provide web services, more specifically they provide hypertext documents via the html language which are fetched via the http (hypertext transfer protocol), these are then used to usually browse the internet :).

## Authentication/AAA Server
A authentication server or a AAA server (Authentication, Authorization, and Accounting) like says in the name authenticates the user to see if the user has permission to access resources on a network, once the user has entered the proper credentials the authentication server will then approve the user by giving a cryptographic ticket which can then be used to access needed services on the network. In enterprises usually there will be a buch of Authentication servers so if one goes down you can still access eterprise services.

## Database servers
A database server stores data which then a user can access, usually these databases format their data in a relational database (tables with attributes that can be related to eachother) which you can then access and query data from using a language like SQL.

## NTP/Time servers (Network Time Protocol Server)
NTP servers are used to get accurate time measurements for your computers. There are NTP servers which keep track of time via a multitude amount of methods (could be using another NTP server, or an atomic clock) which then NTP clients send a request to to get the proper current time, the client will occasionally resend a request to the NTP server to resynchronize it's clock. On windows systems the time server that windows communicates with is time.windows.com which windows will synchronize with occasionally then your computers RTC (Real Time Clock, which usually uses a crystal oscillator at a constant frequency to convert oscillations to seconds) will keep track of seconds and update the clock every second.

## Spam Gateways
Spam gateways is a server that lies in front of your local mail server and messages from other mail servers and determines whether the message is spam or not, if it is it is either discarded or put in a seperate spam inbox for example (depending on how your spam gateway is setup).

## All in One Security Appliance
Commonly also called a Unified Thread Management, Next Generation Firewall, or a Web Security Gateway it is a device that sits between your network and the internet and provides alot of functionality to protect you from the internet, things like url filtering, malware inspection, spam filtering, CSU/DSU (i don't know what this is, research), can be a router and a switch, a firewall, etc.

## Load Balancer
Load Balancers are a useful tool for your service if your service is under demand, if a service you are providing under demand you can have multiple servers provide said service and balance the load of requests for your service between the servers evenly using a load balancer, that way one server won't get overwhelmed and cause subsequent requests to that server for the service to be slow. A load balancer is responsible for seeing the current load on the servers it is managing and redirecting the request to one of the servers who are currently the least occupied, it acts as a inbetween point for the client and the server that will serve the clients request. Having a load balancer allows your service to be fault tolerant to for example a server outage since the load balancer can just redirect client requests to a different server.

## Proxy Server
Proxy servers submits requests to servers on behalf of clients so it can provide protection for clients, protection are things like hiding your ip address from servers since it submits requests to servers using it's ip address, content scanning aswell to see if the content sent from the server is safe to send to the client, and possibly other protections. Proxy servers also provide other services to clients though things like caching maybe, and also location changing aswell so you can access services that are only available in specific countries or areas.

## SCADA/ICS (Supervisory Control and Data Aquisition System/Industrial Control System)
SCADA/ICS is a remote control system used to control usually a bunch of equipment in a plant environment usually and also keep track of data on said equipment so you can adjust the equipment using said information (need more research, look at Ignition SCADA).

## Legacy and Embedded System
Legacy and Embedded Systems can be the systems that are providing an important service for a network and because they are providing important services Legacy Systems can't be replaced with newer and uptodate systems, because of this it is important to know how to maintain Legacy Systems. For Embedded Systems and maintaining them you usually won't have access to the OS that is managing the resource of said system so it can be hard to troubleshoot, but the manufacturer should've provided you with the necessary instructions required to maintain said system nonetheless.

## IOT Devices (Internet of Things Devices)
IOT devices are just any devices that can connect and exchange data with other devices over a network. Usually this term is used to refer to devices that historically did not really use the internet but now can to transmit specific data about the device, things like sensors, gadgets, appliances, and smart devices are some examples (more research).

# 2.4.1 DNS Configuration
DNS servers like previously mentioned are meant to map domain names to ip addresses. You send a packet using the DNS protocol containing the hostname you want to resolve and using transportation layer protocol UDP on port 53, and you get a DNS response containing the ip address of that hostname. DNS is a distributed database with multiple servers supporting it across the world and uses a hierchy of DNS servers to satisfy your request with your request going through the hierchy to find the ip address for the hostname you want. The hierchy is as follows, if your request is not cached in your local DNS server first your request will go to a root DNS server which will then respond with the ip address of a TLD DNS server which will then redirect you to a authoritive DNS server which will respond to your request with the proper ip address. DNS servers contain what we call resource records and is what is used to satisfy client requests and also provide other services aswell, the resource records for DNS servers are as follows...

- Type A: These records contain a mapping from a hostname to a ipv4 address that can be used to communicate with the server

- Type AAAA: These records contain a mapping from a hostname to a ipv6 address that can be used to communicate with the server

- Type MX: These records specify the hostname of a mail server associated to the hostname in the request, used for when your mail server needs to send a email to another mail server so the recepient can recieve your email

- Type CNAME: These records specify the cannonical name of a hostname which can be interpretted as the "read name" of the hostname, this can be useful if you want services for your hostname to refer to the same server for example (urls are formated as "<service>.<hostname>", so you can have all such hostnames with a service part in it have their canonnical name be a hostname with only the hostname part but no service part which will allow all services to refer to the same server)

- Type TXT: These records are just public text records that anyone can read that might have useful information associated to a host name, some common information that were put in these records were things like the public key of the hostname (to prevent spoofing attacks via signing with private keys, specifically used for DKIM), or SPF (Sender Policy Framework) which just specifies what servers are allowed to send mail for a specific domain, if either one of the previous verification methods failed the mail server can then consult in a DMARC TXT record (Domain-based Message Authentication Reporting, and Conformance) which will tell the recepient what the actual owner of the hostname would like you to do. 


DNS records can also specify an additional TTL which is how long this record will stay in caches.

# 2.4.2 DHCP
In the past you would have to manually configure the ip address of your network interface card to be able to communicate with other devices on a network, this obviously causes issues especially in large networks with alot of devices since you don't know what device have what ip addresses and what ip addresses are free, this is where DHCP comes to the rescue. DHCP allows automatic assignment of ip addresses to devices that join the network and the DHCP server takes care of all the overhead of making sure there are no duplicate ip adresses for example so users don't have to worry about it. DHCP uses a process called DORA (Discover Offer Request Acknowledge) to give devices ip addresses and happens every time a new device joins a network, a more verbose explanation of the process is as follows...

- Discover: User attempts to discover a DHCP server to get an ip address by transmitting a broadcast DHCP Discover message

- Offer: DHCP server responds with an offer to the Discover DHCP message which states the ip address it is lending to the client and also how long it is lending it to the client (the lease) using the Offer DHCP message

- Request: User requests the ip address that was offered in the previous Offer DHCP message for use by sending a Request DHCP message, its also possible that the user was sent multiple DHCP Offer messages from multiple servers so it has to specify which server's offer it is accepting via the server identification option in the DHCP protocol (since the request message is sent as a broadcast message for some reason and not directly to the DHCP server that gave the offer)

- Acknowledge: The DHCP server acknoledges the users Request DHCP message with a Acknowledge DHCP message which signifies that the user now is assigned to this ip address and now the DHCP server can mark this ip address as occupied by this user by pairing the users mac address with this ip address internally

DHCP servers also contain something called a DHCP scope which is a list of ip addresses for a network that can be used (DHCP pool), excluded ip addresses on that network that can't be used, and also just general options for your DHCP server (things like subnet, lease duration, ip address reservations, and what is the DNS server, VOIP server, and default gateway of the network are examples). A DHCP server can also be responsible for assigning ip addresses to possibly multiple different subnets, if this is the case the DHCP server will have multip DHCP scopes, one for every subnet it is managing ip addresses for. Another service that DHCP also provides is something called address reservation which allows a ip address to be reserved for a specific device so that no other device can take this ip address, and every time this device re-joins the network it will be assigned this ip address which the DHCP server keeps track of by pairing mac addresses with ip addresses in a reservation table.

# 2.4.3 VLANS and VPNS

## LANS (Local Area Network)
LANS are defined as a group of devices on the same broadcast domain, meaning that if a device that is part of a LAN broadcasts a message on that LAN all the devices that broadcast message reaches is considered a part of the LAN

## VLANS (Virtual Local Area Network)
VLANS are created when you split a single broadcast domain into multiple broadcast domains that are they're own network by adding a logical layer to your switch that is able to split it's interface between the multiple networks and able to keep them logically seperated, the networks will then be logically seperated but will still be using the same physical infastructure (aka the switch). You can also though have hosts be on the same VLAN even if they are connected to different switches since VLANS are implemented in software so aslong as the software has the proper software support everything should work.

## VPN (Virtual Private Network)
A VPN is a network which you can use to extend your current network by use of encrypted tunneling protocols (the VPN client puts in the application layer the full OSI packet meant for the VPN encrypted, then sends it to the VPN network) to get a packet from one network to the other. VPNs are used for personal use for security reasons and also for enterprise use for accessing an enterprises network from offsite. Something called a VPN concentrator is what manages VPN connections to the private network, the VPN concentrator is responsible for a multitude of tasks, things like encrypting packets going to the clients network and decrypting packets going to the VPNs network and routing them through the network, things like authenticating connection requests to the VPN and if proper credentials are given giving the clients device on their network an ip address for the VPN network, and probably more aswell.

# 2.5 Network Devices

## Routers
Routers as the name implies routes incoming network traffic to one of it's subnets on each interface so that the packet can arrive at it's destination, all routers work together to allow arriving packets to be able to travel to their proper destination. What interface the router decides to route the packet depends on the destination ip address of the packet and is called if it only unrolls the packet to layer 3 (network layer) a layer 3 switch. Routers also connect diverse and different link types aswell, it can change the link type from wireless radio waves to ethernet to coxial and to fiber for example.

## Switches
Switches are just layer 2 switches which only unrolls packets up to layer 2 to determine with interface to send the packet on by looking at the destination mac address. usually none of the switches interfaces will have mac addresses and is just an intermedian for a device to connect to multiple network interfaces of different devices with ip addresses. These layer 2 switches usually have tones of interfaces having maybe 24, 48, or maybe even 100, switches can also give PoE (Power over Ethernet) to devices that are connected to it, so connecting your device to a switch can also give your device power aswell.

## Unmanages Switches
Unmanaged switches are just switches that are just plug and play and require no additional configuration, they just work from the moment you plug it in, though these switches come at the disadvantage that there are 0 configuration options for the switch, so if you want to partition the interfaces to create VLANs you can't do so.

## Managed Switch
A managed switch is the complete opposite of the previously mentioned unmanaged switches and allows configuration options like the previously mentioned VLANs, certain traffic prioritization, port mirroring to capture all packet that go through switch, and external management through SNMP (Simple Network Management, Protocol) are some examples of configuration options.

## Access Point
A access point provides a method for devices to connect to a network wirelessly, to be clear an access point is not a router or a switch and can be its own standalone device though it can definitely be part of a router or switch, if the access point is not part of a router or a switch it is usually connected to a router or a switch and switches all packets it receives to said router or switch. As a standalone device it is usually used to connect a wired and a wireless network together to provide wireless access to said wired network. As a standalone device an AP is a layer 2 switch, so it will take a look at the mac address of the packet it receives and makes a decision how to forward it from there.

## Cable Infrastructure
Usually offices with cubicles will give wired internet to each cubicle by connecting one side of an ethernet cable to the desk obviously, and the other side to a punch down block located on a patch panel so the ethernet cable cannot be removed or moved, this simplifies knowing where a desk's ethernet cable is connected to, but complicates the process of connecting your computer to a different switch for example if you want access to another LAN or VLAN, the solution to this is having on the other side of the patch panel RJ45 connectors which are associated to each punched down ethernet cable that you can use to plug in another ethernet cable and connect to whatever LAN or VLAN you want.

## Path Panel
A patch panel is just a combination of punched down ethernet cables and associated with each one a RJ45 connector on the other side you can connect an ethernet cable to just like mentioned in the previous topic.

## Firewall
A firewall is a traffic filter for your network and will make decisions on what to do with said traffic using a multitude of filtering options. Some examples are filtering based on port numbers, ip addresses, and some firewalls use the application layer message to make filtering decisions aswell. Firewalls can be used aswell for a VPN concentrator for encrypting and decrypting the application layer message which contains the OSI model packet for the network (tunneling). A firewall can also act as a proxy, hiding the ip address of the client from the server and also do traffic filtering like previously mentioned to detect malicious data or malware. Lastly firewalls can also be layer 3 devices aka routers, so ontop of all the mentioned previous tasks can also route your packets to whatever subnet that it should go to.

## PoE (Power over Ethernet)
PoE as said in the name gives power to devices over ethernet cables, is used for giving power to telephones for example, an access point on a ceiling, and other devices where adding more cables would be inconvenient. PoE is really nice since you can provide. If a device does not support giving power to another device over internet you can use a injector which plugs into a wall and has 2 RJ45 connectors one for the previously mentioned device, and the other for the device you want to give power. When PoE is coming from a switch itself it is called Endspan, and when it is coming over an injector it is called Midspan. Switches that support PoE are usually marked on switches themselves saying which specific interface supports PoE. There are 3 different for standards for PoE each providing different amount of power to devices, the 3 standards are PoE, PoE+, and PoE++ with each of these providing 15.4 watts of DC and 350 mA current, 25.5 watts of DC and 600 mA current, and 51 watts of DC and 600 mA current respectively (PoE++ has 2 different types and the stats we shown is for the worse type, the other type provides even more power)

## Cable Modem
A cable modem gives us internet access over a existing cable infrastructure that already exists that gives our houses cable, cable modems usually have a coxial cable connected to them which is connected to the cable infrastructure and also an ethernet port which is used to connect to usually your home SOHO router to give your house wifi. This method of giving wifi provides speeds up to 1 Gigabit/s, and since such high speeds are provided it is common to see this method of wifi and connection to the internet used in enterprises.

## DSL Modem
A DSL modem gives internet access over an existing telephone infrastucture that already exists to give our homes telephone access, DSL works by sending internet traffic over the same telephone cables that are meant for telephone traffic using some modulation technique (either FDM or TDM or some other modulation technique like QAM is used), the DSL modem then seperates the telephone and internet traffic and puts said traffic on the corresponding proper interface of the DSL modem. DSL provides download speeds of around 200 Mbits/s and upload speeds of 20 Mbits/s, but are limited in use since a CO (Centarl Office) needs to be close by (~10000 feet) for a DSL internet connection to work to receive the combined telephone and internet traffic from your house.

## ONT (Optical Network Terminal)
ONT provides internet to your house over a fiber optics infrastructure which is the fastest possible link type, ONT provides a way to convert the light from the fiber optics cable into electricity for the ethernet cable to provide internet to your house, and the other way around. The ONT is usually at a place called a demarcation point and is a box outside or inside a building's wall.

## NIC (Network Interface Card)
A NIC is a device that gives other devices access to a pre-existing network, these cards will have RJ45 connectors if you want to connect to a network over ethernet, or it can have an SMA connector that you can use to connect a wifi adapter to to get internet via wifi, or even interfaces to connect fiber optic cables to. A NIC can either be built into a device's motherboard, or it can be modular and be a seperate device that you can connect to another device's motherboard. Every device that can connect to a network has a NIC, whether that be printers, computers, phones, tablets, routers, switches, etc. A NIC card can obviously have multiple interfaces that you can use to connect to a network and since each of these interfaces are seperate each one of them will have their own MAC address.

# 2.6.1 IPv4 and IPv6

## IP addresses
IP addresses act like the phone numbers of a network and allow unique identification of devices in said network so a device with one ip address can send a packet to another device with a different ip address, routers will do the work of making sure the packet arrives at the other device using the ip address of the receiving device as a guide to determine where to send the packet. There are 2 types of IP addresses IPv4 and IPv6.

## IPv4 Address
An IPv4 address is just a 32 bit number split into 4 8 bit sections seperated by a period, a ipv4 address is usually formated by having a decimal numbers represent each of the sections which will be a decimal number between 0 and 255 inclusive (since this is the highest and lowest numbers 8 bits can represent). Each IPv4 address on a network is unique and can communicate with eachother, but because of scales of networks like the internet and the amount of devices that have ip addresses now (20 billion though not all of these are part of the same network) there is an ipv4 address exhaustion so we are running out of ipv4 addresses, like previously mentioned there are 20 billion devices with ip addresses but only 4.3 billion possible ip addresses, so how are each of the devices able to get an ip address, the answer is private networks and addresses.

## Private IP Addresses and Networks
Private networks and addresses allow devices to have the same ip address but have to be on different networks so they can't directly communicate with eachother over the internet unless other measures are made, these private networks will have a multitude of devices connected to them each having an ip address in the network, but in the context of the internet all these devices will only have 1 ip address given to the private network's gateway that will be used to communicate outside the network on the internet and using NAT to differentiate packets being received from the internet to determine which packet goes to which device on the network. The problem with this is that devices on different private networks cannot communicate with eachother (though not really a disadvantage since this provides protection from the internet) and devices on the private network have to initiate communication for NAT to work and devices outside the private network cannot initiate communication with devices in the network, but this helps mitigate the effects of the ipv4 shortage. The range of private addresses that are allowed for this is defined in RFC 1918 and it should be obvious but no device part of the internet network is allowed to have an ip address in this range since how would a router/gateway for a private network know which device to send a packet, the device with this ip address in it's own network, or the device on the internet.

## Public vs Private addresses
A private address is the same as previously mentioned and is just the ip address given to a device for being part of a private network, the public address of a device is just the ip address of the private network's gateway used for communicating on the internet.

## IPv6 address
IPv6 was another solution put in place to solve the IPv4 exhaustion crisis, this solution is pretty simple and was to just increase the bits we use for ip addresses and hence the amount, IPv6 as opposed to IPv4 now uses 128 bits so 4 times the bits of IPv4 and so now there are a total of 340282366920938463463374607431768211456 IPv6 addresses, or 324 undecillion which would be more than plenty to give each device an ip address to communicate by itself on the internet with no help. IPv6 addresses are usually split into 8 16 bit sections represented with 4 hexadecimal digits with each section seperated by a colon, you can also use double colons to seperate different sections which just means all sections inbetween are 0s. Since IPv6 addresses are much harder to memorize than IPv4 DNS now becomes a critical service. Subnetting is also not really needed to give much thought to since there are just so many ip addresses, usually the first 64 bits are the network address and the last 64 bits are the host address.

# 2.6.2 Assigning IP Addresses

## Networking with IPv4
As previously mentioned every device on an IPv4 network needs a unique ip address, but other things that are needed for networking using IPv4 are subnet masks which is a number formatted in the same way as ipv4 but tells us what bits of an ip address are the network and host bits (network bits determine what bits of an ip address stay static on the network while the host bits are the bits that are variable and differentiates the ip addresses on the network). Another thing that is needed is a default gateway which is the gateway for each device to the internet, this ip address must be constant as to allow devices to communicate with it and on a 192.168.1.0 network with subnet 255.255.255.0 usually has address 192.168.1.1.

## Static IP Addresses
Static ip addresses are like mentioned in the name just ip addresses that stays the same for a device. Configuring a static ip address can be done in 2 ways, either via the settings on the devices operating system, or via the DHCP server using DHCP reservation, DHCP reservation is definitely the better approach to this though since in a large network configurating static ip addresses would need to be down individualy going from device to device, using DHCP reservation in this situation would be much easier.

## APIPA (Automatic Private IP Addressing)
APIPA is a way to automatically give your device an ip address if getting one from a DHCP server for a network has failed (and this is the only case this happens, getting a APIPA address does not happen if you aren't connected to the internet, only when you try to connect to a network but fail to communicate with the DHCP server). Because getting an ip address via a DHCP server has failed you unfortunately won't be able to connect to the internet since you don't have access to a gateway, though APIPA still provides methods to communicate with other devices using APIPA aswell. Devices using APIPA to get an ip addresses will select a ip address in the range of 169.254.1.0 to 169.254.254.255 inclusive with subnet 255.255.255.0 (the remaining ip addresses in the subnet are reserved for "future use"), this selection is done randomly and once a ip address is selected the device will send an ARP request for a device with this ip address, if a response packet isn't received it is assumed that the ip address is unoccupied and the device takes said ip address, else the device will choose a new random ip address and this continued till no ARP response packet is received.

## Turning Dynamic Into Static
DHCP ip addresses are given out on a lease, and once that lease is up a possibly new ip address is given to your system, if this is unideal then using the methods mentioned in the Static IP addresses part can help change the dynamic ip address into a static one.

# 2.7.1 Internet Connection Types

## Satellite Networking
Like mentioned in the name satellite networking is a method to provide internet to a device via using a satellite as a gateway, satellite networking is relatively high cost in comparison to terrestrial networking but is very convenient and is able to provide internet to very remote sites where creating a terrestrial network is difficult. Satellite networking usually has 100 Mbit/s download and 5 Mbit/s upload, but staellite networking has pretty high latencies with some having 250ms to just send data up to the satellite and to receive data from the satellite, starlink advertises 25ms to 60ms latencies for communicating with the satellite and this is because these satellites are located much closer to earth than the satellites for other satellite networks. Satellite networking does have its fair share of problems though other than upload and download latency, the satellite for one needs to be in your line of sight, and also if a storm comes through it won't be possible to connect to the internet since there will be interference.

## Fiber
Fiber provides high speed data communication using visable light as a means to modulate data and provides communication over very large distance (much larger than what using standard copper will provide), but fiber requires more expensive equipment and is also more difficult to repair aswell. Fiber is very widely used in WANs (internet for example) because of the previously mentioned advantages (able to transmit large amounts of data fast and is able to be used over long distances). Fiber uses the SONET (Synchronous Optical Networking) protocal for multiplexing and has appeared more commonly as of recent outside of our homes and buisnesses to help provide internet.

## Cable
Cable is one of the most common copper methods used for internet connectivity, cable uses a cable modem (mentioned previously in a different section) to give your house internet via a coxial cable that supports broadband (transmission of data across multiple different frequencies) to give you high speed internet. The standard used to provide internet over an existing cable infrastructure is called DOCSIS (Data Over Cable Service Interface Specification) which like said is a standard (set of protocols to follow) so we can communicate data at high bandwidths over cable infrastructure. Cable can provide speeds from 50 Mbits/s to 1000+Mbits/s, so cable is able to provide very adequate speeds and is definitely a viable option to bring internet to your home.

## DSL
You can also use your existing telephone infrastructure to get internet access, using the same telephone lines that you use for voice communication for your telephone calls for transmitting data from or to the internet using multiplexing techniques.

## Cellular Networks
Another way to get internet is using cellular networks that are used by phones to get said internet access, cellular networks seperate sections of land into "cells" which then a single atenna is then responsible for receiving and sending data for that cell. Since mostly only mobile phones can connect directly to a cellular network to provide internet access through cellular networks to devices that aren't mobile phones you can use something called tethering which will connect your device to a mobile phone which will act as a router for your device (if multiple devices are connected to the phone it is called a mobile hotspot), the mobile phone will then forward packets to the cellular network for said device and the other way around.

## WISP (Wireless Internet Service Provider)
WISP is terrestrial internet access but instead of giving you internet access via a wire going to your home it is provided completely wirelessly. Its convenient for rural or remote locations where it is difficult to get a wire installed connected to your house to give you internet access, so all you have to do for WISP is setup an attena for your house to emit and receive radio waves to connect to the internet. The network you connect to using WISP can be something like a meshed 802.11 network, or using 5G cellular towers for example. WISP can provide speeds up to ~10 to 1000 Mbits/s.

# 2.7.2 Network Types

## LAN (Local Area Network)
A network which has it's device geographically close to eachother (refer to previous section talking about it)

## WAN (Wide Area Network)
A network which geographically is spread over a wide range, an example of a WAN would be the internet, WANs generally connect LANs across long distances and tend to have much longer latencies since you are communicating over longer distances.

## PAN (Personal Area Network)
A PAN is your own private network used for the communication of devices very close to you, if you use bluetooth, infrared electromagnetic radiation, or NFC for communication you are using a PAN. PAN is used in example for vehicles so you can control audio output in your vehicle using your phone.

## MAN (Metropolitan Area Network)
A MAN is a network usually spanning a city for example, it is bigger than a LAN and PAN (obviously), but smaller than a WAN and is usually government owned.

## SAN (Storage Area Network)
A SAN is a repository of storage devices used for storage and provides high speed connectivity for efficient reading and writing of data. To devices accessing the SAN it just looks like a regular local storage device aswell which makes reading and writing easy.

## WLAN (Wireless Local Area Network)
A WLAN as in the name is just a wireless LAN that connects the device wireless using 802.11 technology.

# 2.8 Network Tools

## Cable Crimping
Cable crimping is a part of the process to add a connector to an end of a cable so it can actually be used, an example of this would be crimping ethernet cables (Cat5 or Cat6) and adding a RJ45 connector to the end of said ethernet cable. Cable crimping specifically is the part where you make sure each of the copper wires inside a ethernet cable are attached and touching the copper inside of the RJ45 connector.

## Wifi Analyzer
Wifi Analyzers are used to analyze the strength of wifi signals at a specific information, you can use one to view each individual channel of a wifi connection, the signal strength of each channel, possible interference that is occuring, and more. You can also get device information of what device is using what frequencies aswell so you can determine what devices are causing you interference.

## Tone Generator
Tone generators are used to find where a specific cable is connected to, this is done by one end of a toner will send a signal down through the cable, the other end of the toner can then be put against the wire to try and detect said signal sent, if it is detected the toner will beep, else it won't.

## Punch Down Tool
A Punch Down Tool will punch down a wire down to a punch down block

## Cable Tester
A cable tester is used as the name suggests to test a cable to see if it actually is working properly, it is useful after cable crimping for example to see if each of the copper wires is actually touching the copper in a RJ45 connector for example. You plug one end of the cable into the cable tester and the other into the other part of the cable tester and it will do a test to see if it works.

## Loopback Plug
A loopback plug is a tool used for diagnosis and specifically to test the physical ports on a connector, using the RJ45 connector as an example again the loopback plug would test each of the ports on the connector RJ45 (the copper) and test to see if the RJ45 connector actually is working.

## Tap and Port Mirrors
This is used to copy network traffic's packets on a capture device without intercepting the actual flow of network traffic, one method is using physical taps which will disconnect the link itself and be in the middle of the link and capture traffic. Another method is a port mirror which you plug into a switch, you would then configure the switch to take all packets arriving on one interface and copy them into another (the one the port mirror is connected to).

(This final section is very unfleshed and i don't really understand the topics and devices completely since im not an electrical engineer, would be nice to do some more research into how these actually work and if im not cheap buy some of these :))

