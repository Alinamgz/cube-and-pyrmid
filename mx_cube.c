void mx_printchar(char c);

static void edge_lines(int lvl, int diagonal, int horizontal, int max_h) {
    if (lvl == 1 || lvl == diagonal + 2 || lvl == max_h) {
        if (lvl == 1) {
            for (int col = 0; col < diagonal + 1; col++) 
                mx_printchar(' ');
        }
        for (int col = 0; col <= horizontal + 1; col++) {
            if (col == 0 || col == horizontal + 1)
                mx_printchar('+');
            else
                mx_printchar('-');
        }
        if (lvl == diagonal + 2) {
            for (int col = 0; col < lvl - 2; col++) 
                mx_printchar(' ');
            mx_printchar('|');
        }
    }
}

static void top_panel(int lvl, int diagonal, int horizontal) {
    if (lvl > 1 && lvl <= diagonal + 1) {
        for (int col = 0; col < diagonal - lvl + 2; col++) 
            mx_printchar(' ');
        mx_printchar('/');
        for (int col = 0; col < horizontal; col++) 
            mx_printchar(' ');
        mx_printchar('/');
        for (int col = 0; col < lvl - 2; col++)
            mx_printchar(' ');
        mx_printchar('|');
    }
}

static void front_block(int lvl, int diagonal, int horizontal, int max_h) {
    if (lvl > diagonal + 2 && lvl < max_h - diagonal - 1) {
        for (int col = 0; col <= horizontal + diagonal + 2; col++) {
            if (col == 0 || col == horizontal + 1 ||
                col == horizontal + diagonal + 2)
                mx_printchar('|');
            else
                mx_printchar(' ');
        }
    }
}

static void front_corner(int lvl, int diagonal, int horizontal, int max_h) {
    if (lvl > max_h - diagonal - 2 && lvl < max_h) {
        for (int col = 0; col <= horizontal + 1; col++) {
            if (col == 0 || col == horizontal + 1)
                mx_printchar('|');
            else
                mx_printchar(' ');
        }
        for (int col = 0; col < max_h - lvl - 1; col++) 
            mx_printchar(' ');
        if (lvl == max_h - diagonal - 1)
            mx_printchar('+');
        else
            mx_printchar('/');
    }
}

void mx_cube(int n) {
    int horizontal = n * 2;
    int diagonal = n / 2;
    int max_h = n + diagonal + 3;

    if (n <= 1) 
        return;
        
    for (int lvl = 1; lvl <= max_h; lvl++) {
        edge_lines(lvl, diagonal, horizontal, max_h);
        top_panel(lvl, diagonal, horizontal);
        front_block(lvl, diagonal, horizontal, max_h);
        front_corner(lvl, diagonal, horizontal, max_h);
        mx_printchar('\n');
    }
}
