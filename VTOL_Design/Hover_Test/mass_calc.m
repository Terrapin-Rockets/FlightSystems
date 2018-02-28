clear all; close all; clc;
lbs2kg = 0.453592;
kg2lbs = lbs2kg^-1;
m2in = 39.3701;
in2m = m2in^-1;

pmin = 28; pmax = 45; % Density range of styrofoam in kg/m^3
Pmin = pmin*kg2lbs/(m2in^3); % Min density of styrofoam in lbs/in^3
Pmax = pmax*kg2lbs/(m2in^3); % Max density of styrofoam in lbs/in^3
T = 0.5; % Nominal body tube thickness in inches
Rm = 3.25; % Nominal body tube midpoint radius
Vbody = 2*pi*Rm*T*70; % Nominal body tube volume
Mbody_min = Vbody*Pmin; % Minimum body tube weight in inches for nominal volume
Mbody_max = Vbody*Pmax; % Max body tube weight in inches for nominal volume

m_elec = 40/1000; % Guessed electronics mass
m_motor = 29/1000; % Mass of Lumenier RX2206-13 2000Kv Motor in kg
m_motor_micro = 7/1000; % Mass of EMAX RS1106 7500Kv Motor in kg
m_esc = 32/1000; % Mass of Lumenier 30 amp ESC in kg
m_esc_small = 10/1000; % Mass of small esc in kg
m_batt = 0.0226796185; % Mass of 3.7V 700mAh lipo in kg
m_prop = 7/1000; % Mass of 6" Lumenier 6x5x3 prop in kg
m_prop_micro = 1.3/1000; % Mass of 2.5" HQProp 2.5x3.4x3 in kg
m_struct = 50/1000; % Anticipated additional structural mass for prop mounting in kg
m_hardware_tot = 2*(m_motor+m_esc+m_prop) + m_batt ...
    + 4*(m_motor_micro+m_esc_small+m_prop_micro) + m_struct + m_elec;
M_hardware_tot = kg2lbs*m_hardware_tot;

Mtot_min = Mbody_min + M_hardware_tot;
Mtot_max = Mbody_max + M_hardware_tot;
mtot_min = Mtot_min*lbs2kg;
mtot_max = Mtot_max*lbs2kg;
req_thrust_per_prop_min = mtot_min*9.81/2 % in N
req_thrust_per_prop_max = mtot_max*9.81/2 % in N