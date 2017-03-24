#include <StandardCplusplus.h>
#include <string>
using namespace std;

#define LED   12
#define DELAY 80

const string MESSAGE = "hello world";

string CODE[26] = {
  ".-",   // a
  "-...", // b
  "-.-.", // c
  "-..",  // d
  ".",    // e
  "..-.", // f
  "--.",  // g
  "....", // h
  "..",   // i
  ".---", // j
  "-.-",  // k
  ".-..", // l
  "--",   // m
  "-.",   // n
  "---",  // o
  ".--.", // p
  "--.-", // q
  ".-.",  // r
  "...",  // s
  "-",    // t
  "..-",  // u
  "...-", // v
  ".--",  // w
  "-..-", // x
  "-.--", // y
  "--.."  // z
};

string morseCodify(string msg) {
  string res;
  const int N = msg.size();
  
  for (int i = 0; i < N; i++)
    if (msg[i] != ' ')
      res += CODE[msg[i]-'a'] + " ";

  return res;
}

void setup() {
  pinMode(LED, OUTPUT);
}

const string MORSE = morseCodify(MESSAGE);
int i = 0;
const int N = MORSE.size();
bool done = false;

void loop() {
    if (!done) {
      if (MORSE[i] == ' ')
        delay(2*DELAY);
      else
        digitalWrite(LED, 1);
      
      if (MORSE[i] == '.')
        delay(DELAY);
      else if (MORSE[i] == '-')
        delay(3*DELAY);
  
      digitalWrite(LED, 0);
      delay(DELAY);
    }
    
    if (++i == N-1)
      done = true;
}

