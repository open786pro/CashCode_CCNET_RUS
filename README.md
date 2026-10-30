# CashCode SM 2073 (RUS) Library
Library for Arduino and CashCode Bill Validator for Russian banknotes

# Available commands
 *  void update(); -- put this in looped cycle. It updates your bill validator status
 *  int getBanknote(); -- returns accepted bill value. Available banknotes: 10 RUB, 50 RUB, 100 RUB (old), 200 RUB, 500 RUB, 1000 RUB, 2000 RUB, 5000 RUB (old)
 *  void disable(); -- disable bill validator (switch it's status to unavailable).
 *  void enable(); -- enable bill validator and start accepting banknotes (use reset before it).
 *  void reset(); -- reset bill validator (also helps if banknote got stuck).

# Pinout
![Power](extras/Power.JPG)
1 PIN - +12V; 2 PIN - GND
![Data](extras/Data.JPG)
11 PIN - RX0 (Arduino); 16 PIN - TX1 (Arduino)

