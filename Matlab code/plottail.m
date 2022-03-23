function [L] = plottail(x,y,a,b,E_angle,t_angle,E_steps)
narginchk(6, 7);
if nargin<7, E_steps = 36; end
p = Ellipse(x,y,a,b,E_angle,E_steps);
figure
plot(p(:,1),p(:,2),'-'), axis equal
hold on
plot(x,y,'.','MarkerEdgeColor','#0072BD','MarkerSize',10);
hold on
q = tail(y,a,t_angle);
C = tailEllipse(a,b,[x,y],[q(1,1),q(1,2)],[q(2,1),q(2,2)]);
m = tand(t_angle);
B = y;
X = [-C(1);C(1)];
Y = [m*X(1)+B; m*X(2)+B];
plot(X,Y,'.-','Color','red','MarkerSize',10)
hold on
L = sqrt((X(2)-X(1))^2+(Y(2)-Y(1))^2);
X_out = [-B/m;X(1)];
Y_out = [0;Y(1)];
plot(X_out,Y_out,'--','Color','green')
L_out = sqrt((X_out(2)-X_out(1))^2+(Y_out(2)-Y_out(1))^2);
if L_out < L/2
    h = "true";
else
    h = "false";
end
L = round(L);
L_active = round(sqrt((x-X_out(1))^2+(y-Y_out(1))^2));
title(sprintf('tail angle = %d deg, Max L = %d mm, Active L = %d mm, possible = %s',t_angle,L,L_active,h),'FontSize',9.5);
xmin = min([x-a,X_out(1)]);
xlim([xmin,x+a])
ylim([0,y+b])
xlabel('x (mm)')
ylabel('y (mm)')