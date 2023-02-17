**Kernel Modules**

A kernel module (or loadable kernel mode) is an object file that contains code that can extend the kernel functionality at runtime (it is loaded as needed); When a kernel module is no longer needed, it can be unloaded. Most of the device drivers are used in the form of kernel modules.

**Directory info**

The following directory contains 5 files lkmx.c ( x=1 to 5) each implementing a kernel module functionality and a Makefile to compile the files.

**Steps to compile,load and unload a module**

1. Untar the zipped file 22m2109-cs695-a2.tar.gz and cd to the directory "22m2109-cs695-a2"
2. Run the "make" command [All the modules will be created. Our kernel module is of extension .ko]
Run the "lsmod" command to view the list of modules loaded already
3. To load our custom modules except for the lkm4.ko and lkm5.ko which needs parameters, run the following commnd  sudo insmod <module>.ko e.g. **sudo insmod lkm1.ko**
4. To load lkm4.ko, type **sudo insmod lkm4.ko pid=1 address=0x55f568ff4000** where pid is the process id and adress is a virtual address of the process and for lkm5.ko, **sudo insmod lkm5.ko pid=1**

Now the module is loaded successfully and can be checked using "lsmod" command

5. Type **sudo dmesg -T** to get the kernel related messages from the kernel ring buffer. The last messages will be from the custom modules just loaded.
6. Unload the module using **sudo rmmod <module>** e.g. sudo rmmod lkm1
7. Run **lsmod** to validate whethere the module is unloaded.
8. Output section contains output for each of the lkm modules written.

**Outputs**

Sample of truncated outputs are provided below.

**lkm1.ko message output after loading**

lkm1.c  -  Listing current processes via our module and validated against "ps" which shows the same result

[Tue Jan 24 18:20:52 2023] Hello, Welcome to LKM
[Tue Jan 24 18:20:52 2023] PID: 1 | PROCESS: systemd | STATE: 1
[Tue Jan 24 18:20:52 2023] PID: 3 | PROCESS: rcu_gp | STATE: 1026
[Tue Jan 24 18:20:52 2023] PID: 4 | PROCESS: rcu_par_gp | STATE: 1026
Tue Jan 24 18:20:52 2023] PID: 5 | PROCESS: slub_flushwq | STATE: 1026
[Tue Jan 24 18:20:52 2023] PID: 6 | PROCESS: netns | STATE: 1026
.
.[truncated]
.
[Tue Jan 24 18:20:52 2023] PID: 12883 | PROCESS: kworker/u9:2 | STATE: 1026
[Tue Jan 24 18:20:52 2023] PID: 13363 | PROCESS: kworker/1:0 | STATE: 1026
[Tue Jan 24 18:20:52 2023] PID: 13364 | PROCESS: kworker/0:1 | STATE: 1026
[Tue Jan 24 18:20:52 2023] PID: 13369 | PROCESS: kworker/2:2 | STATE: 1026
[Tue Jan 24 18:20:52 2023] PID: 13381 | PROCESS: sudo | STATE: 1
[Tue Jan 24 18:20:52 2023] PID: 13382 | PROCESS: sudo | STATE: 1
[Tue Jan 24 18:20:52 2023] PID: 13383 | PROCESS: insmod | STATE: 0
[Tue Jan 24 18:20:52 2023] Listing process kernel module loaded

**ps command output**

USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.1 168160 12576 ?        Ss   11:16   0:18 /sbin/init splash
root           2  0.0  0.0      0     0 ?        S    11:16   0:00 [kthreadd]
root           3  0.0  0.0      0     0 ?        I<   11:16   0:00 [rcu_gp]
root           4  0.0  0.0      0     0 ?        I<   11:16   0:00 [rcu_par_gp]
root           5  0.0  0.0      0     0 ?        I<   11:16   0:00 [slub_flushwq]
root           6  0.0  0.0      0     0 ?        I<   11:16   0:00 [netns]
root       12883  0.0  0.0      0     0 ?        I<   18:15   0:00 [kworker/u9:2-rb_allocator]
root       13363  0.0  0.0      0     0 ?        I    18:19   0:00 [kworker/1:0-cgroup_destroy]
root       13364  0.2  0.0      0     0 ?        I    18:19   0:00 [kworker/0:1-events]
root       13369  0.0  0.0      0     0 ?        I    18:20   0:00 [kworker/2:2-events]

**lkm1.ko after unloading**

anubhav@anubhav-Inspiron-5559:~/Desktop/Virtualization/22m2109-cs695-a2$ sudo dmesg -T | tail

[Tue Jan 24 18:29:27 2023] PS module removed,Bye !!

**lkm2.ko message output after loading**

lkm2.c - Prints the pid of the task with the largest in-heap memory. I am printing the heap usage of each task in words using mm_struct data structure and accessing its fields of brk and sbrk and result returns the pid with largest allocated heap. Heap usage calculated: mm->brk - mm->start_brk

Tue Jan 24 18:35:32 2023] Hello, Welcome to LKM
[Tue Jan 24 18:35:32 2023] PID: 1 | PROCESS: systemd | STATE: 1 | HEAP: 2D8000
[Tue Jan 24 18:35:32 2023] PID: 272 | PROCESS: systemd-journal | STATE: 1 | HEAP: CC000
[Tue Jan 24 18:35:32 2023] PID: 320 | PROCESS: systemd-udevd | STATE: 1 | HEAP: 24F000
[Tue Jan 24 18:35:32 2023] PID: 498 | PROCESS: systemd-oomd | STATE: 1 | HEAP: 21000
...
...[truncated]
[Tue Jan 24 18:35:32 2023] PID: 1413 | PROCESS: wireplumber | STATE: 1 | HEAP: 3AC000
[Tue Jan 24 18:35:32 2023] PID: 1414 | PROCESS: pipewire-pulse | STATE: 1 | HEAP: A12000
[Tue Jan 24 18:35:32 2023] PID: 1416 | PROCESS: gnome-keyring-d | STATE: 1 | HEAP: 80000
[Tue Jan 24 18:35:32 2023] PID: 1417 | PROCESS: dbus-daemon | STATE: 1 | HEAP: 1D4000
[Tue Jan 24 18:35:32 2023] PID: 1422 | PROCESS: gvfsd | STATE: 1 | HEAP: 62000
[Tue Jan 24 18:35:32 2023] PID: 1433 | PROCESS: gvfsd-fuse | STATE: 1 | HEAP: 4E000
[Tue Jan 24 18:35:32 2023] PID: 1451 | PROCESS: xdg-document-po | STATE: 1 | HEAP: 43000
[Tue Jan 24 18:35:32 2023] PID: 1454 | PROCESS: xdg-permission- | STATE: 1 | HEAP: 41000
[Tue Jan 24 18:35:32 2023] PID: 1459 | PROCESS: gdm-wayland-ses | STATE: 1 | HEAP: 42000
[Tue Jan 24 18:35:32 2023] PID: 1463 | PROCESS: fusermount3 | STATE: 1 | HEAP: 21000
[Tue Jan 24 18:35:32 2023] PID: 1467 | PROCESS: gnome-session-b | STATE: 1 | HEAP: 64000
[Tue Jan 24 18:35:32 2023] PID: 1505 | PROCESS: tracker-miner-f | STATE: 1 | HEAP: 2B53000
[Tue Jan 24 18:35:32 2023] PID: 1553 | PROCESS: at-spi-bus-laun | STATE: 1 | HEAP: 42000
[Tue Jan 24 18:35:32 2023] PID: 1557 | PROCESS: gnome-shell | STATE: 1 | HEAP: 6614000
[Tue Jan 24 18:35:32 2023] PID: 1563 | PROCESS: dbus-daemon | STATE: 1 | HEAP: 63000
[Tue Jan 24 18:35:32 2023] PID: 13759 | PROCESS: insmod | STATE: 0 | HEAP: 21000
[Tue Jan 24 18:35:32 2023] MAX HEAP USAGE BY PID = 1557 --> AMOUNT USED = 6614000
[Tue Jan 24 18:35:32 2023] List Heap memory-in-use by processes kernel module loaded

**lkm2.ko after unloading**

[Tue Jan 24 18:35:33 2023] List Heap memory-in-use by processes kernel module loaded
[Tue Jan 24 18:44:41 2023] Heap-in-use module removed,Bye !!

**lkm3.ko message output after loading**

lkm3.c - Prints the kernel stack pointer of process with pid 1

[[Mon Jan 30 15:32:32 2023] Hello, Welcome to  LKM
[Mon Jan 30 15:32:32 2023] PID: 1 | PROCESS: systemd | STATE: 1 | STACK TOP FROM TASK->STACK: ffffbb8fc0054000 | CURRENT STACK POINTER THREAD.SP ffffbb8fc0057c80
[Mon Jan 30 15:32:32 2023] SP module loaded

**lkm3.ko after unloading**

[Tue Jan 24 18:53:35 2023] Kernel stack pointer module removed,Bye !!

**lkm4.ko message output after loading**

lkm4.c - Takes process id and a virtual address as an input and gives a physical address for it by traversing the page table directories from mm_struct - pgd, p4d,pud,pmd and pte
 
 
anubhav@anubhav-Inspiron-5559:~/Desktop/Virtualization/22m2109-cs695-a2$ **sudo insmod lkm4.ko pid=1 address=0x7f2878000000**
anubhav@anubhav-Inspiron-5559:~/Desktop/Virtualization/22m2109-cs695-a2$ sudo dmesg -T | tail
[Mon Jan 30 00:03:03 2023] VM START = 7f2886f76000 VM END = 7f2886f78000
[Mon Jan 30 00:03:03 2023] VM START = 7ffdf2e64000 VM END = 7ffdf2e85000
[Mon Jan 30 00:03:03 2023] VM START = 7ffdf2ead000 VM END = 7ffdf2eb1000
[Mon Jan 30 00:03:03 2023] VM START = 7ffdf2eb1000 VM END = 7ffdf2eb3000
[Mon Jan 30 00:03:03 2023] Number of VMAs = 157
[Mon Jan 30 00:03:03 2023] VALID PGD ADDRESS = ffff8fc20667c7f0
[Mon Jan 30 00:03:03 2023] VALID P4D ADDRESS = ffff8fc20667c7f0
[Mon Jan 30 00:03:03 2023] VALID PUD ADDRESS = ffff8fc219e40508
[Mon Jan 30 00:03:03 2023] VALID PMD ADDRESS = ffff8fc204dc1e00
[Mon Jan 30 00:03:03 2023] VALID PTE ADDRESS = ffff8fc204dcb000
[Mon Jan 30 00:03:03 2023] **The virtual address 7f2878000000 maps to physical address 205018000**

[Tue Jan 24 18:55:10 2023] Virtual memory to physical memory info kernel module loaded

**Verification of virtual -> physical mapping using pagemap**

The PFN exactly matches the value returned by the lkm4 module 
./pagemap <pid> <starting VA> <end VA>

sudo ./pagemap 1 0x7f2878000000 0x7f2878021000
**0x7f2878000000  : pfn 205018     soft-dirty 1 file/shared 0 swapped 0 present 1**
0x7f2878001000  : pfn 0  soft-dirty 1 file/shared 0 swapped 0 present 0
0x7f2878002000  : pfn 0  soft-dirty 1 file/shared 0 swapped 0 present 0



**lkm4.ko after unloading**

[Tue Jan 24 18:55:09 2023] Virtual memory to physical memory info kernel module loaded
[Tue Jan 24 18:58:54 2023] Virtual memory module to physical memory info removed,Bye !!

**lkm5.ko message output after loading**

lkm5.c - Given a pid, it calculates the total virtual address space(VSZ) and total physical address space(RSS). Result is validated against the "top" command which comes out to be same

[Tue Jan 24 19:01:14 2023] VM START = 7fb1736d9000 VM END = 7fb1736db000
[Tue Jan 24 19:01:14 2023] VM START = 7fb1736db000 VM END = 7fb1736dd000
[Tue Jan 24 19:01:14 2023] VM START = 7ffc4152f000 VM END = 7ffc41550000
[Tue Jan 24 19:01:14 2023] VM START = 7ffc415f2000 VM END = 7ffc415f6000
[Tue Jan 24 19:01:14 2023] VM START = 7ffc415f6000 VM END = 7ffc415f8000
[Tue Jan 24 19:01:14 2023] PAGE SIZE  IN KB = 4
[Tue Jan 24 19:01:14 2023] Total number of VMAs = 168160
[Tue Jan 24 19:01:14 2023] Total RSS = 12576
[Tue Jan 24 19:01:14 2023] Virtual memory info kernel module loaded

**top command for pid=1**
PID USER  PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
1   root  20   0  168160  12576   8632 S   0.0   0.2   0:18.52 systemd  

**Does Linux implement lazy memory allocation - YES. **

Wrote a sample userspace C program **lazy_allocation.c** in the same directory which will call module load and unload before a malloc and load and unload after accessing it. Whenever we are doing malloc, malloc() will reserve a range of virtual addresses on heap, which is not yet mapped to any physical pages. Physical pages are getting allocated only when that virtual address is accessed. This is what lazy allocation is and is being proved by the following output. First RSS=1592 and then becomes 1636 after accessing the memory location.

[Fri Jan 27 15:25:49 2023] VM START = 7ffe877c2000 VM END = 7ffe877c4000
[Fri Jan 27 15:25:49 2023] PAGE SIZE  IN KB = 4
[Fri Jan 27 15:25:49 2023] Total number of VMAs = 2488
**[Fri Jan 27 15:25:49 2023] Total RSS = 1592**
[Fri Jan 27 15:25:49 2023] Virtual memory info kernel module loaded
[Fri Jan 27 15:25:49 2023] Virtual memory module removed,Bye !!
[Fri Jan 27 15:25:49 2023] Hello, Welcome to LKM
[Fri Jan 27 15:25:49 2023] PID: 3170 | PROCESS: lazy


[Fri Jan 27 15:25:49 2023] VM START = 7ffe8778f000 VM END = 7ffe877b0000
[Fri Jan 27 15:25:49 2023] VM START = 7ffe877be000 VM END = 7ffe877c2000
[Fri Jan 27 15:25:49 2023] VM START = 7ffe877c2000 VM END = 7ffe877c4000
[Fri Jan 27 15:25:49 2023] PAGE SIZE  IN KB = 4
[Fri Jan 27 15:25:49 2023] Total number of VMAs = 2620
**[Fri Jan 27 15:25:49 2023] Total RSS = 1636**
[Fri Jan 27 15:25:49 2023] Virtual memory info kernel module loaded
[Fri Jan 27 15:25:49 2023] Virtual memory module removed,Bye !!


**lkm5.ko after unloading**
[Tue Jan 24 19:10:38 2023] Virtual memory module removed,Bye !

**Additional**

cat /proc/<pid>/maps : to get virtual address intervals for that pid.