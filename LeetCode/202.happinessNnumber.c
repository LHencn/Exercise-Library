
bool isHappy(int n) {
     int temp=0;
        while(n!=1)
        {
            while(n>0)
            {
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n=temp;
            temp=0;
            if(n==4) return 0; 
        }
       return 1; 
}
