void mx_printchar(char c);

void mx_pyramid(int n) {
    int frontdiagonal = n - 1;
    //int verticaldiagonal = n / 2;
    int horizontal = 2 * n - 3;
    int max_w = 2 * n;
    
    
    if (n <= 1 || n % 2 == 1)
        return;
    for (int lvl = 1; lvl <= n; lvl++) {
        if (lvl <= n / 2) {
            for(int col = 0; col <= lvl + n + 2; col++) {
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
        //vertical block
        if (lvl > n / 2 && lvl <= n - 1) {
            for (int col = 0; col <= horizontal; col++) {
                if (col == max_w - lvl - frontdiagonal - 1)
                    mx_printchar('/');
                if (col == horizontal + lvl - frontdiagonal - 1)
                    mx_printchar('\\');
                if (col == horizontal)
                    mx_printchar('|');
                else
                    mx_printchar(' ');
            }
        }
        // last line
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
    mx_printchar('\n');
    }
}
