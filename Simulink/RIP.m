%% - General constants for Rotary Inverted Pendulum ----------------------------------
%
g = 9.81;           % [m/s^2]
L = 0.1254;           % [m]
m = 0.05562;            % [Kg]
r = 0.1095;          % [m]
Jeq = 0.004036;    % [Kg-meter^2]
Beq = 0.0444;        % [Nm/(rad/s)]
n = 0.69;           % hieu suat
Kt = 0.084039;       % [N-m/Amp]
Km = 0.084026;       % [Volt-sec/rad]
Rm = 2.6;
Jm=0.001;
%% ***** constants of the model ----------------------
%
a = Jeq + m*r*r+Jm;
b = m*L*r;
c = (4/3)*m*L*L;
d = m*g*L;
e = Beq + (n*Kt*Km)/Rm;
f = n*Kt/Rm;


%% **** the linearized Rotary Inverted Pendulum system around the straight up position LQR
%
% A = [0,                                         0,                              1,                              0;
%      0,                                         0,                              0,                              1;
%      0,                             b*d/(a*c-b*b),                 -c*e/(a*c-b*b),                              0;
%      0,                             a*d/(a*c-b*b),                 -b*e/(a*c-b*b),                              0]
 
 A=[0,      1,              0,          0;
    a*d/(a*c-b*b), 0,  0,  -b*e/(a*c-b*b);
    0,      0,                  0,       1;
    b*d/(a*c-b*b),      0,   0,  -c*e/(a*c-b*b)]


B = [            0;
    b*f/(a*c-b*b);
                 0;
     c*f/(a*c-b*b)]
 

 
 
% C = [1      0       0       0;
%      0      1       0       0;
%      0      0       1       0;
%      0      0       0       1];
% D = [0;
%      0;
%      0;
%      0];
 
Q = diag ([50 1 80 20]); 
%Q = [5      0       0       0;
%     0      20       0       0;
%     0      0       0       0;
%     0      0       0       0];
R = 1;
%P=dare(A,B,Q,R)
K = lqr(A,B,Q,R)