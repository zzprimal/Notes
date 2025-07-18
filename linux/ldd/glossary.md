# Glossary

## Chapter 1

### Device

A device can be defined as a tool or something designed to perform a task, devices can be split into 2 groups, physical devices and virtual devices

### Virtual Device (Needs Updating)

A virtual device is a piece of software that performs a task, something like /dev/null and /dev/random are examples of this where one performs the task of acting like a shredder and the other performs the task of giving you random bytes of data respectively.

### Physical Device

A physical device is any piece of hardware (anything that you can physically touch) that is part of or can be connected to a computer that performs a task, things like your gpu, mice, keyboards, usbs, soundcards, and many more. A mice is responsible for performing the task of moving your cursor on screen, a gpu is responsible for performing massive parallel computations, usb is responsible for carrying data, etc.

### Driver

A driver implements the functionality of a device and allows the device to be communicated with by implemeting the system calls (or just the api) required for the device to be interfaced with and communicated with. The goal of a driver should be to implement only the mechanism to get the device working and while the higher level abstractions for the code should be implementing the policy for what should be done with the mechanism that is given to it by the driver.

### Device File

A device file is an interface used for processes to be able to interface with the driver for that corresponding device file and allows an interface for the process to communicate with the virtual or physical device the driver is responsible for. A device file can be of 2 types, a logical device file and a physical device file, and they can also be part of another 2 types either a character device file or a block device file.

### Logical Device File

A logical device file is a device file which isn't associated with a particular device but is just an interface to access system resources to do a specific task, something like /dev/random is an example which uses system resources to implement a device file which gives you a stream of random bytes.

### Physical Device File

A physical device file is a device file which is associated to a particular device, an example would be something like /dev/sda which is a device file that represents your hard drive and allows you to interface with the drivers responsible for your hard drive and so your hard drive.

### Character Device File

A character device file is a type of device file that can just be thought of as a never ending stream of bytes, an example of a device file of this kind would be /dev/random or /dev/zero which gives a never ending stream of random bytes and null bytes respectively.

### Block Device File

A block device file is a device file that can be thought of as just a block of data, an example of a device file of this kind would be /dev/sda since a hard drive obviously has to have a limited amount of space.

## Chapter 2

## Chapter 3

## Device Numbers (Major and Minor)

Device numbers are numbers that uniquely identifies devices (atleast character and block devices seperately, ao a character and block device can have same device number) that are currently on your system and they are made up of 2 parts, the major and the minor number, the major number specifies what driver is responsible for controlling the device, while the minor number is just a number used by the driver specified by the major number to differentiate between the devices said driver manages. The major and minor numbers are combined to create what we call a device number and the 2 values of said major and minor are just put in the most significant and least significant part of a 32 bit integer respectively where the major part gets 12 bits and the minor part gets 20 bits which creates the device number (or atleast this is how it was done in the past)

## File Operations (Structure)

File operations implements the system calls that are used to interface with a device where a struct called file_operations which contains a bunch of function pointers is filed with each field representing a system call to like mentioned before to interface with the device which said drivers need to implement. Some of the system calls are things like read, write, llseek, poll, ioctl, and more, with a null value being specified for a function pointer means just resorting to the default behaviour for that system call

## File (Structure)

File structure is a structure that is used to represent an open instance of a file/device (a file descripter) and is created every time a file/device is opened for the first time and only one instance of this structure is created when the first open of this file/device happens and is destroyed when all open instances of the corresponding file/structure are closed. This structure contains information related to the opening of the file like the mode the file was opened with (read or write), the current reading/writing position of the file, a file operations structure which contains the system calls to perform operations on the file, and also a field just for storing any random data the developer finds necessary and useful, and much more.

## Inode (Structure)

Inode structure is a structure that represents a file/device and unlike the file structure does not respresent an open instance and just the file/device in general. Some fields are ones that tell you the device number of the device (obsolete for files), and also a field that points to the cdev struct for the device if that device is a character device (obsolete for other types of files/devices). These are the only fields that are talked about and the only ones of relevance for writing drivers. 

## Preemption

A kernel is said to be preemptive if a thread that is currently executing in kernel space can be forced to give up the cpu by the scheduler to another thread to do a different task