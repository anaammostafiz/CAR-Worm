function [L] = plottail(x,y,r,a,b,E_angle,t_angle,E_steps)
narginchk(7, 8);
if nargin<8, E_steps = 36; end
p = Ellipse(x,y,a,b,E_angle,E_steps);
figure
plot(p(:,1),p(:,2),'-'), axis equal
hold on
plot(x,y,'.','MarkerEdgeColor','#0072BD','MarkerSize',10);
hold on

y1 = r/cosd(t_angle);
y2 = y+y1;
q = tail(y2,a,t_angle);
[C1,C2] = tailEllipse(a,b,[x,y],[q(1,1),q(1,2)],[q(2,1),q(2,2)]);
m = tand(t_angle);
B = y2;
X = [C1(1);C2(1)];
Y = [C1(2);C2(2)];
plot(X,Y,'.-','Color','red','MarkerSize',10)
hold on
L = sqrt((X(2)-X(1))^2+(Y(2)-Y(1))^2);
X_out = [-B/m;X(2)];
Y_out = [0;Y(2)];
plot(X_out,Y_out,'--','Color','green')
L_out = sqrt((X_out(2)-X_out(1))^2+(Y_out(2)-Y_out(1))^2);
if L_out < L/2
    h = "true";
else
    h = "false";
end
L = round(L);
x_mid = (X(1)+X(2))/2;
y_mid = (Y(1)+Y(2))/2;
plot(x_mid,y_mid,'.','MarkerEdgeColor','red','MarkerSize',10);
L_active = round(sqrt((X_out(1)-x_mid)^2+(Y_out(1)-y_mid)^2));
title(sprintf('Tail Angle = %d deg, Max L = %d mm, Active L = %d mm, Possible = ' + h,t_angle,L,L_active),'FontSize',9.5);
xmin = min([x-a,X_out(1)]);
xlim([xmin,x+a])
ylim([0,y+b])
xlabel('x (mm)')
ylabel('y (mm)')