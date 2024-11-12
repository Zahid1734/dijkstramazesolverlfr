#include <EEPROM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ArduinoSTL.h>
#include <set>
#include <string>

using namespace std;
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
#define OLED_RESET  -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int sensorcnt = 6;
int lbase = 20; // 20
int rbase = 20; // 20
int speedl = 10;
int speedr = 9;
int led = 11;
int stby = 3;
int button = 4;
int mx[6], mn[6], mid[6];
int pos, tot;
char flag = 's';
float nodespeed = 5;
int nodedelay = 80;
uint32_t m;
int stoptime = 60;
int braketime = 20;
int balancetime = 20;
float balancespeed = 6;

int motor[] = {8, 7, 5, 6};
int sensor[] = {A5, A4, A3, A2, A1, A0};
int base[] = {1, 2, 4, 8, 16, 32}; 
int obstacles = 4;
int data[sensorcnt];
int x = 0;
char matrix[4][4] = 
{
  {'.', '.', '.', '.'} ,
  {'.', '.', '.', '.'} ,
  {'.', '.', '.', '.'} ,
  {'.', '.', '.', '.'} 
} ;

int mask[4][4] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}
};

int edge[20][20];

int dist[4][4]; 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
set<pair<int, pair<int, int>>> st;
pair<int, int> par[4][4];
string s, f = "FRLLRFRFFL";

void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Could not initiate display!"));
    for(;;); 
  }
  for (int i = 0; i < sensorcnt; i++) pinMode(sensor[i], INPUT);
  for (int i = 0; i < 4; i++) pinMode(motor[i], OUTPUT);
  pinMode(speedl, OUTPUT);
  pinMode(speedr, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(stby, HIGH);
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    mid[i] = EEPROM.read(i) * 4;
    mx[i] = EEPROM.read(i + 6) * 4;
    mn[i] = EEPROM.read(i + 12) * 4;
  }
  m = millis();
  display.display();
  while(millis() - m < 500);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  //resetMap();
}

void loop() {
  display.clearDisplay();
  showMenu();
}
