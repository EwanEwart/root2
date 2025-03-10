# Notes

# X server access
# replace [user]
xhost +si:localuser:[user]

# snap access to USB drives / sticks
# enter literal command as seen below
sudo snap connect root-framework:removable-media

# C++ 
c++filt -t mangled_expr

linux settings
- apps ...

-- Root
--- permissions
---- read/write files on removeable storage design

-- JupyRoot
--- permissions
---- read/write files on removeable storage design

-- PyRoot
--- permissions
---- read/write files on removeable storage design

# Access to USB devices
In Ubuntu,
when using Snap applications,
certain permissions
such as accessing USB drives
require explicit user approval.

This is in line with Snap’s security model,
which isolates applications from the system
and limits their access to the hardware
and files unless permissions are granted.

To configure a Snap app's access to a USB drive,
you can follow these steps:

    Connect the USB Drive:
First, make sure your USB drive is connected to the system.

    Open Terminal:
You can open a terminal window using Ctrl + Alt + T
or by searching for "Terminal" in the application menu.

    List the Connected Snaps:
Run the following command
to see the list of installed Snap applications:

snap list

	Grant Access to the USB Drive:
Use the snap connect command
to grant the necessary permission.
The specific interface you will likely need to connect
is removable-media.

Here's how to do it:

sudo snap connect <snap-package-name>:removable-media

Replace <snap-package-name>
with the name of the Snap application
that needs access.
For example, if you are using VLC,
the command would look like this:

	$ sudo snap connect vlc:removable-media

    Test Access:
After granting permissions,
try accessing the USB drive
through the Snap application again
to see if it works.

Using the GUI (if available)

	Some graphical Snap applications
might prompt you to allow access to the USB drive
when you first attempt to access it.
If you see a dialogue box
requesting permissions,
simply follow the on-screen instructions.

Revoke Access
=============
	If you need to revoke access
to the USB drive later,
you can use the following command:

	$ sudo snap disconnect <snap-package-name>:removable-media

Additional Notes
================
    Each Snap app
might have its own specific requirements
for permissions,
so it's good to read the documentation
or check the interface options.
    Make sure that your USB drive
is mounted properly
before attempting to access it
with the Snap application.

By following these steps,
you should be able
to grant or revoke the necessary permissions
for Snap applications
to access your USB drives in Ubuntu.

# shared objects
https://root.cern/manual/root_macros_and_shared_libraries/

root [.].L TF1_01.C+      // build shared library
root [.].L TF1_01.C++    // force rebuild shared library
root [.].L TF1_01_C.so  // load shared library
root [.].x TF1_01()    // call a shared library function
root [.].L TF1_01.C+g // to force compilation with debug symbols,
