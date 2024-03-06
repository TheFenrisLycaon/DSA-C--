bool find4Numbers(int A[], int n, int X)
{
    sort(A, A + n);
    
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                int temp = A[i] + A[j] + A[k] + A[l];

                if (temp == X)
                    return true;
                else if (temp > X)
                    l--;
                else
                    k++;
            }
        }
    }
    return false;
}