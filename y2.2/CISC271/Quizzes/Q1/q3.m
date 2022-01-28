A = load("20cjbs.txt");

[e, v] = eig(A);
v = v*ones(4,1)
c = 0;

for ei = 1:height(v)
    if v(ei) > c
        c = v(ei)
        V = e(:, ei)
    end
end

