pmin = 28; pmax = 45;
kg2lbs = 2.205;
lbs2kg = 0.453592;
m2in = 39.3701;
in2m = m2in^-1;
m_motor_small = 6*28/1000;
batt = 2*40/1000;
struct = 50/1000;
tinch = 0.5;
rm = 3.25;
Vmin_inch = 2*pi*rm*tinch*70;
pmin_inch = pmin*(kg2lbs/(m2in^3));
mmin_lbs = pmin_inch*Vmin_inch;
mmin_kg = mmin_lbs*lbs2kg+2*m_motor_small+batt+struct