# nfc-door-controll-system-esp32-Http-bell
## About this project:
This is a c++ program for an esp 32 microcontroler with wifi. It was developt as a part of a "nfc-door-controll-system" but can also be used without the rest of the system (Link to mainsystem: "https://github.com/l-nn-rt/nfc-door-controll-system"). 

## Functionality and how to use: 
The microcontroller will set and reset output pins, when receiving  http posts. A post at  "/subscriber/bell/" triggers a ring. A post at "/subscriber/door/" will stop ringing if it still was ringing  before. For more details lock at the "Entwurf_TECO.pdf" file under "eventsubscribers" and "bell". Any other information you can look up in the Readme file at the "bell" directory. 
