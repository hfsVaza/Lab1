void setup() {
  Serial.begin(9600);
  while (!Serial) { }
  Serial.print("> ");
}

void loop() {
  if (!Serial.available()) return;

  String s = Serial.readStringUntil('\n');
  s.replace(',', '.');     
  s.trim();

  int idx = s.indexOf('+'); char op = '+';
  if (idx < 0) { idx = s.indexOf('-'); op = '-'; }
  if (idx < 0) { idx = s.indexOf('*'); op = '*'; }
  if (idx < 0) { idx = s.indexOf('/'); op = '/'; }

  if (idx <= 0 || idx >= (int)s.length() - 1) {
    Serial.println("Format: 8*5");
    Serial.print("> ");
    return;
  }

  float a = s.substring(0, idx).toFloat();
  float b = s.substring(idx + 1).toFloat();

  if (op == '/' && b == 0) {
    Serial.println("Error: /0");
    Serial.print("> ");
    return;
  }

  float r = 0;
  if      (op == '+') r = a + b;
  else if (op == '-') r = a - b;
  else if (op == '*') r = a * b;
  else                r = a / b;

  Serial.print("= ");
  Serial.println(r, 6);   
  Serial.print("> ");
}
