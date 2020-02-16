#include <bits/stdc++.h>
using namespace std;
bool inrow(int a[9][9],int row,int n)
{
    for(int i=0;i<9;i++)
    {
        if(a[row][i]==n)
        return false;
    }
    return true;
}
bool incol(int a[9][9],int col,int n)
{
    for(int i=0;i<9;i++)
    {
        if(a[i][col]==n)
        return false;
    }
    return true;
}
bool inbox(int a[9][9],int boxstart,int colstart,int n)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(a[boxstart+row][colstart+col]==n)
            return false;
        }
    }
    return true;
}
bool noissue(int a[9][9],int r,int c,int n)
{
    return inrow(a,r,n)&&
    incol(a,c,n)&&
    inbox(a,r-r%3,c-c%3,n)&&
    a[r][c]==0;

}
void print(int a[9][9])
{
    for(int i=0;i<9;i++)
        {
        for(int j=0;j<9;j++)
        {cout<<a[i][j]<<" ";
        }
        cout<<endl;
        }
}
bool solved(int a[9][9],int &r,int &c)
{
    for(r=0;r<9;r++)
    {
        for(c=0;c<9;c++)
        {
            if(a[r][c]==0)
            {return false;
            }
        }
    }
    return true;
}
bool solve(int a[9][9])
{ int r,c;
    if(solved(a,r,c))
    {
        return true;
    }
    for(int n=1;n<=9;n++)
    {
        
        if(noissue(a,r,c,n))
        {
        a[r][c]=n;    

        
        if(solve(a))
            {return true;
            }
        a[r][c]=0;
        }
    }
    return false;
    
}


int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int a[9][9];
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    if(solve(a))
	    {
	    	cout<<endl;
	        print(a);
	        cout<<endl;
	    }
	    else
	    cout<<"Not exists"<<endl;
	    
	}
	return 0;
}
