
float eeg = 0;
void setup()
{
        // initialize the serial communication:
        Serial.begin(9600);
 
        pinMode(10, INPUT); // Setup for leads off detection LO +
        pinMode(11, INPUT); // Setup for leads off detection LO -
        pinMode(2, OUTPUT);
        pinMode(4, OUTPUT);
        pinMode(7, OUTPUT);
        pinMode(8, OUTPUT);
       
        analogReference(DEFAULT);
}
 
double mean = 0;
double inputs = 0;
double y;
double last50[50];
int i; // contador
 
void loop()
{
        if ((digitalRead(10) == 1) || (digitalRead(11) == 1))
        {
                Serial.println('!');
                digitalWrite(2, LOW);
                digitalWrite(4, LOW);
                digitalWrite(7, LOW);
                digitalWrite(8, LOW);
        }
        else
        {
                inputs++;
 
                mean = (mean * (inputs - 1) + analogRead(A0)) / inputs;
 
                y = abs(analogRead(A0) - mean);
 
                if (inputs - 1 < 50)
                {
                        // Para las 50 primeras entradas
                        last50[int (inputs)-1] = y;
                }
                else
                {
                        // Para el resto de entradas
                        for (i = 0; i < 49; i++)
                        {
                                // Rotamos los 10 elementos del vector, sobreescribiendo encima de last50[0]
                                last50[i] = last50[i+1];
                        }
                        // Y nuestra ultima entrada la guardamos en la ultima posición del vector
                        last50[49] = y;
                }
 
                y = 0;
 
                for (i = 0; i < 50; i++)
                {
                        y += last50[i];
                }
 
                y = y*4/12000;
                eeg = y;
                Serial.println(eeg);
                
       
               
 
           
        }
 
        // Wait for a bit to keep serial data from saturating
        delay(1);
}
 
