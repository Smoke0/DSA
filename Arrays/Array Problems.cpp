#include <bits/stdc++.h>
using namespace std;

/// gfg verified. pre is used for not printing same element twice and -1 is printed when no
/// element is common
void printCommonElements3Arrays(){
    int t;
	int n1,n2,n3,big,pre=-1;
	cin >> t;

	while(t--){
	    pre=-1;
	    cin >> n1 >> n2 >> n3;
	    int a[n1];
	    int b[n2];
	    int c[n3];

	    for(int i=0;i<n1;i++)
	        cin >> a[i];
        for(int i=0;i<n2;i++)
	        cin >> b[i];
        for(int i=0;i<n3;i++)
	        cin >> c[i];
        bool flag = false;

        for(int i=0,j=0,k=0;i<n1&&j<n2&&k<n3;){

	       if(a[i]==b[j] && b[j]==c[k]){
	           flag = true;
	           if(pre<a[i])
	            cout << a[i] << " ";
	           pre = a[i];
	           i++,j++,k++;
	       }
	       else{
	           big = max(a[i],max(b[j],c[k]));
	           if(a[i] <big)
	            i++;
	            if(b[j]<big)
	            j++;
	            if(c[k] <big)
	            k++;
	       }

	   }
	   if(!flag)
	    cout << -1;
	   cout << "\n";
	}
}


int main() {

	return 0;
}
