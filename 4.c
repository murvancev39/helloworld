else if (abs(b) < eps)
    {
        if (abs(c) < eps)
        {
            printf("x1 = x2 = 0");
        }
        else if (c / a < 0) // FIXME
        {
            x1 = c / a;
            x2 = -c / a;
            printf("x1 = %lf , x2 = %lf", x1, x2);
        }
        else
        {
            printf("no solution");
        }
    }