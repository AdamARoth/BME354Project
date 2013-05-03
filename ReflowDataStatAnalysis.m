%% Stat Analysis of Arudino Oven Temperature Code
% Tyler Hobbs, Adam Roth, Alexa Choy, Kavitha Prasanna
% May 1, 2013

figure(1);

A=[ % INSERT DATA HERE (3 COLUMNS)
    ];


%% Calculate the R squared
SSresid = sum((A(1:662,3) - A(1:662,2)).^2);
SStotal = sum((A(1:662,3) - mean(A(1:662,3))).^2);
r_2 = 1 - SSresid./SStotal

text(105,230,['R^2 = ',num2str(r_2)],'FontSize',16)
title('Temperature (C) vs. Time (s) for Reflow Run 5')
xlabel('Time (seconds)');
        ylabel('Oven Temperature (Celsius)')
