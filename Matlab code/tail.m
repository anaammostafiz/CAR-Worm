function [Z] = tail(y, a, t_angle)

narginchk(2, 3);
if nargin<3, t_angle=45; end

m = tand(t_angle);
b = y;
X = [-a;a];
Y = [m*X(1)+b; m*X(2)+b];
Z = [X,Y];
end

