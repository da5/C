#include<stdio.h>
#include<stdlib.h>

int _gcd(int a, int b)
{
   while (a != b)
    {
        if (a > b)
        {
            return _gcd(a - b, b);
        }
        else
        {
            return _gcd(a, b - a);
        }
    }
    return a;
}

int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int t, n, q, i, x, l,r;
	int *left_to_right = (int*)malloc(sizeof(int)*100001);
	int *right_to_left = (int*)malloc(sizeof(int)*100001);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &x);
			right_to_left[i] = x;
			left_to_right[i] = x; 
		}
		for(i=2;i<=n;i++)
		{
			// printf("%d %d\n", right_to_left[n-i],right_to_left[n-i+1]);
			left_to_right[i] = gcd(left_to_right[i-1], left_to_right[i]);
			right_to_left[n-i+1] = gcd(right_to_left[n-i+2],right_to_left[n-i+1]);
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l==1||r==n)
			{
				if(l==1)
					printf("%d\n", right_to_left[r+1]);
				else
					printf("%d\n", left_to_right[l-1]);
			}
			else
			{
				printf("%d\n", gcd(left_to_right[l-1], right_to_left[r+1]));
			}
		}

	}
	return 0;
}

