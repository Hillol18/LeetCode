#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define input ({lli a;scanf("%lld",&a);a;})
int  s[27];
int sub[24];
lli dp[24][24];
lli x,y;

int length;
lli f(int pos ,int nth,int choto,bool zero,int  nmbr)
{

    //cout<<pos<<" "<<"  "<<nth<<"  "<<choto<<" "<<zero<<"  "<<nmbr<<endl;
      lli ans=0;
       int low=0;
       int high=9;
if(!choto&&!zero&&dp[pos][nth]!=-1)
    return dp[pos][nth];

      if(pos==0)
           {
             //  cout<<"    "<<nmbr<<endl;
               return 1;
           }
       if(choto==1)
       {
           high=s[pos];

          // cout<<s[pos]<<endl;
        //   cout<<high<<endl;
       }
       for(int i=low ;i<=high;i++)
       {

                if(zero)
                {
                  //  cout<<" dd"<<endl;
                     if(i==0)
                     {
                             ans+= f(pos-1,nth-1,choto&&i==high,zero&&i==0,nmbr*10+i);
                     }
                     else
                     {
                            sub[pos]=i;
                            ans+= f(pos-1,nth,choto&&i==high,zero&&i==0,nmbr*10+i);
                     }
                }
                else
                {
                    int mid =(nth+1)/2;
                    if(nth%2==0)
                    {
                         if(pos>mid)
                         {
                             sub[pos]=i;
                             ans+=f(pos-1,nth,choto&&i==high,zero&&i==0,nmbr*10+i);
                         }
                         else
                         {
                             if(sub[nth-pos+1]==i)
                                ans+=f(pos-1,nth,choto&&i==high,zero&&i==0,nmbr*10+i);
                         }
                    }
                    else
                    {
                        if(pos==mid)
                        {
                            ans+=f(pos-1,nth,choto&&i==high,zero&&i==0,nmbr*10+i);
                        }
                        else if(pos>mid)
                        {
                            sub[pos]=i;
                            ans+=f(pos-1,nth,choto&&i==high,zero&&i==0,nmbr*10+i);
                        }
                        else
                        {
                            if(sub[nth-pos+1]==i)
                                ans+=f(pos-1,nth,choto&&i==high,zero&&i==0,nmbr*10+i);
                        }
                    }
                }

       }
       if(!zero&&!choto)
         dp[pos][nth]=ans;
    return ans;
}

int main()
{
lli test;
test=input;
int kase=0;
while(test--)
   {

     x=input;
     y=input;
     if(y<x)
        swap(x,y);
     //sprintf(s,"%lld",x);
    length=0;
x--;
     while(x!=0)
     {
        s[++length] =x%10;
        //if(length==1)
       //     s[length]-=1;
        x/=10;
     }
  //   cout<<s<<endl;
       //length=strlen(s);
       //s+='0';
       memset(dp,-1,sizeof(dp));
       x=f(length,length,1,1,0);
       length=0;
     while(y!=0)
     {
        s[++length] =y%10;
        y/=10;
     }

  //  cout<<x<<endl;
   //  sprintf(s,"%lld",y-1);
  //   cout<<s<<endl;
       //length=strlen(s);

      memset(dp,-1,sizeof(dp));
       y=f(length,length,1,1,0);
      // cout<<y<<endl;
    printf("Case %d: %lld\n",++kase,y-x);
      // cout<<y-x<<endl;
   }
}
