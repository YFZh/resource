#include   <iostream> 
#include   <vector> 
using   namespace   std; 
int   main(void) 
{ 
        vector <vector <int>  > array(3); 
        for(int   i=0;i <3;i++) 
            array[i].resize(3);//��������Ĵ�С3X3 
              //��������Ժ�ʹ������һ��ʹ�����vector 
        for(int   i=0;i <3;i++) 
            for(int   j=0;j <3;j++) 
                array[i][j]=(i*j); 
        //��� 
        for(int   i=0;i <3;i++) 
        { 
              for(int   j=0;j <3;j++) 
                  cout <<array[i][j] << "   "; 
              cout <<endl; 
          } 
      cin>>array[2][2]    ;

      vector <int>a1(3);
      a1[0]=9;
      a1[1]=3;
      a1[2]=4;
      
      array.push_back(a1);

      array.resize(6); 
      array[4].resize(3); 
      array[5].resize(3); 
        //������5X3�������� 
        for(int   i=4;i <6;i++) 
              for(int   j=0;j <3;j++) 
                    array[i][j]=(i*j); 
        for(int   i=0;i <6;i++) 
        { 
              for(int   j=0;j <3;j++) 
                    cout <<array[i][j] << "   "; 
            cout <<endl; 
        } 
        int a2[3]={0};
        a2[0]=9;
        a2[1]=3;
        a2[2]=9;
        
        vector<int> myvector(a2 , a2+3);
        
        for(int   i=0;i <3;i++) 
        { 
             
                    cout <<myvector[i] << "   "; 
        } 
        cout <<endl; 

        vector<int> myvector1(3 , 9);
        
        for(int   i=0;i <3;i++) 
        { 
             
                    cout <<myvector1[i] << "   "; 
        } 
        cout <<endl; 
        //cout<<"\r";
        return 0;
}


