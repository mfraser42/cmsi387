CSI-OS
Written by Michael Fraser

Help from Google Search, which led to sites such as stack overflow, super user, and various others.

This folder contains pictures corresponding to the following pieces of information for Windows, Mac, and Linux operating systems:
1) Pre-OS software (firmware, I/O subsystem, boot loader, etc.)

2) Kernel file(s) 

3) Startup scripts and/or configuration files

4) The “first process” 

5) Network settings 

The files beginning with "Linux" correspond to the linux operating system, just as those starting with "Mac" and "Windows" correspond to Mac and Windows operating systems, respectively. 

1. Pre-OS software
    a) Windows: WindowsPreOS.jpg - found by holding F2 when booting a computer with windows. This is the Windows BIOS.
    b) Mac: MacPreOS.jpg - found by holding command + v when booting a computer running Mac OSX. 
    c) Linux: LinuxFirmware.png - found by navigating to the directory /lib/firmware. 

# JD: Linux is the odd one out here: for Windows and Mac, you show the software while it
#     is *running*; on Linux, you show files, but not in action.

2. Kernel File(s)
    a) Windows: WindowsKernel.png - found by searing the System32 subdirectory for the kernel executable.
    b) Mac: MacKernel.png - found by searching the / directory for anything matching the string "kernel." Andrew is an EE friend who had a macbook handy.
    c) Linux: LinuxKernel.png - located in the /boot directory
    
3. Startup scripts and/or configuration files
    a) Windows: WindowsStartupScripts.png - The directory shown is the location of startup scripts for all users, but there is only one file located there.
    b) Mac: MacConfigFiles.png - found by navigating to the Preferences subdirectory,
# JD: Which one?  There is more than one directory named Preferences, and some
#     of them are user-specific, not system- or OS-wide.
    c) Linux: LinuxConfigFiles.png - configuration files are located in the /etc directory, it was piped into grep so only .conf files are shown.
    
4. The "first process"
    a) Windows: WindowsFirstProcess.png - the output displayed occured when the tasklist was searching for the process with an ID of 0.
    b) Mac: MacFirstProcess.png - the -p 1 in the command calls for the process ID of 1 to be displayed.
    c) Linux: LinuxFirstProcess.png - the -p 1 in the command calls for the process ID of 1 to be displayed.
    
5. Network Settings
    a) Windows: WindowsNetwork.png - Found by clicking on Network in the Control Panel. 
    b) Mac: MacNetworkSettings.png - Found by clicking the wifi icon along the toolbar and clicking Network Settings.
    c) Linux: LinuxNetwork.png - Found by clicking the wifi icon along the toolbar and clicking Network Settings.    
