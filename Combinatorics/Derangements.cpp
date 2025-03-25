//Permutation such that no element appears in its original position (p[i] != i).
The formula used in the solution is:
        if (n == 1) return 0;
        if (n == 2) return 1;
        F(n) = (n – 1) * (F(n – 1) + F(n – 2);
