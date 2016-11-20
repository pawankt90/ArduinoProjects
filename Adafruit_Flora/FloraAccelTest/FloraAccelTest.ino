#include <NeoPatterns.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

int FloraLEDPin = 6;
uint32_t delayTime = 10;

// Create Accelerometer object with a unique ID
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(54321);

NeoPatterns neoStrip = NeoPatterns(8, FloraLEDPin, NEO_GRB + NEO_KHZ800);

void displaySensorDetails(void)
{
	sensor_t sensor;
	accel.getSensor(&sensor);
	Serial.println("------------------------------------");
	Serial.print("Sensor:       "); Serial.println(sensor.name);
	Serial.print("Driver Ver:   "); Serial.println(sensor.version);
	Serial.print("Unique ID:    "); Serial.println(sensor.sensor_id);
	Serial.print("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
	Serial.print("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
	Serial.print("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");
	Serial.println("------------------------------------");
	Serial.println("");
	delay(500);
}

void setup(void)
{
	neoStrip.begin();
	neoStrip.show();
	Serial.begin(115200);
	Serial.println("Accelerometer Test"); Serial.println("");

	/* Initialise the sensor */
	if (!accel.begin())
	{
		/* There was a problem detecting the ADXL345 ... check your connections */
		Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
		while (1);
	}

	neoStrip.ColorSet(GetKnownColorValue(RED));

	/* Display some basic information on this sensor */
	displaySensorDetails();
	delay(2000);
}

void loop(void)
{
	/* Get a new sensor event */
	sensors_event_t event;
	accel.getEvent(&event);

	/* Display the results (acceleration is measured in m/s^2) */
	//Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
	//Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
	//Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  "); Serial.println("m/s^2 ");

	/* Note: You can also get the raw (non unified values) for */
	/* the last data sample as follows. The .getEvent call populates */
	/* the raw values used below. */
	//Serial.print("X Raw: "); Serial.print(accel.raw.x); Serial.print("  ");
	//Serial.print("Y Raw: "); Serial.print(accel.raw.y); Serial.print("  ");
	//Serial.print("Z Raw: "); Serial.print(accel.raw.z); Serial.println("");

	uint8_t b = map(accel.raw.x, -1050, 1050, 0, 255);
	uint8_t r = map(accel.raw.y, -1050, 1050, 0, 255);
	uint8_t g = map(accel.raw.z, -1050, 1050, 0, 255);

	Serial.print("Red="); Serial.print(r); Serial.print(" "); \
		Serial.print("Green="); Serial.print(g); Serial.print(" "); \
		Serial.print("Blue="); Serial.print(b); Serial.println();

	uint32_t color = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;

	neoStrip.ColorSet(color);

	/* Delay before the next sample */
	delay(500);
}

/*
void setup()
{
	Serial.begin(115200);
	neoStrip.begin();
	neoStrip.show();

	//neoStrip.ConfigureFade(GetKnownColorValue(RED), GetKnownColorValue(BLUE), 20, 100);
}

void loop()
{
	//neoStrip.PerformPattern();

}
*/




