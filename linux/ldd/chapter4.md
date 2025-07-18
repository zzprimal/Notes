- the logs for kernel messages which are written via printk is implemented via a circular buffer called the kernel's ring buffer which is around usually 4MB long

- /dev/kmsg provides an interface for which you can use to read the kernel's ring buffer for printk messages, you can then use a utility like dmesg to read the contents of said ring buffer which uses the virtual device /dev/kmsg

- /proc is a directory that was originally meant to store only currently active processes on the system, but that original purpose has started to become a little blurred as now it is used for other things aswell like

- sysrq key combinations are very cool (: (look at /Documentation/admin-guide/sysrq.rst)