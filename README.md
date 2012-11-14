An Arduino to drive color state on an Ambient Orb (ambientdevices.com).

I am using an Arduino Mega for development (using Serial1) for the orb since the Uno
shares its single Serial interface with the development environment.  The default
compile will use the standard Serial interface.

The main goal is to support the Ethernet shield and advertise a hostname over Bonjour.
Then run a web server and support color state change over a JSON url api.  This will
make it a simple matter to script from any computer on the same LAN.

-gorlak