int *pre_kmp(string pattern)
{
    int size = pattern.length();
    int *pie=new int [size];
    pie[0] = 0;
    int k=0;
    for(int i=1;i<size;i++)
    {
        while(k>0 && pattern[k] != pattern[i] )
        {
            k=pie[k-1];
        }
        if( pattern[k] == pattern[i] )
        {
            k=k+1;
        }
        pie[i]=k;
    }
    
    return pie;
}

int kmp(string text,string pattern)
{
    int* pie=pre_kmp(pattern);
    int matched_pos=0;
    for(int current=0; current< text.length(); current++)
    {
        while (matched_pos > 0 && pattern[matched_pos] != text[current] )
            matched_pos = pie[matched_pos-1];
            
        if(pattern[matched_pos] == text[current])
            matched_pos = matched_pos+1;
            
        if( matched_pos == (pattern.length()) )
        {
            return current - (pattern.length() -1 );
            matched_pos = pie[matched_pos-1];
        }
    }

    return -1;
}

void Solve(){
    string str, pattern;
    cin >> str >> pattern;

    int x = kmp(str, pattern);

    cout << x << lb; 
}
