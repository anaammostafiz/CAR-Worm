function [tau_max,theta_max] = pendulum(m,l,alpha)
tau = 0:360;
theta = 0:360;
g = 9.8;
for i = 1:361
    tau(i) = m*l^(2)*alpha + m*g*l*cosd(theta(i));
end
plot(theta,tau);
title('Torque vs. Angle of Rotation');
xlabel('Angle (degrees)');
ylabel('Torque (N-m)');
xlim([0 360])
hold on
theta_mark = 0:8;
tau_mark = 0:8;
for j = 0:8
    theta_mark(j+1) = theta(j*45+1);
    tau_mark(j+1) = tau(j*45+1);
end
plot(theta_mark,tau_mark,'o');
[tau_max,theta_ind] = max(abs(tau));
theta_max = theta_ind-1;

