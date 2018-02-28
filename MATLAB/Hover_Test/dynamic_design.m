

syms x y z vx vy vz phi theta psi w s Rx(s) Ry(s) Rz(s) f T ux uy rn rx ry rr m Ixx Iyy Izz

I=diag([Ixx Iyy Izz]);
m=1;
g=9.81;


Rx(s)=[1 0 0; 0 cos(s) -sin(s); 0 sin(s) cos(s)];
Ry(s)=[cos(s) 0 sin(s); 0 1 0; 0 -sin(s) cos(s)];
Rz(s)=[cos(s) -sin(s) 0; sin(s) cos(s) 0; 0 0 1];

RIB=Rx(phi)*Ry(theta)*Rz(psi);
RBN=Rx(ux)*Ry(uy);

f=RIB*RBN*[0; 0; T];
frcs=[rx; ry; 0];

dv=1/m*(RIB*f+frcs)-[0 0 g];
dphi=(w(1)*cos(psi)-w(2)*sin(psi))/cos(theta);
dtheta=w(1)*sin(psi)+w(2)*cos(psi);
dpsi=(-w(1)*cos(psi)+w(2)*sin(psi))*cos(theta)+w(3);

dw=I\(cross(-w,I*w)+RIB*(cross(rn,f)+cross(rr,frcs)));

