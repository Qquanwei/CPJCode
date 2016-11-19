w = 1.1;
t = 0:0.1:4*pi;
A0 = 5;

X = A0 * sin(2 * pi * w * t);
X2 = A0 * (mod(1:length(t),10) > 4); % 产生一个脉冲信号
Y = X + X2;

subplot(4,1,1);
plot(t,X);
subplot(4,1,2);
plot(t,X2);
subplot(4,1,3);
plot(t,Y);
subplot(4,1,4);
fY = fft(Y);
plot(t,abs(fY))
