class Solution {
public:
int solve(int num){
    if(num<10) return num;
    int sum=0;
    while(num){
        sum=sum+num%10;
        num=num/10;
    }
    
    return solve(sum);
}
    int addDigits(int num) {
        return solve(num);
    }
};