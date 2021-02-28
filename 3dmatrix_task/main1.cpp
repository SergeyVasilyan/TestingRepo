int main()
{
    string myText;
    int M = 5; 
    int count2 = 1;
    int** fltr, ** Img_matrix;
    fltr = new int* [M];
    for (int i = 0;i < M;i++) {
        fltr[i] = new int[M];
    }
    Img_matrix = new int* [M];
    for (int i = 0;i < M;i++) {
        Img_matrix[i] = new int[M]; }
    FILE* in;
    freopen_s(&in, "Filter.txt", "r", stdin);
    FILE* out;
    freopen_s(&out, "F.map.txt", "w", stdout);
    for (int i = 0;i < M;i++) {
        for (int j = 0;j < M;j++) {
            fscanf_s(in, "%d", &fltr[i][j]); }//filtry pahecinq
        int count;
        freopen_s(&in, "Input image.txt", "r", stdin);
        for (int i = 0;i <= 28;i++)
        {
            count = 0; 
            for (int k = i;k < i + 5;k++)
            {
                for (int j = 0;j <= 28;j++)
                    while (count < 5) {
                        
                        fscanf_s(in, "%d", &Img_matrix[k][j]);
                    }
            }
            if (count2 % 28 != 0) {
                int el = mult(Img_matrix, fltr, M, M);
                fprintf(out, "%d", el);
                count2++;
            }
            else {
                fprintf(out, "%s", "\r\n");
                count2++;        } } }
    return 0;
}
    
