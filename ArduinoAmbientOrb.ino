#ifdef __AVR_ATmega2560__
# define DEVELOPMENT 1
#else
# define DEVELOPMENT 0
#endif

#if DEVELOPMENT
# define ORB_SERIAL Serial1
#else
# define ORB_SERIAL Serial
#endif

void setup()
{
	// initialize serial:
	ORB_SERIAL.begin(19200);

#if DEVELOPMENT
	Serial.begin(9600);
	Serial.println("Starting up...");
#endif

	// disable pager data
	ORB_SERIAL.print("~GT");

	char buf[3] = { '\0' };
	ORB_SERIAL.readBytes( buf, 2 );

#if DEVELOPMENT
	Serial.println( buf );
#endif
}

void setColor( const char* code )
{
	char outgoing[ 5 ];
	snprintf( outgoing, sizeof(outgoing), "~A%s", code );
	ORB_SERIAL.print(outgoing);

#if DEVELOPMENT
	Serial.println( outgoing );
#endif

	char buf[3] = { '\0' };
	ORB_SERIAL.readBytes( buf, 2 );

#if DEVELOPMENT
	Serial.println( buf );
#endif
}

void loop()
{
	delay(5000);
#if DEVELOPMENT
	Serial.println("Setting red...");
#endif
	setColor("  ");

	delay(5000);
#if DEVELOPMENT
	Serial.println("Setting blue...");
#endif
	setColor(" 8");
}