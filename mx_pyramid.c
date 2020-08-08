void mx_printchar(char c);

static void apex(int lvl, int n) {
    if (lvl <= n / 2) {
        for (int col = 0; col <= lvl + n + 2; col++) {
            if (col == n - lvl)
                mx_printchar('/');
            if (col == lvl + n - 3 && lvl > 1)
                mx_printchar('\\');
            if (col == lvl + n + 2) {
                for (int i = 1; i < lvl; i++) 
                    mx_printchar(' ');
                mx_printchar('\\');
            }
            if (col < n - lvl || (col >= n - lvl && col <= lvl + n - 4))
                mx_printchar(' ');
        }
    }
}

static void body(int lvl, int n, int horizontal) {
    if (lvl > n / 2 && lvl <= n - 1) {
        for (int col = 0; col <= horizontal; col++) {
            if (col == n - lvl)
                mx_printchar('/');
            if (col == horizontal - n + lvl)
                mx_printchar('\\');
            if (col == horizontal)
                mx_printchar('|');
            else
                mx_printchar(' ');
        }
    }
}

static void bottom(int lvl, int n, int horizontal) {
    if (lvl == n) {
        for (int col = 0; col <= horizontal; col++) {
            if (col == 0)
                mx_printchar('/');
            if (col == horizontal) {
                mx_printchar('\\');
                mx_printchar('|');
            }
            else 
                mx_printchar('_');
        }
    }
}

void mx_pyramid(int n) {
    int horizontal = 2 * n - 3;

    if (n <= 1 || n % 2 == 1) 
        return;

    for (int lvl = 1; lvl <= n; lvl++) {
        apex(lvl, n);
        body(lvl, n, horizontal);
        bottom(lvl, n, horizontal);
        mx_printchar('\n');
    }
}
