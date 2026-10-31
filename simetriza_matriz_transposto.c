void simetrizar_matriz_transposto(int ordem, int mat[ordem][ordem])
{
    for(int i=0;i<ordem;i++)
    {
        for(int j=0;j<ordem;j++)
        {
            if(j>i)
            {
                if(mat[j][i]!=mat[i][j])
                {
                    mat[i][j]=((mat[i][j]+3)%2);
                }
            }
        }
    }
}