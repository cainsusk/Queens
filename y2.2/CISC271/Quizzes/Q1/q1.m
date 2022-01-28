A = load("20cjbs.txt");

k = 3;
I = eye(4);

disp("the results are:")
C = A + k*I

e_A = eig(A)
e_C = eig(C)

