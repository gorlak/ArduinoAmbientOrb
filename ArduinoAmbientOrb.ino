void setup()
{
  // initialize serial:
  Serial1.begin(19200);
}

void loop()
{
  delay(5000);
  Serial1.println("~A  ");
  delay(5000);
  Serial1.println("~A 8");   
}