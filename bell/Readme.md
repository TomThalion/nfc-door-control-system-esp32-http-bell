# Bell manual
## Setup
First of all you need an esp 32 to run the bell subsystem on it. Moreover it should be an az-delivery-devkit-v4, oterhwise there is no guarantee that the system will run. 
The next step is to install VS code with the plattformio plugin. That is neccessary to upload the program to the microcontroller(mc). After you have installed the plugin, you may have to run some commands on the commandline to initialise platformio or vs code will ask you to do this. Then open PIO Home (house symbol), navigate to "projects" and open the project "bell". After that you have to connect your mc to your pc using the micro usb port of your microcontroller. Now you can upload and build the project, if you have any problems with building or uploading the project to your microcontroller, then look at the internet for solutions, depending on your system you might encounter difficulties. (A good website for a closer look e.g. https://docs.platformio.org/en/latest/platforms/espressif32.html#using-arduino-framework-with-staging-version). After that the programm will run on your microcontroller, if you supply it with electricity by usb.

## Connecting hardware
The acoustic bell is using pin 4. 
The lightsignBell is using pin 2.
Pin 5 is used for a controll LED.

If you want to use any of this, please connect an LED or BELL (which can work with the standart "high" output of an microcontroller pin) to the specified pin and GND (Ground). Leds, however, can only direct the current in one direction.

## Get IP4
The microcontroller prints its ip4 on the serial monitor after connecting to wifi for that reason you have to set your serial monitor to the correct bautrate, in this case it should be 9600.
## Need to know
When ever you modyfie configurations you have to rebuild and reupload the project again. 

You can edit all configutations in the platformio.ini. You will also find there an short documentation of what configuration changes what.

