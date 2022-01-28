A = load("20cjbs.txt");

[e, v] = eig(A);
v = v*ones(4,1)

for ei = 1:height(v)
    if v(ei) <= 0.001
        v0 = e(:, ei)
    end
end

vclose = v0*2

