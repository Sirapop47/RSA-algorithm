#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

long long int p, q, j, i, flag ;


long long int n, t;
long long int m[100];
long long int e[100], d[100];
long long int temp[100], en[100];


char msg[100];

int prime(long int pr);
void ce();
long long int cd(long long int);
void encrypt();
void decrypt();




int main()
{
	
    cout << "\nENTER FIRST PRIME NUMBER\n";
    cin >> p;
    flag = prime(p);       
    while (flag == 0)
	{
		cout << "\n\n\n\n\nWRONG INPUT\n";
		cout << "\nENTER FIRST PRIME NUMBER\n";
		cin >> p;
		flag = prime(p);
		
	}

    
    cout << "\nENTER ANOTHER PRIME NUMBER\n";
    cin >> q;
    flag = prime(q);
    while (flag == 0 || p == q)
	{
		cout << "\n\n\n\n\nWRONG INPUT\n";
		cout << "\nENTER ANOTHER PRIME NUMBER\n";
		cin >> q;
		flag = prime(q);
		
	}
	
	
	cout << "\nENTER MESSAGE\n";
	cin >> msg;
	int len = strlen(msg);
	for (i = 0; i < len; i++)	{	m[i] = msg[i];	}	

	n = p * q;
    t = (p - 1) * (q - 1);
    
    ce();
	
    
    
    cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    
    for (i = 0; i < j-1; i++) {
    	cout << e[i] << "\t" << d[i] << "\n";
	}
	
	encrypt();
	decrypt();
	return 0;
        
    
}

int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

void ce()
{
    long int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0) {
        	continue;
		}    
        else {
        	flag = prime(i);
		}

        if (flag == 1 && i != p && i != q)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}


long long int cd(long long int x)
{
	
    long long int k;
	for (k = 1; k < t; k++)
	{
		if ((k * x) % t == 1 && k != p && k != q)
		{
			return k;
		}
		else
		{
			continue;
		}
	}
	
}


void encrypt()
{
    long long int pt, ct, key = e[0], k, len;
    len = strlen(msg);
    
    for (i = 0; i < len; i++)
    {
    	pt = m[i];
    	pt = pt - 96;
    	k = 1;
    	
    	for (j = 0; j < key; j++)
    	{
    		k = k * pt;
			k = k % n; 
		}
		temp[i] = k;
		
		
        ct = k + 96;
        en[i] = ct;
        
        
        cout << ct << " ";
        
        
		
		
		//en[i] = k;
		
	}
	

    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
        printf("%c", en[i]);
}




void decrypt()
{
	long long int pt, ct, key = d[0], k, len;
	len = strlen(msg);
	
	for (i = 0; i < len; i++)
	{
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		
		
		pt = k + 96;
        m[i] = pt;
        
        cout << k << " ";
		
		//m[i] = k;
		
	}
	
	
	m[i] = -1;
	cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", m[i]);

	
}

