function [Rt_req,Rt] = planetary(m,l,alpha,tau_stall,rs,rp)
% m = 0.567 kg
% l = 0.113 m
% alpha = 0.35 rad/s^2
% tau_stall = 0.586 N-m
% rs = (major dia + minor dia)/4 = 0.003625 m originally
% rp = 0.0135 m originally
[tau_max,~] = pendulum(m,l,alpha);
Rt_req = tau_max/tau_stall;
Rt = 2*(rs+rp)/rs;
