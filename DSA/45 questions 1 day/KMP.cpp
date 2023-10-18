// KMP
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;

int *getLPS(string pattern)
{

	int *lps = new int[pattern.length()];
	lps[0] = 0;

	int i = 1;
	int j = 0;

	while (i < pattern.length())
	{

		if (pattern[i] == pattern[j])
		{
			lps[i] = j + 1;
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < pattern.length(); i++)
	{
		cout << lps[i] << " ";
	}

	return lps;
}
//
//
bool KMP(string text, string pattern)
{

	int lenText = text.length();
	int lenPattern = pattern.length();

	int *lps = new int[lenPattern];

	lps = getLPS(pattern);

	int i = 0; // Corresponding to text
	int j = 0; // Corresponding to pattern

	while (j < lenPattern && i < lenText)
	{
		if (pattern[j] == text[i])
		{
			i++;
			j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
	}
	//
	if (j == pattern.length())
	{
		return true;
	}
	return false;
	//
	//
}

int main()
{
	string text, pattern;

	cin >> text >> pattern;

	if (KMP(text, pattern))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}

//
// int* build(string concatenated){
//	int *z = new int[concatenated.length()];
//	z[0] = 0;
//	int l=0;
//	int r =0;
//
//	for(int i=1;i<concatenated.length();i++){
//		if(i > r){
//			l = r = i;
//			while(concatenated[r-l] == concatenated[r] && r < concatenated.length()){
//				r++;
//			}
//			z[i] = r-l;
//			r--;
//		}else{
//			int k = i - l;
//			if(z[k] + i <= r){
//				z[i] = z[k];
//			}else{
//				l = i;
//				while(concatenated[r-l] == concatenated[r]  && r < concatenated.length()){
//					r++;
//				}
//				z[i] = r-l;
//				r--;
//			}
//		}
//	}
//	return z;
//}
//
// bool zAlgo(string text,string pattern){
//
//	string concatenated = pattern + '$' + text;
//
//	int l = concatenated.length();
//	int *z = new int[l];
//
//	z = build(concatenated);
//
//	for(int i=pattern.length()+1;i<l;i++){
//		if(z[i] == pattern.length()){
//			return true;
//		}
//	}
//
//	return false;
//
//}
//
//
// int main(){
//	string text,pattern;
//
//	cin>>text>>pattern;
//
//	if(zAlgo(text,pattern)){
//		cout<<"Yes"<<endl;
//	}else{
//		cout<<"No"<<endl;
//	}
//	return 0;
//}
