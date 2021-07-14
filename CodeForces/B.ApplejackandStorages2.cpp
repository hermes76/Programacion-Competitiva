    #include <iostream>
    using namespace std;

    int arr[100002];
    int main()
    {
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        int n;
        cin>>n;
        int a;
        int dos,cuatro,seis,ocho;
        dos=cuatro=seis=ocho=0;
        for(int x =0; x<n; x++)
        {
            cin>>a;
            arr[a]++;
        }
        for(int x =0; x<100000; x++)
        {
            if(arr[x]>=8)ocho++;
            else if(arr[x]>=6)seis++;
            else if(arr[x]>=4)cuatro++;
            else if(arr[x]>=2)dos++;
        }
        int b;
        cin>>b;
        char signo;
        int c;
        int *cambiar,*cambiar2,*cambiar3;
        while(b--)
        {
            cin>>signo;
            cin>>a;
            c=arr[a];
             if(c<4) cambiar=&dos,cambiar2=NULL,cambiar3=&cuatro;
            else if(c<6) cambiar=&cuatro,cambiar2=&dos,cambiar3=&seis;
            else if(c<8)cambiar=&seis,cambiar2=&cuatro,cambiar3=&ocho;
            else cambiar = &ocho,cambiar2=&seis,cambiar3=NULL;
            //cout<<c<<" "<<*cambiar<<" "<<dos<<endl;
            if(signo=='-')arr[a]--;
            else arr[a]++;
                if(c>=2)
                {
                    if(c>arr[a])
                    {
                        if(arr[a]%2==1)
                        {(*cambiar)--;

                            if(cambiar2 !=NULL)(*cambiar2)++;
                        }
                    }else if(c<arr[a]){

                        if(arr[a]%2==0)
                        {(*cambiar)--;
                        if(cambiar3!=NULL) (*cambiar3)++;
                        }
                    }
                }else if(arr[a]>=2)
                {
                    (*cambiar)++;
                }

            //cout<<dos<<" "<<cuatro<<" "<<seis<<" "<<ocho<<endl;
            if((ocho>=1) or (seis>=1 and (cuatro>=1 or dos >=1))or (cuatro>=2) or (cuatro>=1 and dos>=2) or (dos>=4)) cout<<"YES";
            else cout<<"NO";
            cout<<endl;

        }
    }
