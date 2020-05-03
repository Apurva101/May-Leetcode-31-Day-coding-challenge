class Solution {
public:
    int numJewelsInStones(string J, string S) {
      int n1=J.length();
        int n2=S.length();
        
        	int freq1[26]={0}, freq2[26]={0}, freq3[26]={0}, freq4[26]={0};
        
       for(int i=0;i<n1;++i)
           if(J[i]>='a' && J[i]<='z')
        	freq1[J[i]-'a']++;
    
    
	for(int j=0;j<n2;++j)
         if(S[j]>='a' && S[j]<='z')
    freq2[S[j]-'a']++;
    
    for(int i=0;i<n1;++i)
         if(J[i]>='A' && J[i]<='Z')
	freq3[J[i]-'A']++;
     
        for(int i=0;i<n2;++i)
             if(S[i]>='A' && S[i]<='Z')
	freq4[S[i]-'A']++;
        
        int count=0;
        
        	for(int i=0;i<26;++i)
            if(freq1[i]!=0)
            {
            count+=freq2[i];
              
        }
   
   for(int i=0; i<26;++i)
   if(freq3[i]!=0)
   count+=freq4[i];
        return count;
    }
        
    };
