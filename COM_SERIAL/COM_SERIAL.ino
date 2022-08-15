/*
 * HDT #7: LabView, Interfaz de 4 Sensores.
 * Estudiante: Alba María Rodas Velásquez.
 * Curso: Fabricación y Simulación de PCB.
 * Catedrático: Pablo Mazariegos.
 * Universidad Del Valle de Guatemala.
 * Ejemplo tomado: "Analog input, analog output, serial output"
*/
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// INICIALIZACIÓN DE PINES DE ESP32:
const int analogInPin01 = 34;  // Analog input pin that the potentiometer is attached to
const int analogInPin02 = 39;  // Analog input pin that the potentiometer is attached to
const int analogInPin03 = 35;  // Analog input pin that the potentiometer is attached to
const int analogInPin04 = 36;  // Analog input pin that the potentiometer is attached to
//-------------------------------------------------------------------------------
// INICIALIZACIÓN DE "SENSORES" --> POTENCIOMETROS:
int sensorValue01 = 0;        // value read from the pot
int sensorValue02 = 0;        // value read from the pot
int sensorValue03 = 0;        // value read from the pot
int sensorValue04 = 0;        // value read from the pot
//-------------------------------------------------------------------------------
void setup() 
{
  // INICIALIZACIÓN DE COMUNICACIÓN SERIAL A 115200 BAUDIOS:
  Serial.begin(115200);
  delay(1000);
}

void loop() {

// LECTURA DE VALORES ANALOGICOS:
  sensorValue01 = analogRead(analogInPin01);
  // read the analog in value:
  sensorValue02 = analogRead(analogInPin02);
  // read the analog in value:
  sensorValue03 = analogRead(analogInPin03);
  // read the analog in value:
  sensorValue04 = analogRead(analogInPin04);
  
// MAPEO DE VALORES ADC PARA EL ESP32
  sensorValue01 = map(sensorValue01, 0, 4095, 0, 255);
  // map it to the range of the analog out:
  sensorValue02 = map(sensorValue02, 0, 4095, 0, 255);
  // map it to the range of the analog out:
  sensorValue03 = map(sensorValue03, 0, 4095, 0, 255);
  // map it to the range of the analog out:
  sensorValue04 = map(sensorValue04, 0, 4095, 0, 255);

// PARA COMPROBACIÓN DE FUNCIONAMIENTO:
  // PRINT RESULTADOS EN EL SERIAL COM, SEPARADOS POR COMAS:
  // POTENCIOMETRO #1:
  Serial.print(sensorValue01);
  Serial.print(",");
  
  // POTENCIOMETRO #2:
  Serial.print(sensorValue02);
  Serial.print(",");
  
  // POTENCIOMETRO #3:
  Serial.print(sensorValue03);
  Serial.print(",");
  
  // POTENCIOMETRO #4:
  Serial.println(sensorValue04);
  delay(200);
}
