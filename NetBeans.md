#NetBeans als IDE für C Entwicklung auf dem Raspberry

##Creating A New NetBeans Project
Menu > File > New Project > Select 'C/C++ Application'

Set the projects name and location

Select C or C++ from the drop down 

Leave the default options for 'Build host' and 'Tool collection'.

Click 'Finish'

Select the 'Services' tab in the left window.

Ensure the Raspberry Pi is powered up and connected to the network.

Right click 'C/C++ Build Hosts' > Add New Host

Enter the IP address of the Raspberry Pi

*Press Next*

Jetzt SSH-Schlüssel wählen und den Pfad zur PPK Datei angeben 

*Press next*

NetBeans will attempt to connect

*Press Finish*

Select the 'Projects' tab in the left window.

Right click the projects name > Properties

Build > Build Host > Select the build host name you just created.

Run > Console Type > Standard Output

Apply and Close

If you are using the bcm2835 library for the IO pins etc, ensure you've installed it by following the guide here, add the bcm2835.h file to your project and do this:

Right click the project > Properties > Build > Linker > In the 'Libraries' section press the '…' button > Add Option… > Other Option > Enter: -lbcm2835

Right click the project > Build


##Diverses

###Delete all breakpoints
Menu > Window > Debugging > Breakpoints

Then right-click in the Breakpoints window and select Disable All or  "Delete All".

