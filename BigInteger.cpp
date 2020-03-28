#include<bits/stdc++.h>
#include<string>
using namespace std;
class BigInteger
{
	string number;
	public:
	BigInteger()	//	default constructor: it intializes the BigInteger to 0
	{
		number="0";
	}
	BigInteger(string s)	// parametrized constructor: it intializes the BigInteger with string passed as parameter 
	{
		number=s;
	}
	string getBigInteger() // it returns BigInteger as string
	{
		return number;
	}
	int size()				// returns size of the BigInteger
	{
		return number.size();
	}
	void putBigInteger(string s) // it intializes the BigInteger with string passed as parameter
	{
		number=s;
	}
	void copyBigInteger(BigInteger B) // it copies the BigInteger passed as argument to the BigInteger calling the method
	{
		number=B.number;
	} 
	BigInteger addBigInteger(BigInteger B) // it returns BigInteger which is sum of the BigInteger which calls the addBigInteger() function and the BigInteger which is passed as argument
	{
		string s1=number;
		string s2=B.number;
		int n1=s1.size()-1,n2=s2.size()-1;
		int remainder=0;
		int carry=0,intermediate=0;
		string ans="",intermediateString="";
		while(n1!=-1 && n2!=-1)
		{
			intermediate=s1[n1]-'0'+s2[n2]-'0'+carry;
			remainder=intermediate%10;
			carry=intermediate/10;
			intermediateString=remainder+'0';
			ans=intermediateString+ans;
			n1--;
			n2--;
		}
		while(n1!=-1)
		{
			intermediate=s1[n1]-'0'+carry;
			remainder=intermediate%10;
			carry=intermediate/10;
			intermediateString=remainder+'0';
			ans=intermediateString+ans;
			n1--;
		}
		while(n2!=-1)
		{
			intermediate=s2[n2]-'0'+carry;
			remainder=intermediate%10;
			carry=intermediate/10;
			intermediateString=remainder+'0';
			ans=intermediateString+ans;
			n2--;
		}
		if(carry!=0)
		{
			intermediateString=carry+'0';
			ans=intermediateString+ans;
		}
		BigInteger sum(ans);
		return ans;
	}
	BigInteger subtractBigInteger(BigInteger B) // it subtracts the BigIntergers (this-B)
	{
		BigInteger W(number);
		BigInteger X=W.removeTrailingZeros();
		BigInteger Y=B.removeTrailingZeros();
		
		string s1=X.getBigInteger();
		string s2=Y.getBigInteger();
		int n1=s1.size()-1;
		int n2=s2.size()-1;
		BigInteger ans;
		int f=0,putNegative=0,lm,ln;
		string A="",intermediateString="",intermediate="";
		if(s1.size()<=s2.size())
		{
			if((s1[0]-'0'<s2[0]-'0')||(s1.size()<s2.size()))
			{
				string t=s1;
				s1=s2;
				s2=t;
				int temp=n1;
				n1=n2;
				n2=temp;
				putNegative=1;
			}
		}
		if(n1<=n2)
		{
			int f=0;
			if(n1==n2)
			{
				int i;
				for(i=0;i<n1;i++)
				{
					lm=s1[i]-'0';
					ln=s2[i]-'0';
					if(lm<ln)
					{
						f=1;
						break;
					}
				}	
			}
			if(n1<n2 || f==1)
			{
				string t;
				t=s1;
				s1=s2;
				s2=t;
				int te;
				te=n1;
				n1=n2;
				n2=te;
				putNegative=1;	
			}
		}
		while(n1!=-1 && n2!=-1)
		{
			intermediateString="";
			int x=s1[n1]-'0'-(s2[n2]-'0');
			if(f==1)
			{
				x=x-1;
				f=0;
			}
			if(x<0)
			{
				x=x+10;
				f=1;
			}
			intermediateString=x+'0';
			A=intermediateString+A;
			n1--;
			n2--;
		}
		while(n1!=-1)
		{
			intermediateString="";
			int x=s1[n1]-'0';
			if(f==1)
			{
				x--;
				f=0;
			}
			if(x<0)
			{
				x=x+10;
				f=1;
			}
			intermediateString=x+'0';
			A=intermediateString+A;
			n1--;
		}
		BigInteger TU(A);
		BigInteger DE=TU.removeTrailingZeros();
		A=DE.getBigInteger();
		if(putNegative==1)
			A="-"+A;
		ans.putBigInteger(A);
		return ans;
	}
	BigInteger absolute() // it returns the absolute BigInteger i.e a BigInteger without any +ve or -ve sign
	{
		string s=number;
		int i=0;
		if(s[i]=='+' || s[i]=='-')
			i++;
		string p="";
		for(;i<s.size();i++)
		{
			p=p+s[i];
		}
		BigInteger ans(p);
		return ans;
	}
	BigInteger multiplyBigInteger(BigInteger B) // it returns the product as BigInteger of two BigIntegers
	{
		BigInteger W(number);
		BigInteger X=W.removeTrailingZeros();
		BigInteger Y=B.removeTrailingZeros();
		
		string s1=X.number;
		string s2=Y.number;
		
		int sign1,sign2;
		
		if(s1[0]=='-')
			sign1=0;
		else
			sign1=1;
		
		if(s2[0]=='-')
			sign2=0;
		else
			sign2=1;
		
		X=X.absolute();
		Y=Y.absolute();
		s1=X.number;
		s2=Y.number;
			
		int n1=s1.size()-1;
		int n2=s2.size()-1;
		int i,y,j,k;
		int carry=0;	
		string e="",temp="",intermediateString="",separateFirstString="",separateLastString="";
		BigInteger ans("0");
		int op=0;
		for(i=n2;i>=0;i--)
		{
			temp="";
			intermediateString="";
			separateFirstString="";
			separateLastString="";
			e="";
			int x=s2[i]-'0';
			for(j=n1;j>=0;j--)
			{
				y=s1[j]-'0';
				int p=carry+x*y;
				if(p>=10)
				{
					intermediateString=(p%10)+'0';
					carry=p/10;
					temp=intermediateString+temp;	
				}	
				else
				{
					intermediateString=p+'0';
					temp=intermediateString+temp;
				}
			}
			if(carry!=0)
			{
				e=carry+'0';
				temp=e+temp;
				carry=0;		
			}
			string yu=ans.getBigInteger();
			for(k=0;k<ans.size()-op;k++)
			{
				separateFirstString=separateFirstString+yu[k];
			}
			for(k=ans.size()-op;k<ans.size();k++)
			{
				separateLastString=separateLastString+yu[k];
			}
			BigInteger Q(temp);
			BigInteger W(separateFirstString);
			BigInteger D=Q.addBigInteger(W);
			string t=D.getBigInteger();
			t=t+separateLastString;
			ans.putBigInteger(t);
			op++;
		}
		
		string s=ans.getBigInteger();
		if((sign1==1 && sign2==0)||(sign1==0 && sign2==1))
			s='-'+s;
		ans.putBigInteger(s);
		return ans;
	}
	BigInteger removeTrailingZeros() // it returns the BigInteger in which all the leading zeros are removed
	{
		int i;
		int f=0;
		string p="";
		string x=number;
		for(i=0;i<x.size();i++)
		{
			if(x[i]=='0')
				;
			else
			{
				f=1;
			}
			if(f==1)
			{
				p=p+x[i];
			}
		}
		BigInteger Ans(p);
		return Ans;
	}
	
	char signInChar()		// it returns the sign of BigInteger + for plus and - for minus
	{
		char ans;
		string s=number;
		if(s[0]=='-')
			ans='-';
		else
			ans='+';
		return ans;
	}
	
	int signInInt() 	// it returns the sign of BigInteger 1 for plus and 0 for minus
	{
		int ans;
		string s=number;
		if(s[0]=='-')
			ans=0;
		else
			ans=1;
		return ans;
	}
	
	int lessThan(BigInteger B) // it returns 1 (true) if this < B
	{
		BigInteger A(number);
		int sign1=A.signInInt();
		int sign2=B.signInInt();
		A=A.absolute();
		B=B.absolute();
		BigInteger X=A.removeTrailingZeros();
		BigInteger Y=B.removeTrailingZeros();
		string s1=X.getBigInteger();
		string s2=Y.getBigInteger();
		if(X.size()<Y.size())
			return 1;
		else
		{
			if(X.size()==Y.size())
			{
				int i=0;
				int j=0;
				while(i<s1.size() && j<s2.size())
				{
					if(s1[i]!=s2[j])
					{
						if(s1[i]<s2[j])
							return 1;
						else
							return 0;	
					}	
					i++;
					j++;
				}	
			}
			else
				return 0;
		}
	}
	
	int isEqual(BigInteger B)	// it returns 1 (true) if two BigIntegers are equal else it returns 0 (false)
	{
		BigInteger A(number);
		A=A.removeTrailingZeros();
		B=B.removeTrailingZeros();
		string s1=A.getBigInteger();
		string s2=B.getBigInteger();
		int i=0;
		if(A.size()!=B.size())
			return 0;
		else
		{
			for(i=0;i<s1.size();i++)
			{
				if(s1[i]!=s2[i])
					return 0;
			}
			return 1;
		}
	}
	
	int isZero()	// it returns 1 (true) if BigInteger represents 0 
	{
		BigInteger A(number);
		A=A.absolute();
		string s=A.number;
		int i=0;
		int c=0;
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='0')
				c++;
		}
		if(c==s.size())
			return 1;
		return 0;
	}
	
	BigInteger divideBigInteger(BigInteger B) // it returns the quotient of divison ( this / B )
	{
		BigInteger X(number);
		int i;
		BigInteger divisor("0");
		BigInteger temp("1");
		do
		{
			X=X.subtractBigInteger(B);
			divisor=divisor.addBigInteger(temp);
		}
		while(!X.lessThan(B));
		
		if(X.isEqual(B))
			divisor=divisor.addBigInteger(temp);
			
		return divisor;
	}
	BigInteger modulusBigInteger(BigInteger B) // it returns the modulus of divison ( this / B )
	{
		BigInteger X(number);
		int i;
		BigInteger remainder("0");
		BigInteger temp("1");
		do
		{
			X=X.subtractBigInteger(B);
		}
		while(!X.lessThan(B));
		
		remainder.putBigInteger(X.getBigInteger());
		
		if(X.isEqual(B))
			remainder.putBigInteger("0");
			
		return remainder;
	}
	
	friend BigInteger maxBigInteger(BigInteger A,BigInteger B);
	friend BigInteger minBigInteger(BigInteger A,BigInteger B);
};
	BigInteger maxBigInteger(BigInteger A,BigInteger B) //check ?
	{
		int sign1=A.signInInt();
		int sign2=B.signInInt();
		if(sign1==1 && sign2==1)
		{
			A=A.absolute();
			B=B.absolute();
			
			int f=A.lessThan(B);
			if(f==1)
				return B;
			else
				return A;
		}
		else
		{
			if(sign1==0 && sign2==0)
			{
				BigInteger X=A.absolute();
				BigInteger Y=B.absolute();
				
				int f=X.lessThan(Y);
				if(f==1)
					return A;
				else
					return B;
			}
			else
			{
				if(sign1==1 && sign2==0)
					return A;
				else if(sign1==0 && sign2==1)
					return B;
			}
		}	
	}
	
	BigInteger minBigInteger(BigInteger A,BigInteger B) //check ?
	{
		int sign1=A.signInInt();
		int sign2=B.signInInt();
		if(sign1==1 && sign2==1)
		{
			A=A.absolute();
			B=B.absolute();
			
			int f=A.lessThan(B);
			if(f==1)
				return A;
			else
				return B;
		}
		else
		{
			if(sign1==0 && sign2==0)
			{
				BigInteger X=A.absolute();
				BigInteger Y=B.absolute();
				
				int f=X.lessThan(Y);
				if(f==1)
					return B;
				else
					return A;
			}
			else
			{
				if(sign1==1 && sign2==0)
					return B;
				else if(sign1==0 && sign2==1)
					return A;
			}
		}
	}

int main()
{
	BigInteger B1,B2;
	
	cout<<"Enter Big Integer 1 = ";
	string s1,s2;
	cin>>s1;
	
	B1.putBigInteger(s1);
	cout<<"Enter Big Integer 2 = ";
	cin>>s2;
	B2.putBigInteger(s2);
	/*
	cout<<"Sum of B1 and B2 = ";
	BigInteger B3=B1.addBigInteger(B2);
	cout<<B3.getBigInteger();
	*/
	/*
	cout<<"\nDifference of B1 and B2 = ";
	BigInteger B4=B1.subtractBigInteger(B2);
	cout<<B4.getBigInteger();
	*/
	/*
	cout<<"\nMultiplication of B1 and B2 = ";
	BigInteger B5=B1.multiplyBigInteger(B2);
	cout<<B5.getBigInteger();
	*/
	/*
	cout<<"\nQuotient when B1 is divided by B2 = ";
	BigInteger B6=B1.divideBigInteger(B2);
	cout<<B6.getBigInteger();
	*/
	/*
	cout<<"\nRemainder when B1 is divided by B2 = ";
	B1.copyBigInteger(B2);
	cout<<B1.getBigInteger();
	*/
	BigInteger X=minBigInteger(B1,B2);
	cout<<X.getBigInteger();
	
		
}
